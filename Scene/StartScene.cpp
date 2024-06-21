#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Scene/StartScene.hpp"
#include "Scene/UndergroundShelter/B4/LabScene.hpp"
#include "Stats/Shared.hpp"
void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("menu_background.jpg", halfW, halfH - 150, 0, 0, 0.5, 0.5));
    AddNewObject(new Engine::Label("THE LOST", "pirulen.ttf", 48, halfW / 2 - 260, halfH / 2 + 20 , 255, 255, 255, 255, 0, 0.5));
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("lose/newgame_unhover.png", "lose/newgame_hovered.png", halfW / 2 - 250, halfH / 2 + 130, 290, 30, 0, 0);
    btn->SetOnClickCallback(std::bind(&StartScene::NewgameOnClick, this, 1));
    AddNewControlObject(btn);

    btn = new Engine::ImageButton("lose/continue_unhover.png", "lose/continue_hovered.png", halfW / 2 - 250, halfH / 2 + 170, 290, 30, 0, 0);
    btn->SetOnClickCallback(std::bind(&StartScene::ContinueOnClick, this, 1));
    AddNewControlObject(btn);

    btn = new Engine::ImageButton("lose/scoreboard_unhover.png", "lose/scoreboard_hovered.png", halfW / 2 - 250, halfH / 2 + 210, 290, 30, 0, 0);
    btn->SetOnClickCallback(std::bind(&StartScene::SettingsOnClick, this, 1));
    AddNewControlObject(btn);

    btn = new Engine::ImageButton("lose/settings_unhover.png", "lose/settings_hovered.png", halfW / 2 - 250, halfH / 2 + 250, 290, 30, 0, 0);
    btn->SetOnClickCallback(std::bind(&StartScene::SettingsOnClick, this, 1));
    AddNewControlObject(btn);
    bgmInstance = AudioHelper::PlaySample("Time.ogg", true, AudioHelper::BGMVolume);
}

void StartScene::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    IScene::Terminate();
}

void StartScene::ContinueOnClick(int stage){
    std::ifstream saveFile("../Maincharacter/SaveData.txt");
    if (saveFile.is_open()) {
        std::string sceneName;
        saveFile >> sceneName;
        Shared::currentStage = sceneName;

        saveFile >> Shared::redPotion;
        saveFile >> Shared::bluePotion;
        saveFile >> Shared::yellowPotion;
        saveFile >> Shared::Gold;
        saveFile >> Shared::Aluminum;
        saveFile >> Shared::Iron;
        saveFile >> Shared::HDLoil;
        saveFile >> Shared::LDLoil;
        saveFile >> Shared::IDcard;

        saveFile.close();
        Engine::GameEngine::GetInstance().ChangeScene(sceneName);
    }
}
void StartScene::SettingsOnClick(int stage){
    Engine::GameEngine::GetInstance().ChangeScene("menuSettings");
}
void StartScene::NewgameOnClick(int stage){
    Shared::redPotion = false;
    Shared::bluePotion = false;
    Shared::yellowPotion = false;
    Shared::Gold = false;
    Shared::Aluminum = false;
    Shared::Iron = false;
    Shared::HDLoil = false;
    Shared::LDLoil = false;
    Shared::IDcard = false;
    Shared::correct = false;

    Engine::GameEngine::GetInstance().ChangeScene("Lab");
}
