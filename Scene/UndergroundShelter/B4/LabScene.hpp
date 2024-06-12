#ifndef LABSCENE_HPP
#define LABSCENE_HPP

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
extern Maincharacter* MC;
namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
} 
class LabScene final : public Engine::IScene {
private:
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
	bool showTextBox = true; // Flag to control the visibility of the text box
    float textBoxTimer = 0.0f; // Timer to track the elapsed time
	ALLEGRO_FONT* pirulenFont;
	ALLEGRO_FONT* PoetFont;
	//std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> deathBGMInstance;

public:
	explicit LabScene() = default;
	void Draw() const override;
	void UpdateTextBox(float deltaTime);
	void Update(float deltaTime) override;
	void Initialize() override;
	void Terminate() override;
	void OnKeyDown(int keyCode) override;
	void OnKeyUp(int keyCode) override;
};

#endif //LABSCENE_HPP