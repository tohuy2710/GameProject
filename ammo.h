#ifndef AMMO_H_INCLUDED
#define AMMO_H_INCLUDED
#include <bits/stdc++.h>
#include "player.h"
#include "Graphics.h"
using namespace std;

struct Bullet
{
    SDL_Rect rect;
    bool active = true;
    int speed;
};


void initPlayerBullets(Player &player, vector<Bullet> &vectorPlayerBullets)
{
    Bullet playerBullets[3];
    for(int i = 0; i < 3; i++)
    {
        playerBullets[i].rect.w = 4;
        playerBullets[i].rect.h = 10;
        playerBullets[i].speed = 20;
    }
    playerBullets[0].rect.x = player.rect.x + player.rect.w/2 - playerBullets[0].rect.w;
    playerBullets[0].rect.y = player.rect.y;
    playerBullets[1].rect.x = player.rect.x;
    playerBullets[1].rect.y = player.rect.y + 20;
    playerBullets[2].rect.x = player.rect.x + player.rect.w - playerBullets[2].rect.w;
    playerBullets[2].rect.y = player.rect.y + 20;
    for(int i = 0; i < 3; i++)
    {
        vectorPlayerBullets.push_back(playerBullets[i]);
    }
}

#endif // AMMO_H_INCLUDED


