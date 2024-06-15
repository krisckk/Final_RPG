// Monster.hpp
#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <allegro5/allegro.h>
#include <string>
#include <vector>

#include "Maincharacter/Animation.hpp"
#include "Engine/Point.hpp"
#include "Engine/Sprite.hpp"
#include "Maincharacter/Maincharacter.hpp"
extern Maincharacter* MC;
class Monster : public Engine::Sprite {
    protected:
        float speed;
        int HP;
        int damage;
        
        Animation idleAnimation;
        Animation LeftFlyAnimation;
        Animation RightFlyAnimation;
        Animation DieAnimation;
        Animation *currentAnimation;
    public:
        Monster(std::string img, float x, float y, float radius, float speed);
        static bool isDead;
        void Update(float deltaTime) override;
        void Draw() const override;
        //void MoveLeft(float deltaTime);
        //void MoveRight(float deltaTime);
        //void Fly(float deltaTime);
        //void Die();
        void DetectMC();
        void Stop();
        //bool CheckCollision(float x, float y, float wallX, float wallY, float wallWidth, float wallHeight);
};

#endif