#ifndef ELEVATORB4_HPP
#define ELEVATORB4_HPP

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
class ElevatorB4 final : public  Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_FONT* FloorFont;
        ALLEGRO_FONT* ChangeFont;
        ALLEGRO_BITMAP* Passwordnote;
        ALLEGRO_BITMAP* IronImage;
        ALLEGRO_BITMAP* B4Image1;
        ALLEGRO_BITMAP* B4Image2;
        ALLEGRO_BITMAP* B4Image3;
        ALLEGRO_BITMAP* B4Image4;
        ALLEGRO_BITMAP* B4Image5;
        bool ShowDot1 = false;
        bool ShowDot2 = false;
        bool ShowDot3 = false;
        bool ShowDot4 = false;
        float DotTimer = 0.0f;
    public:
        explicit ElevatorB4() = default;
        void Draw() const override;
        void Update(float deltaTime) override;
        void UpdateDot(float deltaTime);
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "ElevatorB4"; }
};


#endif
