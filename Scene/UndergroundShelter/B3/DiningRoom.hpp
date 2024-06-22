#ifndef DININGROOM_HPP
#define DININGROOM_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"
#include "Maincharacter/Maincharacter.hpp"

namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
}
extern Maincharacter* MC;
class DiningRoom final : public  Engine::IScene {
    private:
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_FONT* BIGFont;
    public:
        explicit DiningRoom() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "DiningRoom"; }
};


#endif
