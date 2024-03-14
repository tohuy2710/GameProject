#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class item
{
public:
    SDL_Texture* texture;
    SDL_Rect rect;
    bool active = true;
    int speed;

    void initItem(Graphics& graphics, int typeOfItem)
    {
        switch(typeOfItem)
        {
        case 1:

        }
    }
};

#endif // ITEM_H_INCLUDED
