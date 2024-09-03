#include "PauseScene.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
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
}

void PauseScene::Draw() const{
    IScene::Draw();
}

void PauseScene::Terminate() {
    al_destroy_font(pirulenFont);
    al_destroy_font(ObjectFont);
    IScene::Terminate();
}

void PauseScene::OnKeyDown(int keyCode){
    const std::string StageName = Shared::previousStage;
        switch (keyCode) {
            case ALLEGRO_KEY_C:
                Engine::GameEngine::GetInstance().ChangeScene(StageName);
                break;
            default:
                break;
        }
}

void PauseScene::SaveOnClick(int stage){
    Engine::LOG(Engine::INFO) << "SaveOnClick";
    std::ofstream saveFile("../Maincharacter/SaveData.txt", std::ios::trunc);// , std::ios::app
    if (saveFile.is_open()) {
        saveFile << Shared::previousStage << " "<< Shared::lives << " " << Shared::redPotion << " " << Shared::bluePotion << " " << Shared::yellowPotion
        << " " << Shared::Gold << " " << Shared::Aluminum << " " << Shared::Iron << " " << Shared::HDLoil << " " << Shared::LDLoil << " " << Shared::IDcard << " " 
        << Shared::coin << " " << Shared::wooden_stick << " " << Shared::Achievement_cola << " " << Shared::Achievement_home << " " << Shared::Achievement_myfavorite << " "
        << Shared::LabScene << " " << Shared::LibraryScene << " " << Shared::StorageRoom << " " << Shared::ElevatorB4 << " " 
        << Shared::ElevatorB3 << " " << Shared::RestRoom << " " << Shared::DiningRoom << " " << Shared::GYMscene << " " << Shared::DataRoom << " " << Shared::ElevatorB2 << " " 
        << Shared::BiologicalLaboratory << " " << Shared::ElevatorB1 << " " << Shared::HardwareRoom << " " << Shared::Office << " " << Shared::ElevatorToFloor << " "
        << Shared::ElevatorFloor << " " << Shared::Factory << " " << Shared::Road << " " << Shared::House << " " << Shared::Home << std::endl;
    }
    else {
        Engine::LOG(Engine::ERROR) << "FILE unable to open.";
    }
    saveFile.close();
    Engine::GameEngine::GetInstance().ChangeScene("start");
}
void PauseScene::ResumeOnClick(int stage){
    const std::string StageName = Shared::previousStage;
    Engine::GameEngine::GetInstance().ChangeScene(StageName);
}
