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
#include "Scene/UndergroundShelter/B4/LibraryScene.hpp"
#include "Scene/UndergroundShelter/B4/LabScene.hpp"
#include "Scene/UndergroundShelter/B4/StorageRoom.hpp"
#include "RestRoom.hpp"
#include "Stats/Shared.hpp"

void RestRoom::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "StorageRoom scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 150, 0);
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/RestRoom/Blackboard.jpg", 400, 500, 800, 700, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/RestRoom/Sofa.jpg", 900, 600, 1200, 800, 0, 0));
    AddNewObject(new Engine::Image("UndergroundShelter/B3/RestRoom/TV.jpg", 1250, 500, 150, 100, 0, 0));
    bgmInstance = AudioHelper::PlaySample("joannaliaoThemeSong.ogg", true, AudioHelper::BGMVolume);
}
void RestRoom::Terminate(){
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    //MC = nullptr; 
    al_destroy_font(PoetFont);
    al_destroy_font(BIGFont);
    IScene::Terminate();
}