#ifndef ROAD_HPP
#define ROAD_HPP

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
#include "Monster/Monster.hpp"

namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
}
extern Maincharacter* MC;
class Road final : public  Engine::IScene {
    private:
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_FONT* FloorFont;
        ALLEGRO_FONT* BIGFont;
        ALLEGRO_BITMAP* GameoverBackground;
    public:
        explicit Road() = default;
        void Draw() const override;
        void Update(float deltaTime) override;
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "Road"; }
};


#endif
