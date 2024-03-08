#ifndef SCORETARGET_H_INCLUDED
#define SCORETARGET_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"
#include "ammo.h"

class ScoreBoard
{
public:
    SDL_Texture* texture;
    SDL_Rect rect;
    long long score = 0;
    bool movingRight = 1;

    void initScoreBoard(Graphics& graphics)
    {
        texture = graphics.loadTexture("assets/item/targetA.png");
        rect.x = 0;
        rect.y = 0;
        rect.w = 200;
        rect.h = 40;
        graphics.renderTexture(texture, rect.x, rect.y, rect.w, rect.h, graphics.renderer);
    }
    void moving()
    {
        if(rect.x > SCREEN_WIDTH - rect.w){
            movingRight = 0;
        }
        else if(rect.x <= 0){
            movingRight = 1;
        }
        if(movingRight)
        {
            rect.x += 3;
        }
        else{
            rect.x -= 3;
        }
    }
    void scoreCount(Bullet &bullet)
    {
        if(checkCollision(bullet.rect, rect))
        {
            int targetOn = abs(bullet.rect.x - rect.x);

            if (targetOn > 100)
            {
                targetOn = 200 - targetOn;
            }

            if (targetOn <= 20)
            {
                score += 1;
            }
            else if (targetOn > 20 && targetOn <= 40)
            {
                score += 3;
            }
            else if (targetOn > 40 && targetOn <= 60)
            {
                score += 5;
            }
            else if (targetOn > 60 && targetOn <= 80)
            {
                score += 7;
            }
            else if (targetOn > 80 && targetOn <= 97)
            {
                score += 9;
            }
            else
            {
                score += 15;
            }
            std::cout << score << std::endl;
            bullet.active = false;
        }
    }
    void scoreReset()
    {
        score = 0;
    }
};

#endif // SCORETARGET_H_INCLUDED
