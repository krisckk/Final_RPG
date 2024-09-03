#include "Backpack.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/LOG.hpp"
#include "Engine/Resources.hpp"
#include "Engine/Sprite.hpp"
#include "Stats/Shared.hpp"

void Backpack::Initialize(){
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::LOG(Engine::INFO) << "Backpack scene create";
    pirulenFont = al_load_font("Resource/fonts/pirulen.ttf", 36, 0);
    ObjectFont=al_load_font("Resource/fonts/PoetsenOne.ttf", 17, 0);
    AddNewObject(new Engine::Image("MCidleStop.png", 600, 300, w / 5, h / 3, 0, 0));
    AddNewObject(new Engine::Image("Li'sfavorite.png", 933, 390, w / 10, h / 10, 0, 0));
    AddNewObject(new Engine::Image("heart.png", 940, 300, w / 17, h / 12, 0, 0));
    AddNewObject(new Engine::Image("water.png", 940, 510, w / 20, h / 12, 0, 0));
    if(Shared::redPotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/red_water.png", 300, 650, 80, 80, 0, 0));
    if(Shared::bluePotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/blue_water.png", 300, 650, 80, 80, 0, 0));
    if(Shared::yellowPotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/yellow_water.png", 300, 650, 80, 80, 0, 0));
    if(Shared::Gold)
        AddNewObject(new Engine::Image("Gold.png", 190, 510, 80, 80, 0, 0));
    if(Shared::Aluminum)
        AddNewObject(new Engine::Image("Aluminum.png", 190, 650, 80, 80, 0, 0));
    if(Shared::Iron)
        AddNewObject(new Engine::Image("Iron.png", 80, 650, 80, 80, 0, 0));
    if(Shared::HDLoil)
        AddNewObject(new Engine::Image("UndergroundShelter/B1/HardwareRoom/HDFussilOil.png", 80, 510, 80, 80, 0, 0));
    if(Shared::LDLoil)
        AddNewObject(new Engine::Image("UndergroundShelter/B1/HardwareRoom/LDFussilOil.png", 80, 510, 80, 80, 0, 0));
    if (Shared::coin && !Shared::Achievement_cola)
        AddNewObject(new Engine::Image("UndergroundShelter/B3/GYMscene/coin.png", 80, 330, 80, 80, 0, 0));
    if (Shared::Achievement_cola)
        AddNewObject(new Engine::Image("UndergroundShelter/B3/GYMscene/cola.png", 80, 330, 80, 80, 0, 0));
    if (Shared::wooden_stick && !Shared::Achievement_myfavorite)
        AddNewObject(new Engine::Image("stick_in_backpack.png", 190, 330, 80, 80, 0, 0));
    if (Shared::Achievement_myfavorite)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/yummy.png", 190, 330, 80, 80, 0, 0));
    if (Shared::Achievement_home)
        AddNewObject(new Engine::Image("Ground/Home/letter.png", 300, 330, 80, 80, 0, 0));
    if (Shared::key && !Shared::IDcard)
        AddNewObject(new Engine::Image("UndergroundShelter/B2/BiologicalLaboratory/key.png", 300, 510, 80, 80, 0, 0));
    if (Shared::IDcard)
        AddNewObject(new Engine::Image("UndergroundShelter/B1/Office/IDcard.png", 305, 510, 70, 70, 0, 0));


}

void Backpack::Draw() const{
    IScene::Draw();
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 150, 200, ALLEGRO_ALIGN_CENTER, "Object");
    al_draw_rectangle(70, 320, 170, 420, al_map_rgb(255, 255, 255), 2);
    al_draw_rectangle(180, 320, 280, 420, al_map_rgb(255, 255, 255), 2);
    al_draw_rectangle(290, 320, 390, 420, al_map_rgb(255, 255, 255), 2);
    al_draw_rectangle(70, 500, 170, 600, al_map_rgb(255, 255, 255), 2);
    if (Shared::HDLoil) al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120, 605, ALLEGRO_ALIGN_CENTER, "95%Oil");
    else if (Shared::LDLoil) al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120, 605, ALLEGRO_ALIGN_CENTER, "75%Oil");
    //else al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120, 605, ALLEGRO_ALIGN_CENTER, "Oil");
    al_draw_rectangle(70, 640, 170, 740, al_map_rgb(255, 255, 255), 2);
    if(Shared::Iron) al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120, 745, ALLEGRO_ALIGN_CENTER, "Fe");
    al_draw_rectangle(180, 500, 280, 600, al_map_rgb(255, 255, 255), 2);
    if(Shared::Gold) al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 230, 605, ALLEGRO_ALIGN_CENTER, "Au");
    al_draw_rectangle(180, 640, 280, 740, al_map_rgb(255, 255, 255), 2);
    if(Shared::Aluminum) al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 230, 745, ALLEGRO_ALIGN_CENTER, "Al");
    al_draw_rectangle(290, 500, 390, 600, al_map_rgb(255, 255, 255), 2);
    al_draw_rectangle(290, 640, 390, 740, al_map_rgb(255, 255, 255), 2);
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 750, 200, ALLEGRO_ALIGN_CENTER, "Character");
    al_draw_rounded_rectangle(1100, 330, 1400, 370, 10, 10, al_map_rgb(255, 255, 255), 2);
    al_draw_filled_rounded_rectangle(1100, 330, 1100 + Shared::lives * 100, 370, 10, 10, al_map_rgb(255, 255, 255));
    al_draw_rounded_rectangle(1100, 420, 1400, 460, 10, 10, al_map_rgb(255, 255, 255), 2);
    al_draw_filled_rounded_rectangle(1100, 420, 1100 + Shared::hunger * 3, 460, 10, 10, al_map_rgb(255, 255, 255));
    al_draw_rounded_rectangle(1100, 520, 1400, 560, 10, 10, al_map_rgb(255, 255, 255), 2);
    al_draw_filled_rounded_rectangle(1100, 520, 1100 + Shared::thirst * 3, 560, 10, 10, al_map_rgb(255, 255, 255));
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 800, 750, ALLEGRO_ALIGN_CENTER, "Press C to Close");
}

void Backpack::Terminate() {
    al_destroy_font(pirulenFont);
    al_destroy_font(ObjectFont);
    IScene::Terminate();
}

void Backpack::OnKeyDown(int keyCode){
    const std::string StageName = Shared::previousStage;
        switch (keyCode) {
            case ALLEGRO_KEY_C:
                Engine::GameEngine::GetInstance().ChangeScene(StageName);
                break;
            default:
                break;
        }
}
