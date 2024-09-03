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
#include "ElevatorB1.hpp"
#include "Stats/Shared.hpp"
#include "Office.hpp"
void Office::Initialize(){
    Shared::Office = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "HardwareRoom scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 150, 0);
    safety_box_closed = al_load_bitmap("Resource/images/UndergroundShelter/B1/Office/safety_deposit_box_closed.png");
    safety_box_opened = al_load_bitmap("Resource/images/UndergroundShelter/B1/Office/safety_deposit_box_opened.png");
    card = al_load_bitmap("Resource/images/UndergroundShelter/B1/Office/IDcard.png");
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1550, h - 460, 300, 360, 0.5, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 0, h - 460, 300, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B1/Office/the_scream.png", 500, 200, 240, 300, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B1/Office/OfficeDesk.png", 600, 490, 450, 400, 0, 0));
    //if(!Shared::IDcard) AddNewObject(new Engine::Image("UndergroundShelter/B1/Office/IDcard.png", 1000, 685, 80, 80, 0, 0));
    MC = new Maincharacter("MCRightStop.png", 1450, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}
void Office::Terminate(){
    Engine::LOG(Engine::INFO) << "Office Terminated";
    MC = nullptr; 
    al_destroy_font(PoetFont);
    al_destroy_font(BIGFont);
    IScene::Terminate();
}
void Office::Draw() const {
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if (MC -> Position.x >= 20 && MC -> Position.x <= 150){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press E to ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Enter");
    }
    if (MC -> Position.x >= 1350 && MC -> Position.x <= 1600){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press E to Back");
    }
    if (MC -> Position.x >= 850 && MC -> Position.x <= 1050 && !Shared::IDcard){
        if(!Shared::box_opened) al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        if(!Shared::box_opened) al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        if (!Shared::key) al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 720, 0, "It is closed");
        else if (Shared::key && !Shared::box_opened) 
        {
            al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 700, 0, "Press I to");
            al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 740, 0, "Use Key");
        }   
    }
    if (MC -> Position.x >= 850 && MC -> Position.x <= 1050 && !Shared::IDcard && Shared::box_opened){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press P to ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Get IDcard");
    }

    if (Shared::box_opened) al_draw_scaled_bitmap(safety_box_opened, 0, 0, 238, 181, 880, 575, 143, 108, 0);
    if (!Shared::IDcard) al_draw_scaled_bitmap(card, 0, 0, 512, 512, 960, 625, 35, 35, 0);
    if (!Shared::box_opened) al_draw_scaled_bitmap(safety_box_closed, 0, 0, 156, 181, 930, 575, 94, 108, 0);
}
void Office::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_A:
            MC -> MoveLeft(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_D:
            MC -> MoveRight(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x >= 20 && MC -> Position.x <= 150) Engine::GameEngine::GetInstance().ChangeScene("ElevatorToFloor");
            if(MC -> Position.x >= 1400) Engine::GameEngine::GetInstance().ChangeScene("HardwareRoom");
            break;
        
        case ALLEGRO_KEY_I:
            if(MC -> Position.x >= 850 && MC -> Position.x <= 1050 && Shared::key) 
                Shared::box_opened = true;
            break;
        case ALLEGRO_KEY_P:
            if(MC -> Position.x >= 850 && MC -> Position.x <= 1050 && Shared::box_opened) 
                Shared::IDcard = true;  
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_ESCAPE:
            Engine::GameEngine::GetInstance().ChangeScene("PauseScene");
            break;
        case ALLEGRO_KEY_M:
            Engine::GameEngine::GetInstance().ChangeScene("Map");
            break;
        default:
            break;
    }
}
void Office::OnKeyUp(int keyCode){
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
