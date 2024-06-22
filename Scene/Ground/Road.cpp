#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

#include <string>
#include <iostream>
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
#include "Road.hpp"
#include "Monster/Monster.hpp"
Monster *Enemy2;
void Road::Initialize(){
    Shared::Road = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Road scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    FloorFont = al_load_font("Resource/fonts/pirulen.ttf", 20, 0);
    AddNewObject(new Engine::Image("Ground/Outside/forest.png", 0, 0, w, h, 0, 0));
    MC = new Maincharacter("MCRightStop.png", 80, 680, 32, 200);
    BIGFont = al_load_font("Resource/fonts/Tiny5.ttf", 80, 0);
    GameoverBackground = al_load_bitmap("Resource/images/menu_background.jpg");
    if(!Enemy2 -> isDead){
        Enemy2 = new Monster("Monster/idle/idle_1.png", w/2, 550, 32, 50);
        if (!Enemy2) {
            Engine::LOG(Engine::ERROR) << "Failed to create Monster object";
        }
        AddNewObject(Enemy2);
    }
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void Road::Terminate() {
    MC = nullptr; 
    Enemy2 = nullptr;
    al_destroy_font(PoetFont);
    al_destroy_font(BIGFont);
    al_destroy_font(FloorFont);
    al_destroy_bitmap(GameoverBackground);
    IScene::Terminate();
}

void Road::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            if(MC -> Position.x <= 0) Engine::GameEngine::GetInstance().ChangeScene("Factory");
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            if(MC -> Position.x >= 1600) Engine::GameEngine::GetInstance().ChangeScene("House");
            break;
        case ALLEGRO_KEY_W:
            if (MC -> Position.x >= 850 && MC -> Position.x <= 1000)
            break;
        case ALLEGRO_KEY_P:
            if(MC -> Position.x >= 380 && MC -> Position.x <= 580) Shared::Iron = true;
            break;
        case ALLEGRO_KEY_E:
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_H:
            Engine::GameEngine::GetInstance().ChangeScene("Home");
            break;
        case ALLEGRO_KEY_M:
            Engine::GameEngine::GetInstance().ChangeScene("Map");
            break;
        default:
            break;
    }
}

void Road::OnKeyUp(int keyCode){
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
void Road::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if(MC -> isDead){
        al_draw_scaled_bitmap(GameoverBackground, 0, 0, 1280, 1280, 0, 0, w, h, 0);
        al_draw_text(BIGFont, al_map_rgb(255, 255, 255), w / 2, h / 2, ALLEGRO_ALIGN_CENTER, "You are dead");
        al_draw_text(BIGFont, al_map_rgb(255, 255, 255), w / 2, h / 2 + 150, ALLEGRO_ALIGN_CENTER, "Press R to restart");
    }
}
void Road::Update(float deltaTime){
    IScene::Update(deltaTime);
    
}

