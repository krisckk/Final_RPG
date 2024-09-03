// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "Engine/LOG.hpp"
#include "Scene/StartScene.hpp"
#include "Scene/MenuSettings.hpp"
#include "Scene/Achievement.hpp"
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
#include "Scene/UndergroundShelter/Floor/ElevatorFloor.hpp"
#include "Scene/UndergroundShelter/Floor/Factory.hpp"
#include "Scene/UndergroundShelter/Floor/CraftingTable.hpp"
#include "Scene/Ground/Home.hpp"
#include "Scene/Ground/House.hpp"
#include "Scene/Ground/Road.hpp"
#include "Scene/WinScene.hpp"
#include "Scene/LoseScene.hpp"
#include "Maincharacter/Backpack.hpp"
#include "Maincharacter/PauseScene.hpp"
#include "Scene/Map/Map.hpp"


int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene("start", new StartScene());
	game.AddNewScene("menuSettings", new MenuSettings());
	game.AddNewScene("Achievement", new Achievement());
	game.AddNewScene("Computer", new Computer());
	game.AddNewScene("PauseScene", new PauseScene());
	game.AddNewScene("Lose", new LoseScene());
	game.AddNewScene("Win", new WinScene());
	game.AddNewScene("Map", new Map());
	// B4
	game.AddNewScene("Lab", new LabScene());
	game.AddNewScene("Library", new LibraryScene());
	game.AddNewScene("Backpack", new Backpack());
	game.AddNewScene("StorageRoom", new StorageRoom());
	game.AddNewScene("ElevatorB4", new ElevatorB4());
	// B3
	game.AddNewScene("ElevatorB3", new ElevatorB3());
	game.AddNewScene("RestRoom", new RestRoom());
	game.AddNewScene("DiningRoom", new DiningRoom());
	game.AddNewScene("GYMscene", new GYMscene());
	game.AddNewScene("DataRoom", new DataRoom());
	// B2
	game.AddNewScene("ElevatorB2", new ElevatorB2());
	game.AddNewScene("BiologicalLaboratory", new BiologicalLaboratory());
	// B1
	game.AddNewScene("ElevatorB1", new ElevatorB1());
	game.AddNewScene("HardwareRoom", new HardwareRoom());
	game.AddNewScene("Office", new Office());
	game.AddNewScene("ElevatorToFloor", new ElevatorToFloor());
	// Floor
	game.AddNewScene("ElevatorFloor", new ElevatorFloor());
	game.AddNewScene("Factory", new Factory());
	game.AddNewScene("CraftingTable", new CraftingTable());
    // Ground
	game.AddNewScene("Home", new Home());
	game.AddNewScene("House", new House());
	game.AddNewScene("Road", new Road());

	game.Start("start", 120, 1600, 900);
	game.Start("menuSettings", 120, 1600, 900);
	game.Start("Achievement", 120, 1600, 900);
	game.Start("Backpack", 120, 1600, 900);
	game.Start("PauseScene", 120, 1600, 900);
	game.Start("Win", 120, 1600, 900);
	game.Start("Lose", 120, 1600, 900);
	game.Start("Map", 120, 1600, 900);
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
	// Floor 
	game.Start("ElevatorFloor", 120, 1600, 900);
	game.Start("Factory", 120, 1600, 900);
	game.Start("CraftingTable", 120, 1600, 900);
	// Ground
	game.Start("Home", 120, 1600, 900);
	game.Start("House", 120, 1600, 900);
	game.Start("Road", 120, 1600, 900);
	return 0;
}
