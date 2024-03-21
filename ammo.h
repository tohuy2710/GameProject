#ifndef AMMO_H_INCLUDED
#define AMMO_H_INCLUDED

#include "Graphics.h"

//typeOfBullet: left: 0, q: 1, w = 2, e = 3, r = 4

class Bullet
{
public:
    SDL_Texture* texture;
    SDL_Rect rect;
    bool active = true;
    int speed;

    void initBullet(Bullet& bullet,Graphics& graphics,SDL_Rect& rect, int typeOfBullet);
};

void Bullet::initBullet(Bullet& bullet,Graphics& graphics,SDL_Rect& player, int typeOfBullet)
{

    bullet.active = true;

    switch (typeOfBullet)
    {
    case 0: //for Player
        bullet.texture = graphics.loadTexture("assets/bullet/uet.png");
        bullet.rect.w = 4;
        bullet.rect.h = 20;
        bullet.rect.x = player.x + player.w/2 - bullet.rect.w;
        bullet.rect.y = player.y;
        bullet.speed = 20;
        break;
    case 1: //for Bot
        bullet.texture = graphics.loadTexture("assets/bullet/thunder.png");
        bullet.rect.w = 20;
        bullet.rect.h = 20;
        bullet.rect.x = player.x + player.w/2 - bullet.rect.w;
        bullet.rect.y = player.y + player.h;
        bullet.speed = 20;
        break;
    }


}

#endif // AMMO_H_INCLUDED


