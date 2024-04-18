#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Graphics.h"
#include "ammo.h"
#include "Bot.h"

struct Player
{
    SDL_Rect rect;
    int heart = 200;
    bool alive = true;
    int score = 0;

    void initPlayer(Player& player)
    {
        player.rect.w = 75;
        player.rect.h = 75;
        player.rect.x = 200;
        player.rect.y = 400;
    }
    void isLoss()
    {
        rect.w = 0;
        rect.h = 0;
    }
};

#endif // PLAYER_H_INCLUDED
