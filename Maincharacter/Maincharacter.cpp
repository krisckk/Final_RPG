#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>

#include "Engine/AudioHelper.hpp"
#include "UI/Animation/DirtyEffect.hpp"
#include "UI/Animation/ExplosionEffect.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/Group.hpp"
#include "Engine/IScene.hpp"
#include "Engine/LOG.hpp"
#include "Maincharacter.hpp"
bool isGrounded;
bool Maincharacter::isDead = false;
Maincharacter::Maincharacter(std::string img, float x, float y, float radius, float speed)
    : Engine::Sprite(img, x, y), speed(speed),
        idleAnimation({al_load_bitmap("Resource/Images/MCidleStop.png")}, 0.2f),
        RightwalkAnimation({al_load_bitmap("Resource/Images/MCRightMove1.png"), al_load_bitmap("Resource/Images/MCRightMove2.png")}, 0.2f),
        LeftwalkAnimation({al_load_bitmap("Resource/Images/MCLeftMove1.png"), al_load_bitmap("Resource/Images/MCLeftMove2.png")}, 0.1f),
        ClimbAnimation({al_load_bitmap("Resource/Images/MCClimbmove1.png"), al_load_bitmap("Resource/Images/MCClimbmove2.png")}, 0.1f),
        currentAnimation(&idleAnimation) {
    ALLEGRO_BITMAP* idleFrame = al_load_bitmap("Resource/Images/MCidleStop.png");
    if (!idleFrame) {
        Engine::LOG(Engine::ERROR) << "Failed to load idle animation frames";
        return;
    }
    ALLEGRO_BITMAP* RightwalkFrame1 = al_load_bitmap("Resource/Images/MCRightMove1.png");
    ALLEGRO_BITMAP* RightwalkFrame2 = al_load_bitmap("Resource/Images/MCRightMove2.png");
    if (!RightwalkFrame1 || !RightwalkFrame2) {
        Engine::LOG(Engine::ERROR) << "Failed to load Rightwalk animation frames";
        return;
    }
    ALLEGRO_BITMAP* LeftwalkFrame1 = al_load_bitmap("Resource/Images/MCLeftMove2.png");
    ALLEGRO_BITMAP* LeftwalkFrame2 = al_load_bitmap("Resource/Images/MCLeftMove1.png");
    if (!LeftwalkFrame1 || !LeftwalkFrame2) {
        Engine::LOG(Engine::ERROR) << "Failed to load Left walk animation frames";
        return;
    }

    ALLEGRO_BITMAP* ClimbFrame1 = al_load_bitmap("Resource/Images/MCClimbmove1.png");
    ALLEGRO_BITMAP* ClimbFrame2 = al_load_bitmap("Resource/Images/MCClimbmove2.png");
    if (!ClimbFrame1 ||!ClimbFrame2) {
        Engine::LOG(Engine::ERROR) << "Failed to load Climb animation frame";
        return;
    }

    idleAnimation = Animation({idleFrame}, 0.2f);
    RightwalkAnimation = Animation({RightwalkFrame1, RightwalkFrame2}, 0.2f);
    LeftwalkAnimation = Animation({LeftwalkFrame1, LeftwalkFrame2}, 0.2f);
    ClimbAnimation = Animation({ClimbFrame1, ClimbFrame2}, 0.2f);
    currentAnimation = &idleAnimation;
    CollisionRadius = radius;
    bmp = std::shared_ptr<ALLEGRO_BITMAP>(al_load_bitmap(img.c_str()), al_destroy_bitmap);
}

void Maincharacter::Update(float deltaTime) {
    float remainSpeed = speed * deltaTime;
    //Rotation = atan2(Velocity.y, Velocity.x);
    // Check for collisions with walls or obstacles
    float newX = Position.x + Velocity.x * deltaTime;
    float newY = Position.y + Velocity.y * deltaTime;
    // Update position
    Position.x = newX;
    Position.y = newY;
    Sprite::Update(deltaTime);
    currentAnimation->Update(deltaTime);
}

void Maincharacter::Draw() const {
    currentAnimation->Draw(Position.x, Position.y, 3.0f, Rotation);
}
void Maincharacter::MoveLeft(float deltaTime) {
    if(Position.x > 0){
        Velocity.x = -speed;
        Rotation = 0;
        currentAnimation = &LeftwalkAnimation;
    }
    
}

void Maincharacter::MoveRight(float deltaTime) {
    if(Position.x < 1600){
        Velocity.x = speed;
        Rotation = 0;
        currentAnimation = &RightwalkAnimation;
    }
    
}
void Maincharacter::Stop(){
    Velocity.x = 0;
    Velocity.y = 0;
    Rotation = 0;
    currentAnimation = &idleAnimation;
}

void Maincharacter::ClimbUp(float deltaTime){
    Velocity.y = -speed;
    currentAnimation = &ClimbAnimation;
}
void Maincharacter::ClimbDown(float deltaTime){
    Velocity.y = speed;
    currentAnimation = &ClimbAnimation;
}
bool Maincharacter::CheckCollision(float x, float y, float wallX, float wallY, float wallWidth, float wallHeight){

}