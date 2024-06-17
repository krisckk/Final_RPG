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
#include "Monster/Monster.hpp"
#include "Stats/Shared.hpp"
#include "ElevatorB2.hpp"
#include "Scene/UndergroundShelter/B3/ElevatorB3.hpp"
Monster* Enemy;
void ElevatorB2::Initialize(){
    Shared::ElevatorB2 = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "ElevatorB3 scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    FloorFont = al_load_font("Resource/fonts/pirulen.ttf", 20, 0);
    BIGFont = al_load_font("Resource/fonts/Tiny5.ttf", 80, 0);
    GameoverBackground = al_load_bitmap("Resource/images/menu_background.jpg");
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 0, h - 460, 200, 360, 0.5, 0));
    AddNewObject(new Engine::Image("elevator.png", halfW + 30, halfH + 30, 330, 330, 0, 0));
    bgmInstance = AudioHelper::PlaySample("Weightless.ogg", true, AudioHelper::BGMVolume);
    MC = new Maincharacter("MCRightStop.png", halfW + 30, 680, 32, 200);
    if(!Enemy -> isDead){
        Enemy = new Monster("Monster/idle/idle_1.png", 80, 550, 32, 50);
        if (!Enemy) {
            Engine::LOG(Engine::ERROR) << "Failed to create Monster object";
        }
        AddNewObject(Enemy);
    }
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void ElevatorB2::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    al_destroy_font(PoetFont);
    al_destroy_font(FloorFont);
    al_destroy_font(BIGFont);
    al_destroy_bitmap(GameoverBackground);
    MC = nullptr; 
    Enemy = nullptr;
    IScene::Terminate();
}

void ElevatorB2::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_W:
            //MC->ClimbUp(1.0f / 60.0f);
            if (MC -> Position.x >= 850 && MC -> Position.x <= 1000)
                Engine::GameEngine::GetInstance().ChangeScene("ElevatorB1");
            break;
        case ALLEGRO_KEY_S:
            if (MC -> Position.x >= 850 && MC -> Position.x <= 1000)
                Engine::GameEngine::GetInstance().ChangeScene("ElevatorB3");
            //MC->ClimbDown(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_E:
            if (MC -> Position.x <= 5) Engine::GameEngine::GetInstance().ChangeScene("BiologicalLaboratory");
            break;
        case ALLEGRO_KEY_I:
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_ESCAPE:
            Engine::GameEngine::GetInstance().ChangeScene("PauseScene");
            break;
        default:
            break;
    }
}

void ElevatorB2::OnKeyUp(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->Stop();
            break;
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
        case ALLEGRO_KEY_R:
            if(MC -> isDead) Engine::GameEngine::GetInstance().ChangeScene("start");
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
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
void ElevatorB2::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    al_draw_filled_rectangle(w / 2 + 180, h / 2 + 75, w / 2  + 258, h / 2 + 96, al_map_rgb(60, 60, 70));
    al_draw_text(FloorFont, al_map_rgb(255, 255, 255), w / 2 + 200, h / 2 + 73, 0, "B2");
    if (MC -> Position.x <= 5){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press E to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Go Back");
    }

    if (MC -> Position.x >= 850 && MC -> Position.x <= 1000){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 550, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press W to Go To B1");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Press S to Go To B3");
    }
    if(MC -> isDead){
        AudioHelper::StopSample(bgmInstance);
        al_draw_scaled_bitmap(GameoverBackground, 0, 0, 1280, 1280, 0, 0, w, h, 0);
        al_draw_text(BIGFont, al_map_rgb(255, 255, 255), w / 2, h / 2, ALLEGRO_ALIGN_CENTER, "You are dead");
        al_draw_text(BIGFont, al_map_rgb(255, 255, 255), w / 2, h / 2 + 150, ALLEGRO_ALIGN_CENTER, "Press R to restart");
    }
}
void ElevatorB2::Update(float deltaTime){
    IScene::Update(deltaTime);
    
}

