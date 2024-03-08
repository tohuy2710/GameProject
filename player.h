#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Graphics.h"
#include "ammo.h"
#include "Bot.h"

class Player
{
public:
    SDL_Texture* texture;
    SDL_Rect rect;
    int hp = 100;
    bool alive = true;

    void initPlayer(Player& player, Graphics& graphics)
    {
        player.texture = graphics.loadTexture("assets/player/test.png");
        player.rect.w = 150;
        player.rect.h = 150;
    }
    void skillJ(Graphics& graphics)
    {
        SDL_Texture* jSkillTexture = graphics.loadTexture("assets/player/j.png");
        SDL_Rect jSkillRect;
        jSkillRect.y = rect.y - 20;
        jSkillRect.w = SCREEN_WIDTH;
        jSkillRect.h = 20;
        graphics.renderTexture(jSkillTexture, 0, jSkillRect.y, jSkillRect.w, jSkillRect.h, graphics.renderer);

    }
    void isLoss()
    {
        texture = NULL;
        rect.w = 0;
        rect.h = 0;
    }


};

#endif // PLAYER_H_INCLUDED
