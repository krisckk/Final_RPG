#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <functional>
#include <memory>
#include <string>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "CraftingTable.hpp"
#include "Stats/Shared.hpp"

bool gold_select = false;
bool iron_select = false;
bool al_select = false;
bool oil75_select = false;
bool oil95_select = false;


void CraftingTable::Initialize()
{
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 17, 0);
    pirulenFont = al_load_font("Resource/fonts/pirulen.ttf", 18, 0);
    GOLD_PIC = al_load_bitmap("Resource/images/UndergroundShelter/Floor/CraftingTable/button_gold.png");
    IRON_PIC = al_load_bitmap("Resource/images/UndergroundShelter/Floor/CraftingTable/button_iron.png");
    AL_PIC = al_load_bitmap("Resource/images/UndergroundShelter/Floor/CraftingTable/button_Al.png");
    OIL_PIC = al_load_bitmap("Resource/images/UndergroundShelter/Floor/CraftingTable/button_oil.png");
    goodRocket = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/GoodRocket.png");
    badRocket1 = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/BadRocket1.png");
    badRocket2 = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/BadRocket2.png");
    badRocket3 = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/BadRocket3.png");
    badRocket4 = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/BadRocket4.png");
    badRocket5 = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/BadRocket5.png");
    badRocket6 = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/BadRocket6.png");
    badRocket7 = al_load_bitmap("Resource/images/UndergroundShelter/Floor/Factory/BadRocket7.png");
    Engine::ImageButton *btn;
    AddNewObject(new Engine::Image("UndergroundShelter/Floor/CraftingTable/minecraft.png", 800, 450, 903, 850, 0.5, 0.5));
    if(Shared::redPotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/red_water.png", 386, 465, 80, 70, 0, 0));
    if(Shared::bluePotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/blue_water.png", 386, 465, 80, 70, 0, 0));
    if(Shared::yellowPotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/yellow_water.png", 386, 465, 80, 70, 0, 0));
    if(Shared::Gold)
    {
        btn = new Engine::ImageButton("UndergroundShelter/Floor/CraftingTable/button_gold.png", "UndergroundShelter/Floor/CraftingTable/button_gold.png", 490, 555, 70, 70, 0, 0);
        btn->SetOnClickCallback(std::bind(&CraftingTable::GoldOnClick, this, 1));
        AddNewControlObject(btn);
    }
    if(Shared::Aluminum)
    {
        btn = new Engine::ImageButton("UndergroundShelter/Floor/CraftingTable/button_Al.png", "UndergroundShelter/Floor/CraftingTable/button_Al.png", 390, 650, 70, 70, 0, 0);
        btn->SetOnClickCallback(std::bind(&CraftingTable::AlOnClick, this, 1));
        AddNewControlObject(btn);
    }
    if(Shared::Iron)
    {
        btn = new Engine::ImageButton("UndergroundShelter/Floor/CraftingTable/button_iron.png", "UndergroundShelter/Floor/CraftingTable/button_iron.png", 486, 650, 70, 70, 0, 0);
        btn->SetOnClickCallback(std::bind(&CraftingTable::IronOnClick, this, 1));
        AddNewControlObject(btn);
    }
    
    if(Shared::HDLoil)
    {
        btn = new Engine::ImageButton("UndergroundShelter/Floor/CraftingTable/button_oil.png", "UndergroundShelter/Floor/CraftingTable/button_oil.png", 390, 550, 70, 70, 0, 0);
        btn->SetOnClickCallback(std::bind(&CraftingTable::Oil95OnClick, this, 1));
        AddNewControlObject(btn);
        
    }
    else if(Shared::LDLoil)
    {
        btn = new Engine::ImageButton("UndergroundShelter/Floor/CraftingTable/button_oil.png", "UndergroundShelter/Floor/CraftingTable/button_oil.png", 390, 550, 70, 70, 0, 0);
        btn->SetOnClickCallback(std::bind(&CraftingTable::Oil75OnClick, this, 1));
        AddNewControlObject(btn);
    }

}
void CraftingTable::Terminate()
{
    al_destroy_font(PoetFont);
    al_destroy_font(pirulenFont);
    al_destroy_bitmap(GOLD_PIC);
    al_destroy_bitmap(IRON_PIC);
    al_destroy_bitmap(AL_PIC);
    al_destroy_bitmap(OIL_PIC);
    al_destroy_bitmap(goodRocket);
    IScene::Terminate();
}
void CraftingTable::Draw() const{
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if(Shared::LDLoil) al_draw_text(pirulenFont, al_map_rgb(0, 0, 0), 400, 575, 0, "75%");
    else if(Shared::HDLoil) al_draw_text(pirulenFont, al_map_rgb(0, 0, 0), 400, 575, 0, "95%");

    if (gold_select) al_draw_scaled_bitmap(GOLD_PIC, 0, 0, 70, 70, 805, 258, 70, 70, 0);
    if (iron_select) al_draw_scaled_bitmap(IRON_PIC, 0, 0, 70, 70, 805, 160, 70, 70, 0);
    if (al_select) al_draw_scaled_bitmap(AL_PIC, 0, 0, 70, 70, 895, 258, 70, 70, 0);
    if  (oil95_select && iron_select && al_select && !gold_select){
        al_draw_scaled_bitmap(goodRocket, 0, 0, 585, 621, 1095, 210, 70, 70, 0);
    }
    else if(oil95_select && iron_select && al_select && gold_select) {
        al_draw_scaled_bitmap(badRocket1, 0, 0, 699, 901, 1095, 210, 70, 70, 0);
    }
    else if(oil95_select && gold_select && al_select && !iron_select) {
        al_draw_scaled_bitmap(badRocket2, 0, 0, 489, 641, 1095, 210, 70, 70, 0);
    }
    else if(oil95_select && gold_select && !al_select && iron_select) {
        al_draw_scaled_bitmap(badRocket3, 0, 0, 727, 980, 1095, 210, 70, 70, 0);
    }
    else if(oil75_select && iron_select && al_select && !gold_select) {
        al_draw_scaled_bitmap(badRocket4, 0, 0, 356, 480, 1095, 210, 70, 70, 0);
    }
    else if(oil75_select && iron_select && al_select && gold_select) {
        al_draw_scaled_bitmap(badRocket5, 0, 0, 821, 1097, 1095, 210, 70, 70, 0);
    }
    else if(oil75_select && gold_select && al_select && !iron_select) {
        al_draw_scaled_bitmap(badRocket6, 0, 0, 899, 1211, 1095, 210, 70, 70, 0);
    }
    else if(oil75_select && gold_select && !al_select && iron_select) {
        al_draw_scaled_bitmap(badRocket7, 0, 0, 480, 626, 1095, 210, 70, 70, 0);
    }
    if (oil75_select) 
    {
        al_draw_scaled_bitmap(OIL_PIC, 0, 0, 70, 70, 900, 160, 70, 70, 0);
        al_draw_text(pirulenFont, al_map_rgb(0, 0, 0), 910, 185, 0, "75%");

    }
    else if (oil95_select)
    {
        al_draw_scaled_bitmap(OIL_PIC, 0, 0, 70, 70, 900, 160, 70, 70, 0);
        al_draw_text(pirulenFont, al_map_rgb(0, 0, 0), 910, 185, 0, "95%");

    }   
}

void CraftingTable::GoldOnClick(int stage)
{
    gold_select =!gold_select;
}

void CraftingTable::AlOnClick(int stage)
{
    al_select =!al_select;
}

void CraftingTable::IronOnClick(int stage)
{
    iron_select =!iron_select;
}

void CraftingTable::Oil75OnClick(int stage)
{
    oil75_select =!oil75_select;
    if (oil75_select) oil95_select = false;
}

void CraftingTable::Oil95OnClick(int stage)
{
    oil95_select =!oil95_select;
    if (oil95_select) oil75_select = false;
}

void CraftingTable::OnKeyDown(int keyCode)
{
    switch (keyCode)
    {
        case ALLEGRO_KEY_C:
            if(oil95_select && iron_select && al_select && !gold_select) {
                Shared::GoodRocket = true;
                Shared::BadRocket1 = false;
                Shared::BadRocket2 = false;
                Shared::BadRocket3 = false;
                Shared::BadRocket4 = false;
                Shared::BadRocket5 = false;
                Shared::BadRocket6 = false;
                Shared::BadRocket7 = false;
            }
            else if(oil95_select && iron_select && al_select && gold_select) {
                Shared::GoodRocket = false;
                Shared::BadRocket1 = true; 
                Shared::BadRocket2 = false;
                Shared::BadRocket3 = false;
                Shared::BadRocket4 = false;
                Shared::BadRocket5 = false;
                Shared::BadRocket6 = false;
                Shared::BadRocket7 = false;
            }
            else if(oil95_select && gold_select && al_select && !iron_select) {
                Shared::GoodRocket = false;
                Shared::BadRocket1 = false;
                Shared::BadRocket2 = true;
                Shared::BadRocket3 = false;
                Shared::BadRocket4 = false;
                Shared::BadRocket5 = false;
                Shared::BadRocket6 = false;
                Shared::BadRocket7 = false;
            }
            else if(oil95_select && gold_select && !al_select && iron_select) {
                Shared::GoodRocket = false;
                Shared::BadRocket1 = false;
                Shared::BadRocket2 = false;
                Shared::BadRocket3 = true;
                Shared::BadRocket4 = false;
                Shared::BadRocket5 = false;
                Shared::BadRocket6 = false;
                Shared::BadRocket7 = false;
            }
            else if(oil75_select && iron_select && al_select && !gold_select) {
                Shared::GoodRocket = false;
                Shared::BadRocket1 = false;
                Shared::BadRocket2 = false;
                Shared::BadRocket3 = false;
                Shared::BadRocket4 = true;
                Shared::BadRocket5 = false;
                Shared::BadRocket6 = false;
                Shared::BadRocket7 = false;
            }
            else if(oil75_select && iron_select && al_select && gold_select) {
                Shared::GoodRocket = false;
                Shared::BadRocket1 = false;
                Shared::BadRocket2 = false;
                Shared::BadRocket3 = false;
                Shared::BadRocket4 = false;
                Shared::BadRocket5 = true;
                Shared::BadRocket6 = false;
                Shared::BadRocket7 = false;
            }
            else if(oil75_select && gold_select && al_select && !iron_select) {
                Shared::GoodRocket = false;
                Shared::BadRocket1 = false;
                Shared::BadRocket2 = false;
                Shared::BadRocket3 = false;
                Shared::BadRocket4 = false;
                Shared::BadRocket5 = false;
                Shared::BadRocket6 = true;
                Shared::BadRocket7 = false;
            }
            else if(oil75_select && gold_select && !al_select && iron_select) {
                Shared::GoodRocket = false;
                Shared::BadRocket1 = false;
                Shared::BadRocket2 = false;
                Shared::BadRocket3 = false;
                Shared::BadRocket4 = false;
                Shared::BadRocket5 = false;
                Shared::BadRocket6 = false;
                Shared::BadRocket7 = true;
            }
            Engine::GameEngine::GetInstance().ChangeScene("Factory");
            break;
        default:
            break;
    }
}\
