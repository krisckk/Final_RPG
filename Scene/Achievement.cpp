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
#include "Scene/Achievement.hpp"
#include "Scene/UndergroundShelter/B4/LabScene.hpp"
#include "Stats/Shared.hpp"
void Achievement::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    pirulenFont = al_load_font("Resource/fonts/pirulen.ttf", 36, 0);
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 16, 0);
    CHAMPION = al_load_bitmap("Resource/images/Achievement/champion.png");
    CHAMPION_HOLLOW = al_load_bitmap("Resource/images/Achievement/champion_hollow.png");
    COLA = al_load_bitmap("Resource/images/UndergroundShelter/B3/GYMscene/cola.png");
    
    Engine::ImageButton *btn;
    btn = new Engine::ImageButton("Achievement/back_button.png", "Achievement/back_button.png", halfW, 670, 170, 55, 0.5, 0.5);
    btn->SetOnClickCallback(std::bind(&Achievement::BackOnClick, this, 1));
    AddNewControlObject(btn);
}

void Achievement::Terminate() {
    IScene::Terminate();
}

void Achievement::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), halfW, 120, ALLEGRO_ALIGN_CENTER, "ACHIEVEMENT");
    if (!Shared::Achievement_cola) 
        al_draw_scaled_bitmap(CHAMPION_HOLLOW, 0, 0, 200, 200, halfW - 100, halfH - 128, 200, 200, 0);
    else 
    {        
        al_draw_scaled_bitmap(CHAMPION, 0, 0, 200, 200, halfW - 100, halfH - 128, 200, 200, 0);
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), halfW, halfH + 95, ALLEGRO_ALIGN_CENTER, "Here's a little reward for");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), halfW, halfH + 110, ALLEGRO_ALIGN_CENTER, "someone loving lifting barbell:D");

    }
    
    if (!Shared::Achievement_home)
        al_draw_scaled_bitmap(CHAMPION_HOLLOW, 0, 0, 200, 200, halfW - 440, halfH - 128, 200, 200, 0);
    else
    {
        al_draw_scaled_bitmap(CHAMPION, 0, 0, 200, 200, halfW - 440, halfH - 128, 200, 200, 0);
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), halfW - 340, halfH + 95, ALLEGRO_ALIGN_CENTER, "You went home and read the letter,");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), halfW - 340, halfH + 110, ALLEGRO_ALIGN_CENTER, "Now you know the whole story!");
    }

    if (!Shared::Achievement_myfavorite)
        al_draw_scaled_bitmap(CHAMPION_HOLLOW, 0, 0, 200, 200, halfW + 240, halfH - 128, 200, 200, 0);
    else
    {
        al_draw_scaled_bitmap(CHAMPION, 0, 0, 200, 200, halfW + 240, halfH - 128, 200, 200, 0);
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), halfW + 340, halfH + 95, ALLEGRO_ALIGN_CENTER, "You got the best food in the world!");
        al_draw_text(PoetFont, al_map_rgb(255, 255, 255), halfW + 340, halfH + 110, ALLEGRO_ALIGN_CENTER, "You are foodie champion!");
    }
}
void Achievement::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("start");
}
void Achievement::OnKeyDown(int keyCode)
{
    switch (keyCode)
    {
    case ALLEGRO_KEY_B:
        Engine::GameEngine::GetInstance().ChangeScene("start");
        break;
    default:
        break;
    }
}
