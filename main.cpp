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
#include "Scene/UndergroundShelter/B3/GYMscene.hpp"
#include "Scene/UndergroundShelter/B3/DiningRoom.hpp"
#include "Scene/UndergroundShelter/B3/DataRoom.hpp"
#include "Scene/UndergroundShelter/B2/ElevatorB2.hpp"
#include "Scene/UndergroundShelter/B2/BiologicalLaboratory.hpp"
#include "Scene/UndergroundShelter/B1/ElevatorB1.hpp"
#include "Scene/UndergroundShelter/B1/HardwareRoom.hpp"
#include "Scene/UndergroundShelter/B1/Office.hpp"
#include "Scene/UndergroundShelter/B1/ElevatorToFloor.hpp"
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
	game.AddNewScene("GYMscene", new GYMscene());
	game.AddNewScene("DiningRoom", new DiningRoom());
	game.AddNewScene("DataRoom", new DataRoom());
	// B2
	game.AddNewScene("ElevatorB2", new ElevatorB2());
	game.AddNewScene("BiologicalLaboratory", new BiologicalLaboratory());
	// B1
	game.AddNewScene("ElevatorB1", new ElevatorB1());
	game.AddNewScene("HardwareRoom", new HardwareRoom());
	game.AddNewScene("Office", new Office());
	game.AddNewScene("ElevatorToFloor", new ElevatorToFloor());
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
	game.Start("GYMscene", 120, 1600, 900);
	game.Start("DiningRoom", 120, 1600, 900);
	game.Start("DataRoom", 120, 1600, 900);
	// B2
	game.Start("ElevatorB2", 120, 1600, 900);
	game.Start("BiologicalLaboratory", 120, 1600, 900);
	// B1
	game.Start("ElevatorB1", 120, 1600, 900);
	game.Start("HardwareRoom", 120, 1600, 900);
	game.Start("Office", 120, 1600, 900);
	game.Start("ElevatorToFloor", 120, 1600, 900);
	return 0;
}
