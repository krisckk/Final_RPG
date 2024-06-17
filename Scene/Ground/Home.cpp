#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <memory>
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
#include "Home.hpp"

bool letter_opened = false;
void Home::Initialize(){
    Shared::Home = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Home scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    FloorFont = al_load_font("Resource/fonts/pirulen.ttf", 20, 0);
    AddNewObject(new Engine::Image("Ground/Home/livingroom.jpg", 0, 0, w, h, 0, 0));
    Letter = al_load_bitmap("Resource/images/Ground/Home/letter.png");
    MC = new Maincharacter("MCRightStop.png", 80, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void Home::Terminate() {
    al_destroy_font(PoetFont);
    al_destroy_font(FloorFont);
    al_destroy_bitmap(Letter);
    MC = nullptr; 
    IScene::Terminate();
}

void Home::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
        if (!letter_opened)
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
        if (!letter_opened)
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_C:
            if (MC -> Position.x >= 850 && MC -> Position.x <= 1000 && letter_opened){
                letter_opened = false;
            }
            break;
        case ALLEGRO_KEY_W:
            if (MC -> Position.x >= 850 && MC -> Position.x <= 1000)
            break;
        case ALLEGRO_KEY_I:
            //Engine::LOG(Engine::INFO) << "open";
            if (MC -> Position.x >= 850 && MC -> Position.x <= 1000 && !letter_opened){
                letter_opened = true;
            }
            break;
        case ALLEGRO_KEY_E:
            if (MC -> Position.x <= 5) Engine::GameEngine::GetInstance().ChangeScene("House");
            break;
        case ALLEGRO_KEY_B:
            Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            break;
        case ALLEGRO_KEY_R:
            Engine::GameEngine::GetInstance().ChangeScene("Road");
            break;
        default:
            break;
    }
}

void Home::OnKeyUp(int keyCode){
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
void Home::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if (MC -> Position.x <= 5){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press E to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Go Back");
    }

    if (MC -> Position.x >= 850 && MC -> Position.x <= 1000 && !letter_opened){
        al_draw_filled_triangle(MC -> Position.x + 200, 700, MC -> Position.x + 200, 740, MC -> Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x + 200, 680, MC -> Position.x + 510, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 700, 0, "Press I to interact");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x + 230, 740, 0, "Press C to close");
    }
    if (letter_opened){
        al_draw_scaled_bitmap(Letter, 0, 0, 1200, 1200, 100, 5, 860, 940, 0);
    }
}
void Home::Update(float deltaTime){
    IScene::Update(deltaTime);
    
}

