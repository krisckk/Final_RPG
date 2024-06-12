// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/LOG.hpp"
#include "Scene/StartScene.hpp"
#include "Scene/MenuSettings.hpp"
#include "Scene/UndergroundShelter/B4/LabScene.hpp"
#include "Scene/UndergroundShelter/B4/LibraryScene.hpp"


int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();

    // TODO: [HACKATHON-1-SCENE] (3/4): Register Scenes here
	game.AddNewScene("start", new StartScene());
	game.AddNewScene("menuSettings", new MenuSettings());
	game.AddNewScene("Lab", new LabScene());
	game.AddNewScene("Library", new LibraryScene());
    // TODO: [HACKATHON-1-SCENE] (4/4): Change the start scene
	game.Start("start", 120, 1600, 900);
	game.Start("menuSettings", 120, 1600, 900);
	game.Start("Lab", 120, 1600, 900);
	game.Start("Library", 120, 1600, 900);
	return 0;
}
