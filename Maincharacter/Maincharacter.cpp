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
Maincharacter::Maincharacter(std::string img, float x, float y, float radius, float speed, float jumpSpeed, int Lives, int Hunger, int Thirst)
    : Engine::Sprite(img, x, y), speed(speed), jumpSpeed(jumpSpeed), Lives(Lives), Hunger(Hunger), Thirst(Thirst),
      RightidleAnimation({al_load_bitmap("Resource/Images/MCRightStop.png"), al_load_bitmap("Resource/Images/MCRightStop.png")}, 0.2f),
      RightwalkAnimation({al_load_bitmap("Resource/Images/MCRightMove1.png"), al_load_bitmap("Resource/Images/MCRightMove2.png")}, 0.2f),
      LeftidleAnimation({al_load_bitmap("Resource/Images/MCLeftStop.png"), al_load_bitmap("Resource/Images/MCLeftStop.png")}, 0.2f),
      LeftwalkAnimation({al_load_bitmap("Resource/Images/MCLeftMove1.png"), al_load_bitmap("Resource/Images/MCLeftMove2.png")}, 0.1f),
      jumpAnimation({al_load_bitmap("Resource/Images/MCRightStop.png")}, 0.0f),
      currentAnimation(&RightidleAnimation) {
    ALLEGRO_BITMAP* idleFrame1 = al_load_bitmap("Resource/Images/MCRightStop.png");
    ALLEGRO_BITMAP* idleFrame2 = al_load_bitmap("Resource/Images/MCRightStop.png");
    if (!idleFrame1 || !idleFrame2) {
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

    ALLEGRO_BITMAP* jumpFrame = al_load_bitmap("Resource/Images/MCRightStop.png");
    if (!jumpFrame) {
        Engine::LOG(Engine::ERROR) << "Failed to load jump animation frame";
        return;
    }

    RightidleAnimation = Animation({idleFrame1, idleFrame2}, 0.2f);
    RightwalkAnimation = Animation({RightwalkFrame1, RightwalkFrame2}, 0.2f);
    LeftwalkAnimation = Animation({LeftwalkFrame1, LeftwalkFrame2}, 0.2f);
    jumpAnimation = Animation({jumpFrame}, 0.0f);
    currentAnimation = &RightidleAnimation;
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

    // Apply gravity
    //Velocity.y += 50 * deltaTime; // Adjust the gravity value as needed

    // Check if the character is on the ground
    /*
    if (Position.y >= groundY - CollisionRadius) {
        Velocity.y = 0;
        Position.y = groundY - CollisionRadius;
        isGrounded = true;
    }
    */
    Sprite::Update(deltaTime);
    currentAnimation->Update(deltaTime);
}

void Maincharacter::Draw() const {
    currentAnimation->Draw(Position.x, Position.y, 3.0f, Rotation);
}
void Maincharacter::MoveLeft(float deltaTime) {
    Velocity.x = -speed;
    Rotation = 0;
    currentAnimation = &LeftwalkAnimation;
}

void Maincharacter::MoveRight(float deltaTime) {
    Velocity.x = speed;
    Rotation = 0;
    currentAnimation = &RightwalkAnimation;
}
void Maincharacter::Stop(){
    Velocity.x = 0;
    Rotation = 0;
    currentAnimation = &RightidleAnimation;
}

void Maincharacter::Jump() {
    if (isGrounded) {
        Velocity.y = -jumpSpeed;
        isGrounded = false;
        currentAnimation = &jumpAnimation;
    }
}
bool Maincharacter::CheckCollision(float x, float y, float wallX, float wallY, float wallWidth, float wallHeight){

}