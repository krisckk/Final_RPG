#ifndef SHARED_HPP
#define SHARED_HPP
#include <string>
#include <vector>
class Shared {
public:
    static int lives;
    static int hunger;
    static int thirst;
    static float PositionX; 
    static bool correct;
    static bool redPotion;
    static bool bluePotion;
    static bool yellowPotion;
    static bool Gold;
    static bool Aluminum;
    static bool Iron;
    static bool HDLoil;
    static bool LDLoil;
    static bool IDcard;
    static bool coin;
    static bool wooden_stick;
    static bool GoodRocket;
    static bool BadRocket1;
    static bool BadRocket2;
    static bool BadRocket3;
    static bool BadRocket4;
    static bool BadRocket5;
    static bool BadRocket6;
    static bool BadRocket7;
    static bool box_opened;
    static bool key;
    static std::string previousStage;
    static std::string currentStage;
    static bool HomeLetterOpen;
    static bool Achievement_cola;
    static bool Achievement_home;
    static bool Achievement_myfavorite;
    // B4
    static bool LabScene;
    static bool LibraryScene;
    static bool StorageRoom;
    static bool ElevatorB4;
    // B3
    static bool ElevatorB3;
    static bool RestRoom;
    static bool DiningRoom;
    static bool GYMscene;
    static bool DataRoom;
    // B2
    static bool ElevatorB2;
    static bool BiologicalLaboratory;
    // B1
    static bool ElevatorB1;
    static bool HardwareRoom;
    static bool Office;
    static bool ElevatorToFloor;
    // Floor
    static bool ElevatorFloor;
    static bool Factory;
    // Ground
    static bool Road;
    static bool House;
    static bool Home;
    static void SetLives(int value);
    static void SetHunger(int value);
    static void SetThirst(int value);
};

#endif // SHARED_HPP
