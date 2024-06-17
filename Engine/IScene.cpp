#include <allegro5/allegro.h>
#include "IScene.hpp"
#include <string>
#include <stdexcept>
namespace Engine {
	void IScene::Terminate() {
		Clear();
	}
	void IScene::Initialize(){
		
	}
	void IScene::Draw() const {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		Group::Draw();
	}
	std::string IScene::GetName() const {
        throw std::runtime_error("GetName() not implemented in derived class");
    }
}
