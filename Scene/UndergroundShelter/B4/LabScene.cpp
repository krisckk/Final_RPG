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
#include "Stats/Shared.hpp"
#include "Maincharacter/Maincharacter.hpp"
#include "LabScene.hpp"
#include "LibraryScene.hpp"
Maincharacter* MC;
void LabScene::Initialize(){
    Shared::LabScene = true;
    // BackGround
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    
    pirulenFont = al_load_font("Resource/fonts/pirulen.ttf", 36, 0);
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    ParasiteFont = al_load_font("Resource/fonts/Parasite.ttf", 20, 0);
    Engine::LOG(Engine::INFO) << "Lab scene create";
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 50, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithoutPeople.png", 300, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 550, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithoutPeople.png", 850, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 1100, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1300, h - 460, 300, 360, 0, 0));
    if(Shared::previousStage == "start") MC = new Maincharacter("MCRightStop.png", 80, 680, 32, 200);
    else if(Shared::previousStage == "Library") MC = new Maincharacter("MCLeftStop.png", 1320, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}
void LabScene::Draw() const{
    IScene::Draw();
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 150, 470, ALLEGRO_ALIGN_CENTER, "Seeds 000");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 400, 470, ALLEGRO_ALIGN_CENTER, "Seeds 001");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 650, 470, ALLEGRO_ALIGN_CENTER, "Seeds 002");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 950, 470, ALLEGRO_ALIGN_CENTER, "Seeds 003");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 1200, 470, ALLEGRO_ALIGN_CENTER, "Seeds 004");
    if (showTextBox) {
        al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 800, 50, ALLEGRO_ALIGN_CENTER, "Chapter 1 : The Recovery");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), 800, 100, ALLEGRO_ALIGN_CENTER, "'God my head hurts, what is this place? ' You woke up and found out you were in an unfamiliar place.");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), 800, 150, ALLEGRO_ALIGN_CENTER, "'Wait…who am I? I can’t remember anything.'");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), 800, 200, ALLEGRO_ALIGN_CENTER, "You look around this room. There are a few cabins around you,");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), 800, 250, ALLEGRO_ALIGN_CENTER, " one of which is broken with a sign saying 'seeds 001'.");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), 800, 300, ALLEGRO_ALIGN_CENTER, "You stand up and try to explore a bit…");
    }
    if (MC -> Position.x >= 1200 && MC -> Position.x <= 1600){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press E to Enter");
    }
}
void LabScene::Terminate() {
    MC = nullptr; 
    al_destroy_font(pirulenFont);
    al_destroy_font(PoetFont);
    al_destroy_font(ParasiteFont);
    IScene::Terminate();
}
void LabScene::OnKeyDown(int keyCode){
    if(!showTextBox){
        switch (keyCode) {
            case ALLEGRO_KEY_A:
                MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
                break;
            case ALLEGRO_KEY_D:
                MC->MoveRight(1.0f / 60.0f);
                break;
            case ALLEGRO_KEY_E:
                if (MC -> Position.x >= 1200 && MC -> Position.x <= 1600)   Engine::GameEngine::GetInstance().ChangeScene("Library");
                break;
            case ALLEGRO_KEY_B:
                Engine::GameEngine::GetInstance().ChangeScene("Backpack");
                break;
            case ALLEGRO_KEY_Q:
                Engine::GameEngine::GetInstance().ChangeScene("GYMscene");
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
}
void LabScene::OnKeyUp(int keyCode){
    if(!showTextBox){
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
            default:
                break;
        }
    }
    
}
void LabScene::UpdateTextBox(float deltaTime) {
    textBoxTimer += deltaTime;
    if (textBoxTimer >= 2.0f) {
        showTextBox = false;
    }
}
void LabScene::Update(float deltaTime) {
    Draw();
    IScene::Update(deltaTime);
    UpdateTextBox(deltaTime);
}
