// Maincharacter.hpp
#ifndef MAINCHARACTER_HPP
#define MAINCHARACTER_HPP

#include <allegro5/allegro.h>
#include <string>
#include <vector>

#include "Animation.hpp"
#include "Engine/Point.hpp"
#include "Engine/Sprite.hpp"

class Maincharacter : public Engine::Sprite {
protected:
    float speed;
    Animation idleAnimation;
    Animation LeftwalkAnimation;
    Animation RightwalkAnimation;
    Animation ClimbAnimation;
    Animation* currentAnimation;
    
public:
    static bool isDead;
    Maincharacter(std::string img, float x, float y, float radius, float speed);
    int groundY;
    void Update(float deltaTime) override;
    void Draw() const override;
    void MoveLeft(float deltaTime);
    void MoveRight(float deltaTime);
    void ClimbUp(float deltaTime);
    void ClimbDown(float deltaTime);
    void Stop();
    bool CheckCollision(float x, float y, float wallX, float wallY, float wallWidth, float wallHeight);
};

#endif // MAINCHARACTER_HPP
