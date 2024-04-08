#ifndef ONTARGET_H_INCLUDED
#define ONTARGET_H_INCLUDED

#include "Graphics.h"
#include "skill.h"
#include "Bot.h"
#include "player.h"

bool checkCollision(SDL_Rect rectA, SDL_Rect rectB) {
    return (rectA.x < rectB.x + rectB.w &&
            rectA.x + rectA.w > rectB.x &&
            rectA.y < rectB.y + rectB.h &&
            rectA.y + rectA.h > rectB.y);
}



#endif // ONTARGET_H_INCLUDED
