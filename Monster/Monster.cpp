#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/IScene.hpp"
#include "Engine/LOG.hpp"
#include "Maincharacter/Maincharacter.hpp"
#include "Monster.hpp"
#include "Stats/Shared.hpp"
bool Monster::isDead = false;
Monster::Monster(std::string img, float x, float y, float radius, float speed)
    : Engine::Sprite(img, x, y), speed(speed),
    RightFlyAnimation({al_load_bitmap("Resource/images/Monster/fly/RightFly1.png"), al_load_bitmap("Resource/images/Monster/fly/RightFly2.png")}, 0.2f),
    LeftFlyAnimation({al_load_bitmap("Resource/images/Monster/fly/LeftFly1.png"), al_load_bitmap("Resource/images/Monster/fly/LeftFly2.png")}, 0.2f),
    idleAnimation({al_load_bitmap("Resource/images/Monster/idle/idle_1.png")}, 0.2f),
    DieAnimation({al_load_bitmap("Resource/images/Monster/death/death_6.png")}, 0.2f),
    currentAnimation(&idleAnimation) {

    ALLEGRO_BITMAP* idleFrame = al_load_bitmap("Resource/images/Monster/idle/idle_1.png");
    if (!idleFrame) {
        Engine::LOG(Engine::ERROR) << "Failed to load idle animation frames";
        return;
    }
    ALLEGRO_BITMAP* RightFlyFrame1 = al_load_bitmap("Resource/images/Monster/fly/RightFly1.png");
    ALLEGRO_BITMAP* RightFlyFrame2 = al_load_bitmap("Resource/images/Monster/fly/RightFly2.png");
    if (!RightFlyFrame1 || !RightFlyFrame2) {
        Engine::LOG(Engine::ERROR) << "Failed to load Right fly animation frames";
        return;
    }
    ALLEGRO_BITMAP* LeftFlyFrame1 = al_load_bitmap("Resource/images/Monster/fly/LeftFly1.png");
    ALLEGRO_BITMAP* LeftFlyFrame2 = al_load_bitmap("Resource/images/Monster/fly/LeftFly2.png");
    if (!LeftFlyFrame1 || !LeftFlyFrame2) {
        Engine::LOG(Engine::ERROR) << "Failed to load Left fly animation frames";
        return;
    }
    ALLEGRO_BITMAP* DieFrame = al_load_bitmap("Resource/images/Monster/death/death_6.png");
    if (!DieFrame) {
        Engine::LOG(Engine::ERROR) << "Failed to load Die animation frames";
        return;
    }
    // Set the sprite's animation
    idleAnimation = Animation({idleFrame}, 0.2f);
    RightFlyAnimation = Animation({RightFlyFrame1, RightFlyFrame2}, 0.2f);
    LeftFlyAnimation = Animation({LeftFlyFrame1, LeftFlyFrame2}, 0.2f);
    DieAnimation = Animation({DieFrame}, 0.2f);
    CollisionRadius = radius;
    bmp = std::shared_ptr<ALLEGRO_BITMAP>(al_load_bitmap(img.c_str()), al_destroy_bitmap);
}
void Monster::Update(float deltaTime) {
    DetectMC();
    if (currentAnimation != &idleAnimation && !isDead) {
        // Update the position while flying towards the Maincharacter
        Position.x += Velocity.x * deltaTime;
    }
    // Update the animation
    Sprite::Update(deltaTime);
    currentAnimation->Update(deltaTime);
}

void Monster::Draw() const {
    currentAnimation->Draw(Position.x, Position.y, 3.0f, Rotation);
}
void Monster::DetectMC()
{
    // Get the position of the Maincharacter
    Engine::Point mcPosition = MC->Position;

    // Calculate the distance between the Monster and the Maincharacter
    float distance = abs(Position.x - mcPosition.x);

    // If the distance is within a certain range, start flying towards the Maincharacter
    if (!isDead && distance < 1000.0f)
    { // Adjust the range as needed
        // Set the velocity to fly towards the Maincharacter
        Velocity.x = speed * (mcPosition - Position).Normalize().x;
        if (mcPosition.x > Position.x)
            currentAnimation = &RightFlyAnimation; // Set the flying animation
        else
            currentAnimation = &LeftFlyAnimation;
    }
    if (Shared::bluePotion && distance < 200.0f)
    {
        Velocity.x = 0;
        Velocity.y = 0;
        currentAnimation = &DieAnimation;
        isDead = true;
    }
    else if(!Shared::bluePotion && distance < 100.0f){
        Velocity.x = 0;
        Velocity.y = 0;
        currentAnimation = &idleAnimation;
        MC -> isDead = true;
    }
}
void Monster::Stop(){
    Velocity.x = 0;
    Velocity.y = 0;
    Rotation = 0;
    currentAnimation = &idleAnimation;
}