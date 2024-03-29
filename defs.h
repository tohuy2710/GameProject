#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 960;
const char* WINDOW_TITLE = "Game";

const char* MENU_BACKGROUND_FILE = "assets2/gameMenuBackground.png";
const char* BACKGROUND_FILE = "assets2/background.jpg";
const char* PLAYER_SPRITE_FILE = "assets2/tests.png";
const char* BOT_SPRITE_FILE = "assets2/bot02Sprite.png";
const char* STONE_01_SPRITE_FILE = "assets2/stone_01.png";
const char* STONE_02_SPRITE_FILE = "assets2/stone_02.png";
const char* STONE_03_SPRITE_FILE = "assets2/stone_03.png";
const char* BUTTON_PLAY_SPRITE_FILE = "assets2/playButtonSprite.png";
const char* BUTTON_HTP_SPRITE_FILE = "assets2/htpButtonSprite.png";
const char* GUIDE_FILE = "assets2/guideTheme.png";
const char* PLAYER_BULLET_FILE = "assets2/player_laser.png";


const int PLAYER_CLIPS[][4] = {
    {  0, 0, 75, 75},
    { 75, 0, 75, 75},
    {150, 0, 75, 75},
    {225, 0, 75, 75},
    {300, 0, 75, 75},
    {375, 0, 75, 75},
    {450, 0, 75, 75},
    {525, 0, 75, 75},
    {600, 0, 75, 75},
    {675, 0, 75, 75},
    {750, 0, 75, 75},
    {825, 0, 75, 75},};

const int BOT_CLIPS[][4] = {
    {  0, 0, 50, 50},
    { 50, 0, 50, 50},
    {100, 0, 50, 50},
    {150, 0, 50, 50},
    {200, 0, 50, 50},
    {250, 0, 50, 50},
    {300, 0, 50, 50},
    {350, 0, 50, 50},};

const int STONE_01_CLIPS[][4] = {
    {  0, 0, 100, 100},
    { 100, 0, 100, 100},
    {200, 0, 100, 100},
    {300, 0, 100, 100},
    {400, 0, 100, 100},
    {500, 0, 100, 100},};

const int BUTTON_PLAY_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

const int BUTTON_HTP_CLIPS[][4] = {
    {  0, 0, 200, 100},
    { 200, 0, 200, 100},};

const int PLAYER_FRAMES = sizeof(PLAYER_CLIPS)/sizeof(int)/4;
const int BOT_FRAMES = sizeof(BOT_CLIPS)/sizeof(int)/4;
const int STONE_01_FRAMES = sizeof(STONE_01_CLIPS)/sizeof(int)/4;
const int BUTTON_PLAY_FRAMES = sizeof(BUTTON_PLAY_CLIPS)/sizeof(int)/4;
const int BUTTON_HTP_FRAMES = sizeof(BUTTON_HTP_CLIPS)/sizeof(int)/4;
#endif // DEFS_H_INCLUDED
