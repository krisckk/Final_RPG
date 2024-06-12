#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
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
bool stickynotes_opened = false;
bool enter_password = false;
bool door_open = false;
char password[5];
int i = 0;
void LibraryScene::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Library scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 150, 0);
    Passwordnote = al_load_bitmap("Resource/images/UndergroundShelter/B4/Library/Passwordnote.png");
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackgroundPlatform.png", 0, h - 520, w, 60, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/ladder.png", 300, h - 540, 160, 460, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/bookshelf.png", 500, 80, 400, 300, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/bookshelf.png", 900, 80, 400, 300, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/bookshelf.png", 1300, 80, 300, 300, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/stickynotes.png", 1000, 180, 50, 50));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/WaterFountain.png", 100, 95, 180, 300, 0, 0));
    bgmInstance = AudioHelper::PlaySample("joannaliaoThemeSong.ogg", true, AudioHelper::BGMVolume);
    AddNewObject(new Engine::Image("2Ddooropened.png", 0, h - 460, 200, 360, 0.5, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/Computer.png", 650, h - 300, 100, 100, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/ComputerDesk.png", 600, h - 200, 200, 100, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/bookshelf.png", 900, h - 400, 300, 300, 0 , 0));
    AddNewObject(new Engine::Image("2Ddoorclosed.png", 1300, h - 460, 300, 360, 0, 0));
    MC = new Maincharacter("MCRightStop.png", 80, 680, 32, 100, 3, 100, 100);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void LibraryScene::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    MC = nullptr; 
    IScene::Terminate();
}

void LibraryScene::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            if (!stickynotes_opened && !enter_password) MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
            if (!stickynotes_opened && !enter_password) MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_W:
            if(!stickynotes_opened && !enter_password && MC -> Position.x >= 280 && MC -> Position.x <= 400 && MC -> Position.y >= 250){
                MC->ClimbUp(1.0f / 60.0f);
            }
            break;
        case ALLEGRO_KEY_S:
            if(!stickynotes_opened && !enter_password && MC -> Position.x >= 280 && MC -> Position.x <= 400 && MC -> Position.y <= 570){
                MC->ClimbDown(1.0f / 60.0f);
            }
            break;
        case ALLEGRO_KEY_E:
            if (MC -> Position.x >= 1350 && MC -> Position.x <= 1600){
                enter_password = !enter_password;
                i = 0;
            }
            break;
        case ALLEGRO_KEY_I:
            if (MC -> Position.x >= 900 && MC -> Position.x <= 1050 && MC -> Position.y < 450){
                stickynotes_opened = !stickynotes_opened;
            }
            if (MC -> Position.x >= 600 && MC -> Position.x <= 750 && MC -> Position.y > 450){
                Engine::GameEngine::GetInstance().ChangeScene("Computer");
            }
            break;
        case ALLEGRO_KEY_1:
        case ALLEGRO_KEY_2:
        case ALLEGRO_KEY_3:
        case ALLEGRO_KEY_4:
        case ALLEGRO_KEY_5:
        case ALLEGRO_KEY_6:
        case ALLEGRO_KEY_7:
        case ALLEGRO_KEY_8:
        case ALLEGRO_KEY_9:
        case ALLEGRO_KEY_0:
        case ALLEGRO_KEY_BACKSPACE:
            if (enter_password){
                if (keyCode == ALLEGRO_KEY_BACKSPACE){
                    if (password[0]!= '\0'){
                        for (int j = 0; j < 4; j++) password[j] = '\0';
                        i = 0;
                    }
                }
                else{
                    Engine::LOG(Engine::INFO) << "Key pressed: " << keyCode - 27;
                    password[i] = *al_keycode_to_name(keyCode);
                    i++;
                }
            }
        default:
            break;
    }
}

void LibraryScene::OnKeyUp(int keyCode){
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
        case ALLEGRO_KEY_S:
            MC->Stop();
            break;
        default:
            break;
    }
}
void LibraryScene::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    //if (door_open) al_draw_scaled_bitmap(dooropened,0, 0, 162, 228, 1400, h - 460, 200, 360, 0);

    if (MC -> Position.x >= 1350 && MC -> Position.x <= 1600 && !enter_password){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press E to Enter");
        if (!door_open) al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 750, 0, "Password");
    }
    if (MC -> Position.x >= 900 && MC -> Position.x <= 1050 && MC -> Position.y < 450 && !stickynotes_opened){
        al_draw_filled_triangle(MC -> Position.x - 55, MC -> Position.y , MC -> Position.x - 55, MC -> Position.y + 40, MC -> Position.x - 10, MC -> Position.y + 20, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, MC -> Position.y - 20, MC -> Position.x - 50, MC -> Position.y + 100, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, MC -> Position.y + 10, 0, "Press I to Interact");
    }
    if (MC -> Position.x >= 600 && MC -> Position.x <= 750 && MC -> Position.y > 450){
        al_draw_filled_triangle(MC -> Position.x - 55, MC -> Position.y , MC -> Position.x - 55, MC -> Position.y + 40, MC -> Position.x - 10, MC -> Position.y + 20, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, MC -> Position.y - 20, MC -> Position.x - 50, MC -> Position.y + 100, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, MC -> Position.y + 10, 0, "Press I to Interact");
    }
    if (stickynotes_opened){
        al_draw_filled_rounded_rectangle(400, 200, 1200, 700, 10, 10, al_map_rgb(255, 255, 102));
        al_draw_scaled_bitmap(Passwordnote, 0, 0, 563, 228, 600, 350, 400, 200, 0);
    }
    if (enter_password && !door_open){
        al_draw_filled_rounded_rectangle(390, 350, 580, 550, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(600, 350, 790, 550, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(810, 350, 1000, 550, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(1020, 350, 1210, 550, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 440, 360, 0, "%c", password[0]);
        al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 650, 360, 0, "%c", password[1]);
        al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 860, 360, 0, "%c", password[2]);
        al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 1070, 360, 0, "%c", password[3]);
    }
}
void LibraryScene::Update(float deltaTime){
    IScene::Update(deltaTime);
    if (password[0] == '5' && password[1] == '3' && password[2] == '4' && password[3] == '0') {
        door_open = true;
        enter_password = false;
        Engine::LOG(Engine::INFO) << "The door is open";
        Engine::GameEngine::GetInstance().ChangeScene("StorageRoom");
    }
}

