#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <functional>
#include <memory>
#include <string>
#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Point.hpp"
#include "Engine/LOG.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Computer.hpp"

char word[5];
int cur = 0;

void Computer::Initialize()
{
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    PoetFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 17, 0);
    OSImage = al_load_bitmap("Resource/images/UndergroundShelter/B4/Computer/OS.jpg");
    BIGFont = al_load_font("Resource/fonts/PoetsenOne.ttf", 40, 0);
    signinImage = al_load_bitmap("Resource/images/UndergroundShelter/B4/Computer/user.jpg");
    AddNewObject(new Engine::Image("UndergroundShelter/B4/Computer/WindowsBackground.png", 0, 0, w, h, 0, 0));
    bgmInstance = AudioHelper::PlaySample("Weightless.ogg", true, AudioHelper::BGMVolume);

    Engine::ImageButton *btn;
    btn = new Engine::ImageButton("UndergroundShelter/B4/Computer/file.png", "UndergroundShelter/B4/Computer/file.png", halfW / 2 + 850, halfH / 2 + 90, 120, 120, 0, 0);
    btn->SetOnClickCallback(std::bind(&Computer::DiaryOnClick, this, 1));
    AddNewControlObject(btn);
    btn = new Engine::ImageButton("UndergroundShelter/B4/Computer/file.png", "UndergroundShelter/B4/Computer/file.png", halfW / 2 + 850, halfH / 2 + 200, 120, 120, 0, 0);
    btn->SetOnClickCallback(std::bind(&Computer::SeedsOnClick, this, 1));
    AddNewControlObject(btn);
    btn = new Engine::ImageButton("UndergroundShelter/B4/Computer/file.png", "UndergroundShelter/B4/Computer/file.png", halfW / 2 + 850, halfH / 2 + 310, 120, 120, 0, 0);
    btn->SetOnClickCallback(std::bind(&Computer::PasswordOnClick, this, 1));
    AddNewControlObject(btn);

}
void Computer::Terminate()
{
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    IScene::Terminate();
    al_destroy_font(PoetFont);
    al_destroy_font(BIGFont);
    al_destroy_bitmap(OSImage);
    al_destroy_bitmap(signinImage);
}
void Computer::Draw() const
{
    Engine::ImageButton *btn;
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    al_draw_text(PoetFont, al_map_rgb(0, 0, 0), halfW / 2 + 865, halfH / 2 + 170, 0, "Researcher's");
    al_draw_text(PoetFont, al_map_rgb(0, 0, 0), halfW / 2 + 890, halfH / 2 + 190, 0, "Diary");
    al_draw_text(PoetFont, al_map_rgb(0, 0, 0), halfW / 2 + 890, halfH / 2 + 280, 0, "Seeds");    
    al_draw_text(PoetFont, al_map_rgb(0, 0, 0), halfW / 2 + 883, halfH / 2 + 390, 0, "Password");


    if (Seeds)
    {
        al_draw_filled_rectangle(w / 2 - 300, 100, w / 2 + 300, 760, al_map_rgb(255, 255, 255));
        al_draw_filled_rectangle(w / 2 - 300, 100, w / 2 + 300, 130, al_map_rgb(2, 13, 128));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 140, 0, "seed 000");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 160, 0, "Name: Adam Morphy");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 180, 0, "birthday: 1998/06/12");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 200, 0, "residence: N city");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 220, 0, "spouse: Catherine Taylor");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 260, 0, "seed 001");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 280, 0, "Name: Bill Brown");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 300, 0, "birthday: 1992/10/09");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 320, 0, "residence: F city");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 340, 0, "spouse: Janice Smith");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 380, 0, "seed 002");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 400, 0, "Name: Max Huang");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 420, 0, "birthday: 2000/01/03");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 440, 0, "residence: P city");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 460, 0, "spouse: --");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 500, 0, "seed 003");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 520, 0, "Loading Failed");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 100, 720, 0, "Press C to close the file");
        if (OS)
        {
            al_draw_scaled_bitmap(OSImage, 0, 0, 1000, 338, w / 2 - 350, 550, 700, 300, 0);
        }
    }
    else if (Diary)
    {
        al_draw_filled_rectangle(w / 2 - 300, 100, w / 2 + 300, 860, al_map_rgb(255, 255, 255));
        al_draw_filled_rectangle(w / 2 - 300, 100, w / 2 + 300, 130, al_map_rgb(2, 13, 128));

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 140, 0, "2024/02/28");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 160, 0, "I'm so tired from work, so I'd better write a diary,");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 180, 0, "otherwise I can't do anything here except experiment.");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 220, 0, "2024/03/01");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 240, 0, "Today is a happy day, we have McDonald's for lunch.");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 260, 0, "I found that the monster was unusually excited.");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 280, 0, "Maybe the fries were too fragrant.If the fries had no calories,");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 300, 0, "I would eat them every day.I was feeling hungry again:(");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 340, 0, "2024/03/02");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 360, 0, "I feel so depressed after my experiment failed today.");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 380, 0, "I really want to eat French fries, even though I already had");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 400, 0, "them yesterday.But today I tried the food in the cafeteria for");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 420, 0, "the first time, and found that I was full of energy after eating it.");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 460, 0, "2024/03/03");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 480, 0, "The gym is newly opened today.");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 500, 0, "I heard that your memory will improve if you exercise more.");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 530, 0, "2024/03/04");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 550, 0, "Something terrible happened today. The monsters all escaped for some ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 570, 0, "reason. Now there are monsters everywhere. I can only hide in the ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 590, 0, "storage room. The only place they don't approach. I hope the ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 610, 0, "investigators can quickly eliminate them.");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 640, 0, "2024/03/05");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 660, 0, "There is a group of new personnel today, and they seem to be here to");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 680, 0, "build spaceships. Hopefully they can finish it successfully and we");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 700, 0, "can get out of this shitty place as soon as possible.");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 730, 0, "2024/05/19");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 750, 0, "The spaceship is built! But they seem to have ordered too many ");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 770, 0, "materials,and there are parts all over the corridor.");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 800, 0, "2024/05/20");
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 280, 820, 0, "We are leaving tomorrow, goodbye Earth!");

        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 - 100, 840, 0, "Press C to close the file");
    }
    else if (password)
    {
        al_draw_filled_rectangle(w / 2, 460, w / 2 + 300, 760, al_map_rgb(255, 255, 255));
        al_draw_text(PoetFont, al_map_rgb(0, 0, 0), w / 2 + 50, 600, 0, "0310");

    }

    if (!signin) 
    {
        al_draw_scaled_bitmap(signinImage, 0, 0, 800, 541, 0, 0, 1600, 900, 0);
    }

    if (!signin)
    {
        if (word[0] != '\0') al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 585, 470, 0, ".");
        if (word[1] != '\0') al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 595, 470, 0, ".");
        if (word[2] != '\0') al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 605, 470, 0, ".");
        if (word[3] != '\0') al_draw_textf(BIGFont, al_map_rgb(0, 0, 0), 615, 470, 0, ".");
    }

}

