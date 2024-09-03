#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "MenuSettings.hpp"

void MenuSettings::Initialize() {
    // BackGround
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Image("menu_background.jpg", halfW, halfH - 150, 0, 0, 0.5, 0.5));
    AddNewObject(
            new Engine::Label("Settings", "PoetsenOne.ttf", 56, halfW / 2 - 210, halfH / 2 + 20, 255, 255, 255, 255, 0, 0.5));
    Engine::ImageButton *btn;
    Slider *sliderBGM, *sliderSFX;
    sliderBGM = new Slider(40 + halfW - 95, halfH - 50 - 2, 190, 4);
    sliderBGM->SetOnValueChangedCallback(
            std::bind(&MenuSettings::BGMSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderBGM);
    AddNewObject(
            new Engine::Label("BGM: ", "PoetsenOne.ttf", 28, 40 + halfW - 60 - 95, halfH - 50, 255, 255, 255, 255, 0.5, 0.5));
    sliderSFX = new Slider(40 + halfW - 95, halfH + 50 - 2, 190, 4);
    sliderSFX->SetOnValueChangedCallback(
            std::bind(&MenuSettings::SFXSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderSFX);
    AddNewObject(
            new Engine::Label("SFX: ", "PoetsenOne.ttf", 28, 40 + halfW - 60 - 95, halfH + 50, 255, 255, 255, 255, 0.5, 0.5));
    btn = new Engine::ImageButton("Blankbackground.png", "Blankbackground.png", halfW - 65, 635, 130, 60);
    btn->SetOnClickCallback(std::bind(&MenuSettings::BackOnClick, this, 1));
    AddNewControlObject(btn);
    Engine::GameEngine::GetInstance().PlayBGM("Intestellar.ogg");
}
void MenuSettings::Terminate() {
    IScene::Terminate();
}
void MenuSettings::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("start");
}
void MenuSettings::BGMSlideOnValueChanged(float value) {
    AudioHelper::BGMVolume = value;
}

void MenuSettings::SFXSlideOnValueChanged(float value) {
    sfxInstance = AudioHelper::PlaySample("laser.wav", false, AudioHelper::SFXVolume);
    AudioHelper::SFXVolume = value;
}
