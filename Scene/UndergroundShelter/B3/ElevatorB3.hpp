#ifndef ELEVATORB3_HPP
#define ELEVATORB3_HPP

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
class ElevatorB3 final : public  Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_FONT* FloorFont;
    public:
        explicit ElevatorB3() = default;
        void Draw() const override;
        void Update(float deltaTime) override;
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "ElevatorB3"; }
};


#endif
