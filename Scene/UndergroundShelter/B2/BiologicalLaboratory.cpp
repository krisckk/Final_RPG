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
#include "Stats/Shared.hpp"
#include "BiologicalLaboratory.hpp"

void BiologicalLaboratory::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "BiologicalLaboratory scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 150, 0);
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackgroundPlatform.png", 0, h - 520, w, 60, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Library/ladder.png", 300, h - 540, 160, 460, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 1300, h - 460, 300, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithoutPeople.png", 50, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 550, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 850, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 1100, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 50, 30, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 550, 30, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B2/BiologicalLaboratory/Desk.png", 1000, 210, 400, 200, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B2/BiologicalLaboratory/ExperimentTool.png", 1100, 150, 200, 120, 0, 0));
    if(!Shared::Aluminum) AddNewObject(new Engine::Image("Aluminum.png", 1500, 330, 80, 60, 0, 0));
    MC = new Maincharacter("MCRightStop.png", 1450, 680, 32, 200);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}
void BiologicalLaboratory::Terminate() {
    Engine::LOG(Engine::INFO) << "BiologicalLaboratory scene terminated";
    al_destroy_font(PoetFont);
    al_destroy_font(BIGFont);
    IScene::Terminate();
}
void BiologicalLaboratory::Update(float deltaTime){
    IScene::Update(deltaTime);
}

void BiologicalLaboratory::Draw() const {
    IScene::Draw();
    if (MC -> Position.x >= 1250 && MC -> Position.x <= 1600 && MC -> Position.y > 450){
        al_draw_filled_triangle(MC -> Position.x - 55, 700, MC -> Position.x - 55, 740, MC -> Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 680, MC -> Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 710, 0, "Press E to Enter");
    }
    if(MC -> Position.y < 450 && MC -> Position.x >= 1380 && !Shared::Aluminum){
        al_draw_filled_triangle(MC -> Position.x - 55, 250, MC -> Position.x - 55, 290, MC -> Position.x - 10, 270, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC -> Position.x - 350, 230, MC -> Position.x - 50, 350, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 250, 0, "Press P to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC -> Position.x - 310, 290, 0, "Pick Up");
    }
}
void BiologicalLaboratory::OnKeyDown(int keyCode){
    switch (keyCode)
    {   
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_W:
            if(MC -> Position.x >= 280 && MC -> Position.x <= 400 && MC -> Position.y >= 250){
                MC->ClimbUp(1.0f / 60.0f);
            }
            break;
        case ALLEGRO_KEY_S:
            if(MC -> Position.x >= 280 && MC -> Position.x <= 400 && MC -> Position.y <= 570){
                MC->ClimbDown(1.0f / 60.0f);
            }
            break;
        case ALLEGRO_KEY_P:
            if(MC -> Position.y < 450 && MC -> Position.x >= 1380){
                Shared::Aluminum = true;
            }
            break;
        case ALLEGRO_KEY_E:
            if(MC -> Position.x >= 1250 && MC -> Position.x <= 1600 && MC -> Position.y > 450){
                Engine::GameEngine::GetInstance().ChangeScene("ElevatorB2");
            }
            break;
    }
}

void BiologicalLaboratory::OnKeyUp(int keyCode){
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