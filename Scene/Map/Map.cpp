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
#include "Map.hpp"

void Map::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Map create";
    pirulenFont = al_load_font("Resource/fonts/pirulen.ttf", 45, 0);
    ObjectFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 80, 0);
    if(Shared::LabScene) AddNewObject(new Engine::Image("Map/LabScene.png", 400, 600, 200, 100, 0, 0));
    if(Shared::LibraryScene) AddNewObject(new Engine::Image("Map/LibraryScene.png", 600, 600, 200, 100, 0, 0));
    if(Shared::StorageRoom) AddNewObject(new Engine::Image("Map/StorageRoom.png", 800, 600, 200, 100, 0, 0));
    if(Shared::ElevatorB4) AddNewObject(new Engine::Image("Map/ElevatorB4.png", 1000, 600, 200, 100, 0, 0));
    if(Shared::DataRoom) AddNewObject(new Engine::Image("Map/DataRoom.png", 200, 500, 200, 100, 0, 0));
    if(Shared::GYMscene) AddNewObject(new Engine::Image("Map/GYMscene.png", 400, 500, 200, 100, 0, 0));
    if(Shared::DiningRoom) AddNewObject(new Engine::Image("Map/DiningRoom.png", 600, 500, 200, 100, 0, 0));
    if(Shared::RestRoom) AddNewObject(new Engine::Image("Map/RestRoom.png", 800, 500, 200, 100, 0, 0));
    if(Shared::ElevatorB3) AddNewObject(new Engine::Image("Map/ElevatorB3.png", 1000, 500, 200, 100, 0, 0));
    if(Shared::BiologicalLaboratory) AddNewObject(new Engine::Image("Map/BiologicalLaboratory.png", 800, 400, 200, 100, 0, 0));
    if(Shared::ElevatorB2) AddNewObject(new Engine::Image("Map/ElevatorB2.png", 1000, 400, 200, 100, 0, 0));
    if(Shared::ElevatorToFloor) AddNewObject(new Engine::Image("Map/ElevatorToFloor.png", 400, 300, 200, 100, 0, 0));
    if(Shared::Office) AddNewObject(new Engine::Image("Map/Office.png", 600, 300, 200, 100, 0, 0));
    if(Shared::HardwareRoom) AddNewObject(new Engine::Image("Map/HardwareRoom.png", 800, 300, 200, 100, 0, 0));
    if(Shared::ElevatorB1) AddNewObject(new Engine::Image("Map/ElevatorB1.png", 1000, 300, 200, 100, 0, 0));
    if(Shared::ElevatorFloor) AddNewObject(new Engine::Image("Map/ELevatorFloor.png", 400, 200, 200, 100, 0, 0));
    if(Shared::Factory) AddNewObject(new Engine::Image("Map/Factory.png", 600, 200, 200, 100, 0, 0));
    if(Shared::Road) AddNewObject(new Engine::Image("Map/Road.png", 800, 200, 200, 100, 0, 0));
    if(Shared::House) AddNewObject(new Engine::Image("Map/House.png", 1000, 200, 200, 100, 0, 0));
    if(Shared::Home) AddNewObject(new Engine::Image("Map/Home.png", 1200, 200, 200, 100, 0, 0));
}

void Map::Draw() const{
    IScene::Draw();
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 800, 840, ALLEGRO_ALIGN_CENTER, "Press C to close.");
}

void Map::Terminate() {
    al_destroy_font(pirulenFont);
    al_destroy_font(ObjectFont);
    IScene::Terminate();
}

void Map::OnKeyDown(int keyCode){
    const std::string StageName = Shared::previousStage;
        switch (keyCode) {
            case ALLEGRO_KEY_C:
                Engine::GameEngine::GetInstance().ChangeScene(StageName);
                break;
            default:
                break;
        }
}

