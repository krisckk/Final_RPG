#ifndef DATAROOM_HPP
#define DATAROOM_HPP

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
class DataRoom final : public  Engine::IScene {
    private:
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_BITMAP* Background;
        ALLEGRO_BITMAP* firstData;
        ALLEGRO_BITMAP* secondData;
        ALLEGRO_BITMAP* thirdData;
        ALLEGRO_BITMAP* fourthData;
        bool first;
        bool second;
        bool third;
        bool fourth;
    public:
        explicit DataRoom() = default;
        void Initialize() override;
        void Terminate() override;
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        std::string GetName() const override { return "DataRoom"; }
};

#endif