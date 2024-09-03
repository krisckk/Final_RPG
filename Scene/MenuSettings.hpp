#ifndef MENUSETTINGS_HPP
#define MENUSETTINGS_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class MenuSettings final : public Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> sfxInstance;
        std::shared_ptr<ALLEGRO_BITMAP> background;
    public:
        explicit MenuSettings() = default;
        void Initialize() override;
        void Terminate() override;
        void BGMSlideOnValueChanged(float value);
        void SFXSlideOnValueChanged(float value);
	    void BackOnClick(int stage);
        std::string GetName() const override { return "menuSettings"; }
};

#endif
