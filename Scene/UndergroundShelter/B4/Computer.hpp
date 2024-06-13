#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class Computer final : public Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
        ALLEGRO_FONT* PoetFont;
        bool Seeds=false;
        bool Diary=false;
    public:
        explicit Computer() = default;
        void Initialize() override;
        void Terminate() override;
        std::string GetName() const override { return "Computer"; }
        void SeedsOnClick(int stage);
        void DiaryOnClick(int stage);
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
        //void SettingsOnClick(int stage);
        //void NewgameOnClick(int stage);
};


#endif
