#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Graphics.h"
#include "defs.h"
#include "ammo.h"
#include "Bot.h"
#include "item.h"
#include "onTarget.h"
#include "scoreTarget.h"


struct Button
{
    SDL_Rect rect;
    bool mouseInButton = 0;
    void initButton(Button &button, Graphics &graphics, SDL_Rect &rct)
    {
        rect = rct;
        button.mouseInButton = 0;
    }

    void initPlay(Button &button, Graphics &graphics)
    {
        SDL_Rect rectPlay;
        rectPlay.x = 170;
        rectPlay.y = 600;
        rectPlay.w = 200;
        rectPlay.h = 100;
        initButton(button, graphics, rectPlay);
    }

    void initHowToPlay(Button &button, Graphics &graphics)
    {
        SDL_Rect rectPlay;
        rectPlay.x = 170;
        rectPlay.y = 700;
        rectPlay.w = 200;
        rectPlay.h = 100;
        initButton(button, graphics, rectPlay);
    }

};

void initMenu(Button &buttonPlay, Button &buttonHowToPlay, Graphics &graphics)
{
    buttonPlay.initPlay(buttonPlay, graphics);
    buttonHowToPlay.initHowToPlay(buttonHowToPlay, graphics);
}

bool inButton(Button &button, Graphics &graphics, int posMouse_x, int posMouse_y)
{
    if(posMouse_x >= button.rect.x && posMouse_x <= button.rect.x + button.rect.w
        && posMouse_y >= button.rect.y && posMouse_y <= button.rect.y + button.rect.h)
    {
        return 1;
    }
    return 0;
}

#endif // BUTTON_H_INCLUDED
