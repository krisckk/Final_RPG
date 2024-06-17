#include "PauseScene.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/LOG.hpp"
#include "Engine/Resources.hpp"
#include "Engine/Sprite.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Point.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Stats/Shared.hpp"

void PauseScene::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "PauseScene create";
    pirulenFont = al_load_font("Resource/fonts/pirulen.ttf", 45, 0);
    ObjectFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 80, 0);

    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("button_resume.png", "button_resume_hovered.png", halfW, halfH - 75, 270, 70, 0.5, 0.5);
    btn->SetOnClickCallback(std::bind(&PauseScene::ResumeOnClick, this, 1));
    AddNewControlObject(btn);
    
    btn = new Engine::ImageButton("button_save.png", "button_save_hovered.png", halfW, halfH + 75, 500, 70, 0.5, 0.5);
    btn->SetOnClickCallback(std::bind(&PauseScene::SaveOnClick, this, 1));
    AddNewControlObject(btn);
    //AddNewObject(new Engine::Image("MCidleStop.png", 600, 300, w / 5, h / 3, 0, 0));
    //AddNewObject(new Engine::Image("Li'sfavorite.png", 933, 390, w / 10, h / 10, 0, 0));
    //AddNewObject(new Engine::Image("heart.png", 940, 300, w / 17, h / 12, 0, 0));
    //AddNewObject(new Engine::Image("water.png", 940, 510, w / 20, h / 12, 0, 0));
    //if(Shared::redPotion)
    //    AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/red_water.png", 80, 330, 80, 80, 0, 0));
}

void PauseScene::Draw() const{
    IScene::Draw();
    //al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 800, 350, ALLEGRO_ALIGN_CENTER, "RESUME");
    //al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 800, 550, ALLEGRO_ALIGN_CENTER, "SAVE PROCESS");
    //al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 150, 200, ALLEGRO_ALIGN_CENTER, "Object");
    //al_draw_rectangle(70, 320, 170, 420, al_map_rgb(255, 255, 255), 2);
    //al_draw_rounded_rectangle(1100, 330, 1400, 370, 10, 10, al_map_rgb(255, 255, 255), 2);
    //al_draw_filled_rounded_rectangle(1100, 330, 1100 + Shared::lives * 100, 370, 10, 10, al_map_rgb(255, 255, 255));
}

void PauseScene::Terminate() {
    al_destroy_font(pirulenFont);
    al_destroy_font(ObjectFont);
    IScene::Terminate();
}

void PauseScene::OnKeyDown(int keyCode){
    const std::string StageName = Shared::previosStage;
        switch (keyCode) {
            case ALLEGRO_KEY_C:
                Engine::GameEngine::GetInstance().ChangeScene(StageName);
                break;
            default:
                break;
        }
    
    //if(keyCode == ALLEGRO_KEY_E) Engine::GameEngine::GetInstance().ChangeScene("Library");
}

void PauseScene::SaveOnClick(int stage){
    Engine::GameEngine::GetInstance().ChangeScene("start");
}
void PauseScene::ResumeOnClick(int stage){
    const std::string StageName = Shared::previosStage;
    Engine::GameEngine::GetInstance().ChangeScene(StageName);
    //Engine::GameEngine::GetInstance().ChangeScene("Lab");
}
