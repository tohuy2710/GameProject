#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}


int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("assets/background/bgr_1.jpg");
    graphics.prepareScene(background);

    SDL_Rect player;
    player.w = 150;
    player.h = 150;
    player.x = 195;
    player.y = 810;

    SDL_Texture* plane = graphics.loadTexture("assets/player/test.png");

    bool quit = 0;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if(e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_d:
                    if(player.x + player.w <= SCREEN_WIDTH)
                    {
                        player.x += 20;
                    }
                    break;
                case SDLK_a:
                    if(player.x >= 0)
                    {
                        player.x -= 20;
                    }
                    break;
                //space
                }
            }
        }
        graphics.prepareScene(background);
        SDL_RenderCopy(graphics.renderer, plane, NULL, &player);
        graphics.presentScene();
    }

    //del
    SDL_DestroyTexture( plane );
    plane = NULL;
    SDL_DestroyTexture( background );
    background = NULL;


    //quit
    graphics.quit();


    return 0;
}
