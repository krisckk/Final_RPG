#ifndef LABSCENE_HPP
#define LABSCENE_HPP

#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include <string>

#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"

namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
} 
class LabScene final : public Engine::IScene {
private:
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
	//std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> deathBGMInstance;
protected:
	int Lives;
	int Hunger;
    int Thirst;
	int currentTime;
public:
	explicit LabScene() = default;
	void Initialize() override;
	void Terminate() override;
	void OnKeyDown(int keyCode) override;
	void OnKeyUp(int keyCode) override;
};

#endif //LABSCENE_HPP