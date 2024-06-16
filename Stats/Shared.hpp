#ifndef SHARED_HPP
#define SHARED_HPP
#include <string>
class Shared {
public:
    static int lives;
    static int hunger;
    static int thirst;
    static float PositionX; 
    static bool redPotion;
    static bool bluePotion;
    static bool yellowPotion;
    static bool Gold;
    static bool Aluminum;
    static bool Iron;
    static bool HDLoil;
    static bool LDLoil;
    static bool IDcard;
    static std::string previosStage;
    static std::string currentStage;
    static void SetLives(int value);
    static void SetHunger(int value);
    static void SetThirst(int value);
};

#endif // SHARED_HPP