void Computer::SeedsOnClick(int stage)
{
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if (!Diary && !password)
        Seeds = true;
    else
        Seeds = false;
}

void Computer::DiaryOnClick(int stage)
{
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    if (!Seeds && !password)
        Diary = true;
    else
        Diary = false;
}

void Computer::PasswordOnClick(int stage)
{
    if (!Seeds && !Diary)
        password = true;
    else
        password = false;
}

void Computer::OnKeyDown(int keyCode)
{
    switch (keyCode)
    {
    case ALLEGRO_KEY_C:
        if (Seeds && !OS)
        {
            OS = true;
        }
        else if (Seeds && OS)
        {
            OS = false;
            Seeds = false;
        }
        else if (Diary)
        {
            Diary = false;
        } 
        else if (password)
        {
            password = false;
        }
        else
        {
            Seeds = false;
            Diary = false;
            password = false;
            Engine::GameEngine::GetInstance().ChangeScene("Library");
        }
        break;
    case ALLEGRO_KEY_ENTER:
        if (!signin)
        {
            if (word[0] == '5' && word[1] == '3' && word[2] == '4' && word[3] == '0')
            {
                signin = true;
            }
        }
        break;
    case ALLEGRO_KEY_1:
    case ALLEGRO_KEY_2:
    case ALLEGRO_KEY_3:
    case ALLEGRO_KEY_4:
    case ALLEGRO_KEY_5:
    case ALLEGRO_KEY_6:
    case ALLEGRO_KEY_7:
    case ALLEGRO_KEY_8:
    case ALLEGRO_KEY_9:
    case ALLEGRO_KEY_0:
    case ALLEGRO_KEY_BACKSPACE:
        if (!signin){
            if (keyCode == ALLEGRO_KEY_BACKSPACE){
                if (word[0]!= '\0'){
                    for (int j = 0; j < 4; j++) word[j] = '\0';
                    cur = 0;
                }
            }
            else{
                Engine::LOG(Engine::INFO) << "Key pressed: " << keyCode - 27;
                word[cur] = *al_keycode_to_name(keyCode);
                cur++;
            }
        }
        break;
    default:
        break;
    }
}
