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
#include "UI/Animation/DirtyEffect.hpp"
#include "UI/Animation/Plane.hpp"
#include "Maincharacter/Maincharacter.hpp"
#include "Scene/UndergroundShelter/B4/LibraryScene.hpp"
#include "Scene/UndergroundShelter/B4/LabScene.hpp"
#include "Scene/UndergroundShelter/B4/StorageRoom.hpp"
#include "RestRoom.hpp"
#include "Stats/Shared.hpp"
#include "Monster/Monster.hpp"
static ALLEGRO_BITMAP* bulletin_board = NULL;
bool bulletin_board_open = false;

void RestRoom::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "StorageRoom scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 150, 0);
    bulletin_board = al_load_bitmap("Resource/images/UndergroundShelter/B3/RestRoom/bulletin_board_NEW.png");
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/RestRoom/bulletin_board.png", 400, 450, 400, 370, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/RestRoom/newsofa.png", 900, 620, 400, 200, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/RestRoom/TV.jpg", 1150, 400, 150, 200, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/RestRoom/monalisa.png", 1155, 405, 140, 190, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1550, h - 460, 300, 360, 0.5, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 0, h - 460, 300, 360, 0, 0));
    MC = new Maincharacter("MCRightStop.png", 1450, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void RestRoom::Terminate(){
    MC = nullptr; 
    al_destroy_font(PoetFont);
    al_destroy_font(BIGFont);
    IScene::Terminate();
}

void RestRoom::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if (MC -> Position.x >= 20 && MC -> Position.x <= 150){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press E to ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Enter");
    }
    if(MC -> Position.x >= 1400){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press E to ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Back");
    }
    if (MC -> Position.x >= 350 && MC -> Position.x <= 650 && !bulletin_board_open){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 550, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press I to Interact");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 730, 0, "Press C to close");
    }
    if (bulletin_board_open){
        al_draw_filled_rectangle(340, 140, 1310, 760, al_map_rgb(255, 255, 255));
        al_draw_scaled_bitmap(bulletin_board,0, 0, 1471, 809, 350, 150, 950, 600, 0);
    }
}

void RestRoom::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_A:
            if (!MC -> isDead && !bulletin_board_open) MC -> MoveLeft(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_D:
            if (!MC -> isDead && !bulletin_board_open) MC -> MoveRight(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_I:
            if (MC -> Position.x >= 350 && MC -> Position.x <= 650)
                bulletin_board_open = true;
            break;
        case ALLEGRO_KEY_C:
            bulletin_board_open = false;
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x >= 20 && MC -> Position.x <= 150) Engine::GameEngine::GetInstance().ChangeScene("DiningRoom");
            if(MC -> Position.x >= 1400) Engine::GameEngine::GetInstance().ChangeScene("ElevatorB3");
            break;
        default:
            break;
    }
}
void RestRoom::OnKeyUp(int keyCode){
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
