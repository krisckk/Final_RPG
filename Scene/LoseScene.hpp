///
/// Created by Kris on 2024/6/10
///

#ifndef LOSESCENE_HPP
#define LOSESCENE_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class LoseScene final : public Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
    public:
        explicit LoseScene() = default;
        void Initialize() override;
        void Terminate() override;
        void SettingsOnClick(int stage);
        void NewgameOnClick(int stage);
        void ContinueOnClick(int stage);
        void OnKeyDown(int keycode) override;
        std::string GetName() const override { return "Lose"; }
};


#endif
