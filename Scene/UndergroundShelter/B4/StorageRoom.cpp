#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/LOG.hpp"
#include "Engine/Resources.hpp"
#include "Engine/Sprite.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Animation/DirtyEffect.hpp"
#include "UI/Animation/Plane.hpp"
#include "Maincharacter/Maincharacter.hpp"
#include "LibraryScene.hpp"
#include "LabScene.hpp"
#include "StorageRoom.hpp"
#include "ElevatorB4.hpp"
#include "Stats/Shared.hpp"
bool StorageRoom::Red_potion = false;
bool StorageRoom::Blue_potion = false;
bool StorageRoom::Yellow_potion = false;

void StorageRoom::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "StorageRoom scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 150, 0);
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackgroundPlatform.png", 0, h - 520, w, 60, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/ladder.png", 490, h - 540, 160, 460, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 0, h - 460, 200, 360, 0.5, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1300, h - 460, 300, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/shelf.png", 320, h - 300, 300, 200, 0.5, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/shelf.png", 810, h - 300, 300, 200, 0.5, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/shelf.png", 1130, h - 300, 300, 200, 0.5, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/shelf.png", 320, halfH - 270, 300, 200, 0.5, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/shelf.png", 810, halfH - 270, 300, 200, 0.5, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/shelf.png", 1130, halfH - 270, 300, 200, 0.5, 0));
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/red_water.png", 250 + i * 70, h - 315 + j * 51, 60, 40, 0.5, 0));
            AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/blue_water.png", 740 + i * 70, h - 315 + j * 51, 60, 40, 0.5, 0));
            AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/yellow_water.png", 1060 + i * 70, h - 315 + j * 51, 60, 40, 0.5, 0));
        }
    }
    MC = new Maincharacter("MCRightStop.png", 80, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void StorageRoom::Terminate() {
    MC = nullptr; 
    IScene::Terminate();
}

void StorageRoom::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    //if (door_open) al_draw_scaled_bitmap(dooropened,0, 0, 162, 228, 1400, h - 460, 200, 360, 0);

    if (MC -> Position.x <= 5){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 700, 0, "Press E to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 740, 0, "Go Back");
    }
    if (MC -> Position.x >= 150 && MC -> Position.x <= 340){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 700, 0, "Press E to Get");
        al_draw_text(PoetFont, al_map_rgb(200, 0, 0), MC -> Position.x + 250, 740, 0, "Red Potion");
        Red_potion = true;
        Blue_potion = false;
        Yellow_potion = false;
    }
    else if (MC -> Position.x >= 640 && MC -> Position.x <= 830){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 700, 0, "Press E to Get");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 200), MC -> Position.x - 310, 740, 0, "Blue Potion");
        Red_potion = false;
        Blue_potion = true;
        Yellow_potion = false;
    }
    else if (MC -> Position.x >= 960 && MC -> Position.x <= 1150){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 700, 0, "Press E to Get");
        al_draw_text(PoetFont, al_map_rgb(200, 200, 0), MC -> Position.x - 310, 740, 0, "Yellow Potion");
        Red_potion = false;
        Blue_potion = false;
        Yellow_potion = true;
    }
    else {
        Red_potion = false;
        Blue_potion = false;
        Yellow_potion = false;
    }
    if (MC -> Position.x >= 1280 && MC -> Position.x <= 1500){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press E to Enter");
    }

}

void StorageRoom::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_E:
            if (MC -> Position.x <= 5) Engine::GameEngine::GetInstance().ChangeScene("Library");
            if (MC -> Position.x >= 1280 && MC -> Position.x <= 1500) Engine::GameEngine::GetInstance().ChangeScene("ElevatorB4");
            if(Red_potion) Shared::redPotion = true;
            if(Blue_potion) Shared::bluePotion = true;
            if(Yellow_potion) Shared::yellowPotion = true;
            break;
        case ALLEGRO_KEY_B:
                Engine::GameEngine::GetInstance().ChangeScene("Backpack");
                break;
        default:
            break;
    }
}

void StorageRoom::OnKeyUp(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->Stop();
            break;
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
        case ALLEGRO_KEY_W:
            MC->Stop();
            break;
    }
}

void StorageRoom::Update(float deltaTime){
    IScene::Update(deltaTime);
    
}

