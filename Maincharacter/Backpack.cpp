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
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/red_water.png", 80, 330, 80, 80, 0, 0));
    if(Shared::bluePotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/blue_water.png", 190, 330, 80, 80, 0, 0));
    if(Shared::yellowPotion)
        AddNewObject(new Engine::Image("UndergroundShelter/B4/StorageRoom/yellow_water.png", 300, 330, 80, 80, 0, 0));
}

void Backpack::Draw() const{
    IScene::Draw();
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 150, 200, ALLEGRO_ALIGN_CENTER, "Object");
    al_draw_rectangle(70, 320, 170, 420, al_map_rgb(255, 255, 255), 2);
    al_draw_rectangle(180, 320, 280, 420, al_map_rgb(255, 255, 255), 2);
    al_draw_rectangle(290, 320, 390, 420, al_map_rgb(255, 255, 255), 2);
    al_draw_rectangle(70, 500, 170, 600, al_map_rgb(255, 255, 255), 2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120, 605, ALLEGRO_ALIGN_CENTER, "75% Oil");
    al_draw_rectangle(70, 640, 170, 740, al_map_rgb(255, 255, 255), 2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120, 745, ALLEGRO_ALIGN_CENTER, "95% Oil");
    al_draw_rectangle(180, 500, 280, 600, al_map_rgb(255, 255, 255), 2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 230, 605, ALLEGRO_ALIGN_CENTER, "Au");
    al_draw_rectangle(180, 640, 280, 740, al_map_rgb(255, 255, 255), 2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 230, 745, ALLEGRO_ALIGN_CENTER, "Al");
    al_draw_rectangle(290, 500, 390, 600, al_map_rgb(255, 255, 255), 2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 340, 605, ALLEGRO_ALIGN_CENTER, "Fe");
    al_draw_rectangle(290, 640, 390, 740, al_map_rgb(255, 255, 255), 2);
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 750, 200, ALLEGRO_ALIGN_CENTER, "Character");
    al_draw_rounded_rectangle(1100, 330, 1400, 370, 10, 10, al_map_rgb(255, 255, 255), 2);
    al_draw_filled_rounded_rectangle(1100, 330, 1100 + Shared::lives * 100, 370, 10, 10, al_map_rgb(255, 255, 255));
    al_draw_rounded_rectangle(1100, 420, 1400, 460, 10, 10, al_map_rgb(255, 255, 255), 2);
    al_draw_filled_rounded_rectangle(1100, 420, 1100 + Shared::hunger * 3, 460, 10, 10, al_map_rgb(255, 255, 255));
    al_draw_rounded_rectangle(1100, 520, 1400, 560, 10, 10, al_map_rgb(255, 255, 255), 2);
    al_draw_filled_rounded_rectangle(1100, 520, 1100 + Shared::thirst * 3, 560, 10, 10, al_map_rgb(255, 255, 255));
}

void Backpack::Terminate() {
    al_destroy_font(pirulenFont);
    al_destroy_font(ObjectFont);
    IScene::Terminate();
}

void Backpack::OnKeyDown(int keyCode){
    const std::string StageName = Shared::previosStage;
        switch (keyCode) {
            case ALLEGRO_KEY_ESCAPE:
                Engine::GameEngine::GetInstance().ChangeScene(StageName);
                break;
            default:
                break;
        }
    
    //if(keyCode == ALLEGRO_KEY_E) Engine::GameEngine::GetInstance().ChangeScene("Library");
}
