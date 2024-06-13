// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/LOG.hpp"
#include "Scene/StartScene.hpp"
#include "Scene/MenuSettings.hpp"
#include "Scene/UndergroundShelter/B4/LabScene.hpp"
#include "Scene/UndergroundShelter/B4/LibraryScene.hpp"
#include "Scene/UndergroundShelter/B4/Computer.hpp"
#include "Scene/UndergroundShelter/B4/StorageRoom.hpp"
#include "Scene/UndergroundShelter/B4/ElevatorB4.hpp"
#include "Scene/UndergroundShelter/B3/RestRoom.hpp"
#include "Scene/UndergroundShelter/B3/ElevatorB3.hpp"
#include "Scene/UndergroundShelter/B2/ElevatorB2.hpp"
#include "Maincharacter/Backpack.hpp"


int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();

    // TODO: [HACKATHON-1-SCENE] (3/4): Register Scenes here
	game.AddNewScene("start", new StartScene());
	game.AddNewScene("menuSettings", new MenuSettings());
	game.AddNewScene("Computer", new Computer());
	// B4
	game.AddNewScene("Lab", new LabScene());
	game.AddNewScene("Library", new LibraryScene());
	game.AddNewScene("Backpack", new Backpack());
	game.AddNewScene("StorageRoom", new StorageRoom());
	game.AddNewScene("ElevatorB4", new ElevatorB4());
	// B3
	game.AddNewScene("ElevatorB3", new ElevatorB3());
	game.AddNewScene("RestRoom", new RestRoom());
	// B2
	game.AddNewScene("ElevatorB2", new ElevatorB2());
    // TODO: [HACKATHON-1-SCENE] (4/4): Change the start scene
	game.Start("start", 120, 1600, 900);
	game.Start("menuSettings", 120, 1600, 900);
	game.Start("Backpack", 120, 1600, 900);
	// B4
	game.Start("Lab", 120, 1600, 900);
	game.Start("Library", 120, 1600, 900);
	game.Start("Computer", 120, 1600, 900);
	game.Start("StorageRoom", 120, 1600, 900);
	game.Start("ElevatorB4", 120, 1600, 900);
	// B3
	game.Start("ElevatorB3", 120, 1600, 900);
	game.Start("RestRoom", 120, 1600, 900);
	// B2
	game.Start("ElevatorB2", 120, 1600, 900);
	return 0;
}
