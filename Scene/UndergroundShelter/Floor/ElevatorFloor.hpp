#ifndef ELEVATORFLOOR_HPP
#define ELEVATORFLOOR_HPP

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
class ElevatorFloor final : public  Engine::IScene {
    private:
        bool showTextBox = true; // Flag to control the visibility of the text box
        float textBoxTimer = 0.0f; // Timer to track the elapsed time
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_FONT* FloorFont;
        ALLEGRO_FONT* pirulenFont;
    public:
        explicit ElevatorFloor() = default;
        void Draw() const override;
        void Update(float deltaTime) override;
        void UpdateTextBox(float deltaTime);
        void Initialize() override;
        void Terminate() override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "ElevatorFloor"; }
};


#endif