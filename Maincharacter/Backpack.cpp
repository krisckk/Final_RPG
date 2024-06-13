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
    //AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackground.png", 0, 0, w, h, 0, 0));
    //AddNewObject(new Engine::Image("UndergroundShelter/LabGeneralBackgroundPlatform.png", 0, h - 520, w, 60, 0, 0));
    //bgmInstance = AudioHelper::PlaySample("joannaliaoThemeSong.ogg", true, AudioHelper::BGMVolume);
    //AddNewObject(new Engine::Image("2Ddooropened.jpg", 0, h - 450, 200, 360, 0.5, 0));
    bgmInstance = AudioHelper::PlaySample("joannaliaoThemeSong.ogg", true, AudioHelper::BGMVolume);
    
}

void Backpack::Draw() const{
    IScene::Draw();
    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 150, 200, ALLEGRO_ALIGN_CENTER, "Object");
    al_draw_rectangle(70, 320, 170, 420,  al_map_rgb(255, 255, 255),2);
    al_draw_rectangle(180, 320, 280, 420,  al_map_rgb(255, 255, 255),2);
    al_draw_rectangle(290, 320, 390, 420,  al_map_rgb(255, 255, 255),2);


    al_draw_rectangle(70, 500, 170, 600,  al_map_rgb(255, 255, 255),2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120, 605, ALLEGRO_ALIGN_CENTER, "75% Oil");
    al_draw_rectangle(70, 640, 170, 740,  al_map_rgb(255, 255, 255),2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 120,745, ALLEGRO_ALIGN_CENTER, "95% Oil");
    al_draw_rectangle(180, 500, 280, 600,  al_map_rgb(255, 255, 255),2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 230, 605, ALLEGRO_ALIGN_CENTER, "Au");
    al_draw_rectangle(180, 640, 280, 740,  al_map_rgb(255, 255, 255),2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 230, 745, ALLEGRO_ALIGN_CENTER, "Al");
    al_draw_rectangle(290, 500, 390, 600,  al_map_rgb(255, 255, 255),2);
    al_draw_text(ObjectFont, al_map_rgb(255, 255, 255), 340, 605, ALLEGRO_ALIGN_CENTER, "Fe");
    al_draw_rectangle(290, 640, 390, 740,  al_map_rgb(255, 255, 255),2);
    

    al_draw_text(pirulenFont, al_map_rgb(255, 255, 255), 750, 200, ALLEGRO_ALIGN_CENTER, "Character");

    /*al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 150, 470, ALLEGRO_ALIGN_CENTER, "Seeds 000");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 400, 470, ALLEGRO_ALIGN_CENTER, "Seeds 001");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 650, 470, ALLEGRO_ALIGN_CENTER, "Seeds 002");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 950, 470, ALLEGRO_ALIGN_CENTER, "Seeds 003");
    al_draw_text(ParasiteFont, al_map_rgb(54, 100, 139), 1200, 470, ALLEGRO_ALIGN_CENTER, "Seeds 004");*/
    //al_draw_text(PoetFont, al_map_rgb(255, 255, 255),250 , 850, ALLEGRO_ALIGN_CENTER, "Press B to open the backpack");
    
}

void Backpack::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    //delete MC; // Delete the dynamically allocated Maincharacter object
    /*MC = nullptr; 
    al_destroy_font(pirulenFont);*/
    al_destroy_font(pirulenFont);
    al_destroy_font(ObjectFont);
    IScene::Terminate();
}

void Backpack::OnKeyDown(int keyCode){
    //if(!showTextBox){
    const std::string StageName = Shared::previosStage;
        switch (keyCode) {
            case ALLEGRO_KEY_ESCAPE:
                Engine::GameEngine::GetInstance().ChangeScene(StageName);
                break;
            case ALLEGRO_KEY_A:
                //MC->MoveLeft(1.0f / 60.0f); // Assuming 60 FPS
                break;
            case ALLEGRO_KEY_D:
               // MC->MoveRight(1.0f / 60.0f);
                break;
            case ALLEGRO_KEY_W:
                //MC->ClimbUp(1.0f / 60.0f);
                break;
            case ALLEGRO_KEY_S:
                //MC->ClimbDown(1.0f / 60.0f);
                break;
            case ALLEGRO_KEY_E:
                break;
                //if (MC -> Position.x >= 1400 && MC -> Position.x <= 1600)   Engine::GameEngine::GetInstance().ChangeScene("Library");
            case ALLEGRO_KEY_B:
                break;
                //Engine::GameEngine::GetInstance().ChangeScene("Backpack");
            default:
                break;
        }
    
    //if(keyCode == ALLEGRO_KEY_E) Engine::GameEngine::GetInstance().ChangeScene("Library");
}
