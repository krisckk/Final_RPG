#ifndef SHARED_HPP
#define SHARED_HPP
#include <string>
class Shared {
public:
    static int lives;
    static int hunger;
    static int thirst;
    static std::string previosStage;
    static std::string currentStage;
    static void SetLives(int value);
    static void SetHunger(int value);
    static void SetThirst(int value);
};

#endif // SHARED_HPP