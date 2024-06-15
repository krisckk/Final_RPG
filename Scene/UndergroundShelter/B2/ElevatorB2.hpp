#ifndef ELEVATORB2_HPP
#define ELEVATORB2_HPP

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include <string>
#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"
#include "Monster/Monster.hpp"
#include "Maincharacter/Maincharacter.hpp"

namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
}
extern Monster* Enemy;
extern Maincharacter* MC;
class ElevatorB2 final : public  Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_FONT* FloorFont;
        ALLEGRO_FONT* BIGFont;
        ALLEGRO_BITMAP* GameoverBackground;
    public:
        explicit ElevatorB2() = default;
        void Draw() const override;
        void Update(float deltaTime) override;
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "ElevatorB2"; }
};


#endif
