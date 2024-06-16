#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
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
#include "Maincharacter/Backpack.hpp" 
#include "Stats/Shared.hpp"
#include "ElevatorToFloor.hpp"
#include "Scene/UndergroundShelter/B3/ElevatorB3.hpp"
void ElevatorToFloor::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "ElevatorB3 scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    FloorFont = al_load_font("Resource/fonts/pirulen.ttf", 20, 0);
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1550, h - 460, 300, 360, 0.5, 0));
    AddNewObject(new Engine::Image("elevator.png", halfW - 170, halfH + 30, 330, 330, 0, 0));
    bgmInstance = AudioHelper::PlaySample("joannaliaoThemeSong.ogg", true, AudioHelper::BGMVolume);
    MC = new Maincharacter("MCRightStop.png", halfW + 30, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void ElevatorToFloor::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    MC = nullptr; 
    IScene::Terminate();
}

void ElevatorToFloor::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_W:
            if (MC -> Position.x >= 850 && MC -> Position.x <= 1000 && Shared::IDcard)
                Engine::GameEngine::GetInstance().ChangeScene("ElevatorB1");
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x >= 1400) Engine::GameEngine::GetInstance().ChangeScene("Office");
            break;
        case ALLEGRO_KEY_I:
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        default:
            break;
    }
}

void ElevatorToFloor::OnKeyUp(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->Stop();
            break;
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        default:
            break;
    }
}
void ElevatorToFloor::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    al_draw_filled_rectangle(w / 2 + 180, h / 2 + 75, w / 2  + 258, h / 2 + 96, al_map_rgb(60, 60, 70));
    al_draw_text(FloorFont, al_map_rgb(255, 255, 255), w / 2 + 200, h / 2 + 73, 0, "B1");
    if (MC -> Position.x >= 650 && MC -> Position.x <= 800 && Shared::IDcard){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 550, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press W to Go To Floor");
    }
    else if(MC -> Position.x >= 650 && MC -> Position.x <= 800 && !Shared::IDcard){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 550, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "GO back and get the");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Fucking ID Card");
    }
}
void ElevatorToFloor::Update(float deltaTime){
    IScene::Update(deltaTime);
}

