#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class Computer final : public Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
    public:
        explicit Computer() = default;
        void Initialize() override;
        void Terminate() override;
        //void SettingsOnClick(int stage);
        //void NewgameOnClick(int stage);
};


#endif