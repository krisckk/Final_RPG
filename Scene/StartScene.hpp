///
/// Created by Kris on 2024/6/10
///

#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class StartScene final : public Engine::IScene {
    private:
    public:
        explicit StartScene() = default;
        void Initialize() override;
        void Terminate() override;
        void SettingsOnClick(int stage);
        void NewgameOnClick(int stage);
        void ContinueOnClick(int stage);
        void AchievementOnClick(int stage);
        std::string GetName() const override { return "start"; }
};


#endif
