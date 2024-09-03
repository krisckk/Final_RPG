#include "Shared.hpp"
#include <vector>
int Shared::lives = 3;
int Shared::hunger = 100;
int Shared::thirst = 100;
float Shared::PositionX;
bool Shared::correct;
bool Shared::bluePotion = true;
bool Shared::redPotion;
bool Shared::yellowPotion;
bool Shared::Gold = true;
bool Shared::Aluminum = true;
bool Shared::Iron = true;
bool Shared::HDLoil = true;
bool Shared::LDLoil;
bool Shared::IDcard;
bool Shared::coin;
bool Shared::wooden_stick;
bool Shared::GoodRocket;
bool Shared::BadRocket1;
bool Shared::BadRocket2;
bool Shared::BadRocket3;
bool Shared::BadRocket4;
bool Shared::BadRocket5;
bool Shared::BadRocket6;
bool Shared::BadRocket7;
bool Shared::HomeLetterOpen;
bool Shared::Achievement_cola;
bool Shared::Achievement_home;
bool Shared::Achievement_myfavorite;
bool Shared::key;
bool Shared::box_opened;
// B4
bool Shared::LabScene;
bool Shared::LibraryScene;
bool Shared::StorageRoom;
bool Shared::ElevatorB4;
// B3
bool Shared::ElevatorB3;
bool Shared::RestRoom;
bool Shared::DiningRoom;
bool Shared::GYMscene;
bool Shared::DataRoom;
// B2
bool Shared::ElevatorB2;
bool Shared::BiologicalLaboratory;
// B1
bool Shared::ElevatorB1;
bool Shared::HardwareRoom;
bool Shared::Office;
bool Shared::ElevatorToFloor;
// Floor
bool Shared::ElevatorFloor;
bool Shared::Factory;
// Ground
bool Shared::Road;
bool Shared::House;
bool Shared::Home;
std::string Shared::previousStage = "";
std::string Shared::currentStage = "";
void Shared::SetLives(int value) {
    lives = value;
}

void Shared::SetHunger(int value) {
    hunger = value;
}

void Shared::SetThirst(int value) {
    thirst = value;
}
