#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <memory>
#include <chrono>
#include <ctime>
#include <iomanip>


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
#include "LabScene.hpp"
Maincharacter* MC;
void LabScene::Initialize(){
    // BackGround
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Lab scene create";
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    bgmInstance = AudioHelper::PlaySample("joannaliaoThemeSong.ogg", true, AudioHelper::BGMVolume);
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 50, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithoutPeople.png", 300, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 550, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithoutPeople.png", 850, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B4/LabScene/tankwithPeople.png", 1100, h - 450, 200, 360, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.jpg", 1400, h - 450, 200, 360, 0, 0));
    MC = new Maincharacter("MCRightStop.png", 80, 680, 32, 100, 500, 3, 100, 100);
    if (!MC) {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}
void LabScene::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    delete MC; // Delete the dynamically allocated Maincharacter object
    MC = nullptr; 
    IScene::Terminate();
}
void LabScene::OnKeyDown(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
            break;
        case ALLEGRO_KEY_D:
            MC->MoveRight(1.0f / 60.0f);
            break;
        case ALLEGRO_KEY_SPACE:
            MC->Jump();
            break;
    }
}
void LabScene::OnKeyUp(int keyCode){
    switch (keyCode) {
        case ALLEGRO_KEY_A:
            MC->Stop();
            break;
        case ALLEGRO_KEY_D:
            MC->Stop();
            break;
    }
}