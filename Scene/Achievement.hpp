#ifndef ACHIEVEMENT_HPP
#define ACHIEVEMENT_HPP

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class Achievement final : public Engine::IScene {
    private:
        ALLEGRO_BITMAP* CHAMPION_HOLLOW;
        ALLEGRO_BITMAP* CHAMPION;
        ALLEGRO_BITMAP* COLA;
        ALLEGRO_FONT* pirulenFont;
        ALLEGRO_FONT* PoetFont;

    public:
        explicit Achievement() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void BackOnClick(int stage);
        void OnKeyDown(int keycode) override;
        std::string GetName() const override { return "Achievement"; }
};


#endif
