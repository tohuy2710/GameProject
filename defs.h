#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 960;
const char* WINDOW_TITLE = "Game";

const char* PLAYER_SPRITE_FILE = "assets/player/player.png";
const int PLAYER_CLIPS[][4] = {
    {  0, 0, 150, 150},
    { 150, 0, 150, 150},
    {300, 0, 150, 150},
    {450, 0, 150, 150},
    {600, 0, 150, 150},
    {750, 0, 150, 150},};
const int PLAYER_FRAMES = sizeof(PLAYER_CLIPS)/sizeof(int)/4;


#endif // DEFS_H_INCLUDED
