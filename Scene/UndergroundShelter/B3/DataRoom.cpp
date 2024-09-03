#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/LOG.hpp"
#include "Engine/Resources.hpp"
#include "Engine/Sprite.hpp"
#include "UI/Component/Label.hpp"
#include "Maincharacter/Maincharacter.hpp"
#include "Scene/UndergroundShelter/B4/LibraryScene.hpp"
#include "Scene/UndergroundShelter/B4/LabScene.hpp"
#include "Scene/UndergroundShelter/B4/StorageRoom.hpp"
#include "DataRoom.hpp"
#include "Stats/Shared.hpp"
#include "Monster/Monster.hpp"

void DataRoom::Initialize(){
    Shared::DataRoom = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    first = false;
    second = false;
    third = false;
    fourth = false;
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    firstData = al_load_bitmap("Resource/images/UndergroundShelter/B3/DataRoom/dataone.png");
    Background = al_load_bitmap("Resource/images/UndergroundShelter/B3/DataRoom/DataBackground.jpg");
    secondData = al_load_bitmap("Resource/images/UndergroundShelter/B3/DataRoom/datatwo.png");
    thirdData = al_load_bitmap("Resource/images/UndergroundShelter/B3/DataRoom/datathree.png");
    fourthData = al_load_bitmap("Resource/images/UndergroundShelter/B3/DataRoom/datafour.png");
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1550, h - 460, 300, 360, 0.5, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/DataRoom/NewBookShelf.png", 900, h - 410, 400, 350, 0 , 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/DataRoom/NewBookShelf.png", 600, h - 410, 400, 350, 0 , 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/DataRoom/NewBookShelf.png", 300, h - 410, 400, 350, 0 , 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/DataRoom/NewBookShelf.png", 0, h - 410, 400, 350, 0 , 0));
    MC = new Maincharacter("MCRightStop.png", 1450, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
    Engine::LOG(Engine::INFO) << "DataRoom scene create";
}
void DataRoom::Terminate(){
    Engine::LOG(Engine::INFO) << "DataRoom scene terminated";
    al_destroy_font(PoetFont);
    al_destroy_bitmap(Background);
    al_destroy_bitmap(firstData);
    al_destroy_bitmap(secondData);
    al_destroy_bitmap(thirdData);
    al_destroy_bitmap(fourthData);
    MC = nullptr;
    IScene::Terminate();
}

void DataRoom::Draw() const {
    IScene::Draw();
    if (MC -> Position.x >= 1350 && MC -> Position.x <= 1600){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press E to Back");
    }
    if(MC -> Position.x >= 10 && MC -> Position.x <= 250){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 780, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press I to interact. ");
    }
    if(MC -> Position.x >= 310 && MC -> Position.x <= 550){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 780, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press I to interact. ");
    }
    if(MC -> Position.x >= 610 && MC -> Position.x <= 850){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 780, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press I to interact");
    }
    if(MC -> Position.x >= 910 && MC -> Position.x <= 1150){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 780, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press I to interact");
    }
    if(first || second || third || fourth){
        if(first) al_draw_scaled_bitmap(firstData, 0, 0, 1009, 600, 0, 0, 1600, 900, 0);
        if(second) al_draw_scaled_bitmap(secondData, 0, 0, 1009, 600, 0, 0, 1600, 900, 0);
        if(third) al_draw_scaled_bitmap(thirdData, 0, 0, 1009, 600, 0, 0, 1600, 900, 0);
        if(fourth) al_draw_scaled_bitmap(fourthData, 0, 0, 729, 494, 0, 0, 1600, 900, 0);
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), 800, 820, ALLEGRO_ALIGN_CENTER, "Press C to close");
    }
}

void DataRoom::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_A:
            MC -> MoveLeft(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_D:
            MC -> MoveRight(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x >= 1400) Engine::GameEngine::GetInstance().ChangeScene("GYMscene");
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_ESCAPE:
            Engine::GameEngine::GetInstance().ChangeScene("PauseScene");
            break;
        case ALLEGRO_KEY_I:
            if(MC -> Position.x >= 10 && MC -> Position.x <= 250){
                first = true;
                second = false;
                third = false;
                fourth = false;
            }
            if(MC -> Position.x >= 310 && MC -> Position.x <= 550){
                second = true;
                first = false;
                third = false;
                fourth = false;
            }
            if(MC -> Position.x >= 610 && MC -> Position.x <= 850){
                third = true;
                first = false;
                second = false;
                fourth = false;
            }
            if(MC -> Position.x >= 910 && MC -> Position.x <= 1150){
                fourth = true;
                first = false;
                second = false;
                third = false;
            }
            break;
        case ALLEGRO_KEY_C:
            if(first) first = false;
            if(second) second = false;
            if(third) third = false;
            if(fourth) fourth = false;
            break;
        case ALLEGRO_KEY_M:
            Engine::GameEngine::GetInstance().ChangeScene("Map");
            break;
        default:
            break;
    }
}

void DataRoom::OnKeyUp(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->Stop();
            break;
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
        default:
            break;
    }
}
