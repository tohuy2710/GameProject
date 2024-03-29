#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

struct item
{
    SDL_Rect rect;
    bool active = true;

    void initStone(item& stone, int x, int y)
    {
        stone.rect.x = x;
        stone.rect.y = y;
        stone.rect.w = 100;
        stone.rect.h = 100;
    }
    void stone_moving()
    {
        rect.y += 5;
    }
};

#endif // ITEM_H_INCLUDED
