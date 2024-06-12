// Animation.cpp
#include "Animation.hpp"

Animation::Animation(const std::vector<ALLEGRO_BITMAP*>& frames, float frameDelay)
    : frames(frames), frameDelay(frameDelay), currentTime(0.0f), currentFrame(0) {}

void Animation::Update(float deltaTime) {
    currentTime += deltaTime;
    if (currentTime >= frameDelay) {
        currentTime = 0.0f;
        currentFrame = (currentFrame + 1) % frames.size();
    }
}

void Animation::Draw(float x, float y, float scale, float rotation) const {
    al_draw_tinted_scaled_rotated_bitmap(frames[currentFrame], al_map_rgba_f(1.0f, 1.0f, 1.0f, 1.0f),
                                         0, 0, x, y, scale, scale, rotation, 0);
}
