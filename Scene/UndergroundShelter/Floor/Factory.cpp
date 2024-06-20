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
#include "Factory.hpp"
#include "Stats/Shared.hpp"
void Factory::Initialize(){
    Shared::Factory = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Factory scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 150, 0);
    AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/FactoryBackground.jpg", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 0, h - 460, 200, 360, 0.5, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1400, h - 460, 300, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/Test.png", 170, 90, 400, 700, 0, 0));
    if(!Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/UncompleteRocket.png", 650, 490, 400, 300, 0, 0));
    }
    else if(Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/GoodRocket.png", 650, 90, 400, 700, 0, 0));
    }
    else if(!Shared::GoodRocket && Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/BadRocket1.png", 650, 90, 400, 700, 0, 0));
    }
    else if(!Shared::GoodRocket && !Shared::BadRocket1 && Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/BadRocket2.png", 650, 90, 400, 700, 0, 0));
    }
    else if(!Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/BadRocket3.png", 650, 90, 400, 700, 0, 0));
    }
    else if(!Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/BadRocket4.png", 650, 90, 400, 700, 0, 0));
    }
    else if(!Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/BadRocket5.png", 650, 90, 400, 700, 0, 0));
    }
    else if(!Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && Shared::BadRocket6 && !Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/BadRocket6.png", 650, 90, 400, 700, 0, 0));
    }
    else if(!Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && Shared::BadRocket7){
        AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/BadRocket7.png", 650, 90, 400, 700, 0, 0));
    }
    AddNewObject(new Engine::Image("UndergroundShelter/Floor/Factory/CraftingTable.jpg", 1150, 600, 200, 200, 0, 0));
    MC = new Maincharacter("MCRightStop.png", 40, 700, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}
void Factory::Terminate() {
    MC = nullptr; 
    al_destroy_font(BIGFont);
    al_destroy_font(PoetFont);
    IScene::Terminate();
}

void Factory::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if (MC -> Position.x <= 40){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 700, 0, "Press E to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 740, 0, "Go Back");
    }
    if (MC -> Position.x >= 125 && MC -> Position.x <= 510){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 710, 0, "This is broken.");
    }
    if (MC -> Position.x >= 605 && MC -> Position.x <= 990 && !Shared::GoodRocket && !Shared::BadRocket1 && !Shared::BadRocket2 && !Shared::BadRocket3 && !Shared::BadRocket4 && !Shared::BadRocket5 && !Shared::BadRocket6 && !Shared::BadRocket7){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 710, 0, "Uncomplete");
    }
    if (MC -> Position.x >= 605 && MC -> Position.x <= 990 && (Shared::GoodRocket || Shared::BadRocket1|| Shared::BadRocket2 || Shared::BadRocket3 || Shared::BadRocket4 ||Shared::BadRocket5 || Shared::BadRocket6 ||Shared::BadRocket7)){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 500, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 250, 710, 0, "Press E to Enter");
    }
    if (MC -> Position.x >= 1030 && MC -> Position.x <= 1350){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 320, 700, 0, "Press I to Interact");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 320, 740, 0, "Press C to Close");
    }
    if (MC -> Position.x >= 1380 && MC -> Position.x <= 1600){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 320, 710, 0, "Press E to Enter");
    }
}

void Factory::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x <= 150) Engine::GameEngine::GetInstance().ChangeScene("ElevatorFloor");
            if(MC -> Position.x >= 1300) Engine::GameEngine::GetInstance().ChangeScene("Road");
            if (MC -> Position.x >= 605 && MC -> Position.x <= 990 && (Shared::GoodRocket || Shared::BadRocket1|| Shared::BadRocket2 || Shared::BadRocket3 || Shared::BadRocket4 ||Shared::BadRocket5 || Shared::BadRocket6 ||Shared::BadRocket7)){
                if(Shared::GoodRocket){
                    Engine::GameEngine::GetInstance().ChangeScene("Win");
                }
                else if(Shared::BadRocket2 || Shared::BadRocket3 || Shared::BadRocket4 ||Shared::BadRocket5 || Shared::BadRocket6 ||Shared::BadRocket7){
                    Engine::GameEngine::GetInstance().ChangeScene("Lose");
                }
            }
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_ESCAPE:
            Engine::GameEngine::GetInstance().ChangeScene("PauseScene");
            break;
        case ALLEGRO_KEY_I:
            if (MC -> Position.x >= 1030 && MC -> Position.x <= 1350){
                Engine::GameEngine::GetInstance().ChangeScene("CraftingTable");
            }
            break;
        case ALLEGRO_KEY_M:
            Engine::GameEngine::GetInstance().ChangeScene("Map");
            break;
        default:
            break;
    }
}

void Factory::OnKeyUp(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->Stop();
            break;
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
    }
}

void Factory::Update(float deltaTime){
    IScene::Update(deltaTime);
}

