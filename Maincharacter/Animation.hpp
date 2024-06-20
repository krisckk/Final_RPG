// Animation.hpp
#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <allegro5/allegro.h>

class Animation {
public:
    Animation(const std::vector<ALLEGRO_BITMAP*>& frames, float frameDelay);
    void Update(float deltaTime);
    void Draw(float x, float y, float scale = 1.0f, float rotation = 0.0f) const;

private:
    std::vector<ALLEGRO_BITMAP*> frames;
    float frameDelay;
    float currentTime;
    int currentFrame;
};

#endif // ANIMATION_HPP
