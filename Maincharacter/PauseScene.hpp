#ifndef PAUSESCENE_HPP
#define PAUSESCENE_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <memory>
#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"

class PauseScene final : public  Engine::IScene {
    private:
        ALLEGRO_FONT* pirulenFont;
        ALLEGRO_FONT* ObjectFont;
    public:
        explicit PauseScene() = default;
        void Draw() const override;
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        void SaveOnClick(int stage);
        void ResumeOnClick(int stage);
        std::string GetName() const override { return "PauseScene"; }
};


#endif
