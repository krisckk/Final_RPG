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
#include "Maincharacter/Maincharacter.hpp"
#include "LibraryScene.hpp"
#include "LabScene.hpp"
#include "Maincharacter/Backpack.hpp"
#include "StorageRoom.hpp"
#include "Stats/Shared.hpp"
#include "ElevatorB4.hpp"
#include "Scene/UndergroundShelter/B3/ElevatorB3.hpp"
bool change = false;

void ElevatorB4::Initialize()
{
    Shared::ElevatorB4 = true;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "ElevatorB4 scene create";
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 30, 0);
    FloorFont = al_load_font("Resource/fonts/pirulen.ttf", 20, 0);
    ChangeFont = al_load_font("Resource/fonts/pirulen.ttf", 150, 0);
    B4Image1 = al_load_bitmap("Resource/images/UndergroundShelter/B4/Elevator/B4-1.jpg");
    B4Image2 = al_load_bitmap("Resource/images/UndergroundShelter/B4/Elevator/B4-2.jpg");
    B4Image3 = al_load_bitmap("Resource/images/UndergroundShelter/B4/Elevator/B4-3.jpg");
    B4Image4 = al_load_bitmap("Resource/images/UndergroundShelter/B4/Elevator/B4-4.jpg");
    AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    AddNewObject(new Engine::Image("2Ddooropened.png", 0, h - 460, 200, 360, 0.5, 0));
    AddNewObject(new Engine::Image("elevator.png", halfW + 30, halfH + 30, 330, 330, 0, 0));
    if (!Shared::Iron)
        AddNewObject(new Engine::Image("Iron.png", 500, 750, 80, 60, 0, 0));
    bgmInstance = AudioHelper::PlaySample("Weightless.ogg", true, AudioHelper::BGMVolume);
    MC = new Maincharacter("MCRightStop.png", 80, 680, 32, 200);
    if (!MC)
    {
        Engine::LOG(Engine::ERROR) << "Failed to create Maincharacter object";
        return;
    }
    MC->groundY = h - 100; // Set the ground level
    AddNewObject(MC);
}

void ElevatorB4::Terminate()
{
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    MC = nullptr;
    al_destroy_font(ChangeFont);
    al_destroy_font(PoetFont);
    al_destroy_font(FloorFont);
    al_destroy_bitmap(Passwordnote);
    al_destroy_bitmap(B4Image1);
    al_destroy_bitmap(B4Image2);
    al_destroy_bitmap(B4Image3);
    al_destroy_bitmap(B4Image4);
    al_destroy_bitmap(B4Image5);
    DotTimer=0.0f;
    ShowDot1=false;
    ShowDot2=false;
    ShowDot3=false;
    ShowDot4=false;
    IScene::Terminate();
}

void ElevatorB4::OnKeyDown(int keyCode)
{
    switch (keyCode)
    {
    case ALLEGRO_KEY_A:
        MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
        break;
    case ALLEGRO_KEY_D:
        MC->MoveRight(1.0f / 60.0f);
        break;
    case ALLEGRO_KEY_W:
        if (MC->Position.x >= 850 && MC->Position.x <= 1000)
        {
            change = true;
        }
        break;
    case ALLEGRO_KEY_P:
        if (MC->Position.x >= 380 && MC->Position.x <= 580)
            Shared::Iron = true;
        break;
    case ALLEGRO_KEY_E:
        if (MC->Position.x <= 5)
            Engine::GameEngine::GetInstance().ChangeScene("StorageRoom");
        break;
    case ALLEGRO_KEY_B:
        Engine::GameEngine::GetInstance().ChangeScene("Backpack");
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

void ElevatorB4::OnKeyUp(int keyCode)
{
    switch (keyCode)
    {
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
void ElevatorB4::Draw() const
{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    al_draw_filled_rectangle(w / 2 + 180, h / 2 + 75, w / 2 + 258, h / 2 + 96, al_map_rgb(60, 60, 70));
    al_draw_text(FloorFont, al_map_rgb(255, 255, 255), w / 2 + 200, h / 2 + 73, 0, "B4");
    if (MC->Position.x <= 5)
    {
        al_draw_filled_triangle(MC->Position.x + 200, 700, MC->Position.x + 200, 740, MC->Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC->Position.x + 200, 680, MC->Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC->Position.x + 230, 700, 0, "Press E to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC->Position.x + 230, 740, 0, "Go Back");
    }

    if (MC->Position.x >= 850 && MC->Position.x <= 1000)
    {
        al_draw_filled_triangle(MC->Position.x + 200, 700, MC->Position.x + 200, 740, MC->Position.x + 170, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC->Position.x + 200, 680, MC->Position.x + 400, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC->Position.x + 230, 700, 0, "Press W to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC->Position.x + 230, 740, 0, "Go To B3");
    }
    if (MC->Position.x >= 380 && MC->Position.x <= 580 && !Shared::Iron)
    {
        al_draw_filled_triangle(MC->Position.x - 55, 700, MC->Position.x - 55, 740, MC->Position.x - 10, 720, al_map_rgb(255, 255, 255));
        al_draw_filled_rounded_rectangle(MC->Position.x - 350, 680, MC->Position.x - 50, 800, 10, 10, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC->Position.x - 310, 700, 0, "Press P to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), MC->Position.x - 310, 740, 0, "Pick Up");
    }
    if (change)
    {   al_draw_filled_rectangle(0, 0, w, h, al_map_rgb(0, 0, 0));
        if(ShowDot1) al_draw_scaled_bitmap(B4Image1,0,0,1518,1408,100,99,w-300,h,0);
        if(ShowDot2) al_draw_scaled_bitmap(B4Image2,0,0,1518,1408,102,100,w-300,h,0);
        if(ShowDot3) al_draw_scaled_bitmap(B4Image3,0,0,1518,1408,100,100,w-300,h,0);
        if(ShowDot4) al_draw_scaled_bitmap(B4Image4,0,0,1518,1408,100,100,w-300,h,0);
    }
}

void ElevatorB4::UpdateDot(float deltaTime)
{
    int m = 1;
    if (change)
    {
        DotTimer += deltaTime;
        if (DotTimer <= 1.0f * m)
            ShowDot1 = true;
        if (DotTimer <= 2.0f * m && DotTimer > 1.0f * m)
        {
            ShowDot2 = true;
            Engine::LOG(Engine::INFO) << "1";
            ShowDot1 = false;
        }
        if (DotTimer <= 3.0f * m && DotTimer > 2.0f * m)
        {
            ShowDot3 = true;
            Engine::LOG(Engine::INFO) << "2";
            ShowDot2 = false;
        }
        if (DotTimer <= 4.0f * m && DotTimer > 3.0f * m)
        {
            ShowDot4 = true;
            Engine::LOG(Engine::INFO) << "3";
            ShowDot3 = false;
        }

        if (DotTimer >= 4.5f)
        {
            change = false;
            Engine::GameEngine::GetInstance().ChangeScene("ElevatorB3");
        }
    }
}
void ElevatorB4::Update(float deltaTime)
{
    Draw();
    IScene::Update(deltaTime);
    UpdateDot(deltaTime);
}
