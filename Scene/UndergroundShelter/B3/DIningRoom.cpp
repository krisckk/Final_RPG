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
#include "DiningRoom.hpp"
#include "Stats/Shared.hpp"
void DiningRoom::Initialize(){
    Shared::DiningRoom = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "StorageRoom scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/Tiny5.ttf", 80, 0);
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/DiningRoom/vendingmachine.png", 350, 450, 200, 400, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/DiningRoom/whitewood.png", 700, 550, 500, 250, 0, 0));
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
void DiningRoom::Draw() const {
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
    if (MC -> Position.x >= 270 && MC -> Position.x <= 450 && Shared::coin && !Shared::Achievement_cola){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press I to use coin");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "to get drink");
    }

}
void DiningRoom::Terminate(){
    MC = nullptr; 
    al_destroy_font(PoetFont);
    al_destroy_font(BIGFont);
    IScene::Terminate();
}
void DiningRoom::OnKeyDown(int keyCode){
    switch(keyCode){
        case ALLEGRO_KEY_A:
            MC -> MoveLeft(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_D:
            MC -> MoveRight(1.0f/ 60.0f);
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x >= 20 && MC -> Position.x <= 150) Engine::GameEngine::GetInstance().ChangeScene("GYMscene");
            if(MC -> Position.x >= 1400) Engine::GameEngine::GetInstance().ChangeScene("RestRoom");
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_I:
            if (MC -> Position.x >= 270 && MC -> Position.x <= 450 && Shared::coin) Shared::Achievement_cola = true;
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
void DiningRoom::OnKeyUp(int keyCode){
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