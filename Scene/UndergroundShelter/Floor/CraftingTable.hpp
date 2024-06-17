#ifndef CRAFTINGTABLE_HPP
#define CRAFTINGTABLE_HPP

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class CraftingTable final : public Engine::IScene {
    private:
        std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
        ALLEGRO_FONT* PoetFont;
        ALLEGRO_FONT* pirulenFont;
        ALLEGRO_BITMAP* GOLD_PIC;
        ALLEGRO_BITMAP* IRON_PIC;
        ALLEGRO_BITMAP* AL_PIC;
        ALLEGRO_BITMAP* OIL_PIC;
    public:
        explicit CraftingTable() = default;
        void Initialize() override;
        void Terminate() override;
        std::string GetName() const override { return "CraftingTable"; }
        void GoldOnClick(int stage);
        void AlOnClick(int stage);
        void IronOnClick(int stage);
        void Oil75OnClick(int stage);
        void Oil95OnClick(int stage);
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
};


#endif
