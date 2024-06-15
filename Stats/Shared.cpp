#include "Shared.hpp"

int Shared::lives = 3;
int Shared::hunger = 100;
int Shared::thirst = 100;
float Shared::PositionX;
bool Shared::bluePotion = true;
bool Shared::redPotion;
bool Shared::yellowPotion;
std::string Shared::previosStage = "";
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
