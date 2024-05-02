#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "defs.h"


struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;
    int RenderBeat = 1;
    int countBeat = 0;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick()
    {
        countBeat++;
        if(countBeat == RenderBeat)
        {
            currentFrame = (currentFrame + 1) % clips.size();
            countBeat = 0;
        }
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
};

std::pair<int, std::string> getRank(Sprite& rankSrite, int score)
{
    std::pair<int, std::string> res = {0, "None"};

    if(score >= 20 && score < 80)
    {
        res = {1, "Bronze"};
    }
    else if(score >= 80 && score < 150)
    {
        res = {2, "Sliver"};
    }
    else if(score >= 150 && score < 250)
    {
        res = {3, "Platinum"};
    }
    else if(score > 250 && score < 400)
    {
        res = {4, "Diamond"};
    }
    else if(score >= 400 && score < 800)
    {
        res = {5, "Master"};
    }
    else if(score >= 800)
    {
        res = {6, "Legendary"};
    }
    rankSrite.currentFrame = res.first;
    return res;
}

bool customSort(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
    return a.second < b.second;
}

void readRankFile(std::pair<int, std::string>& highScore_rank, std::vector<std::pair<std::string, std::string>>& highScore, Sprite& rankSrite)
{
    std::ifstream file("highScore.csv");
    if(file.is_open())
    {
        for(int i = 0; i < 5; i++)
        {
            std::pair<std::string, std::string> tmp;
            getline(file, tmp.first, ',');
            getline(file, tmp.second);
            highScore.push_back(tmp);
        }
    }
    else
    {
        std::cerr << "error opening 'highScore.csv' to read! \n";
    }

    int highestScore = std::stoi(highScore[0].second);
    highScore_rank = getRank(rankSrite, highestScore);
    rankSrite.currentFrame = highScore_rank.first;
    file.close();
}

void writeRankFile(std::vector<std::pair<std::string, std::string>>& highScore)
{
    auto customSort = [](const std::pair<std::string, std::string> &a, const std::pair<std::string, std::string> &b) {
        return stoi(a.second) > stoi(b.second);
    };

    std::ofstream file("highScore.csv");
    if(file.is_open())
    {
        std::sort(highScore.begin(), highScore.end(), customSort);
        int numRecords = std::min(static_cast<int>(highScore.size()), 5);
        for(int i = 0; i < numRecords; i++)
        {
            file << highScore[i].first << ',' << highScore[i].second << std::endl;
        }
    }
    else
    {
        std::cerr << "error opening 'highScore.csv' to write! \n";
    }
}


struct ScrollingBackground {
    SDL_Texture* texture;
    double scrollingOffset = 0;
    int width, height;

    void setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void scroll(double distance) {
        scrollingOffset += distance;
        if (scrollingOffset >= height) {
            scrollingOffset -= height;
        }
    }
};

struct Graphics {

    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }

	void init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //full screen
        //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

        if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (TTF_Init() == -1)
        {
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
            TTF_GetError());
        }

        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
           logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",
                            Mix_GetError() );
        }

    }

	void prepareScene(SDL_Texture * background)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy( renderer, background, NULL, NULL);
    }

    void presentScene()
    {
        SDL_RenderPresent(renderer);
    }

    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }

    void renderTexture(SDL_Texture *texture, int x, int y, int width, int height, SDL_Renderer* renderer)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w = width;
        dest.h = height;

        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

    void renderTexture(SDL_Texture *texture, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }


    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w = src->w;
        dest.h = src->h;

        SDL_RenderCopy(renderer, texture, src, &dest);
    }

    void renderBackground(const ScrollingBackground& bgr) {
        renderTexture(bgr.texture, 0, bgr.scrollingOffset);
        renderTexture(bgr.texture, 0, bgr.scrollingOffset - bgr.height); // Đổi dấu ở đây
    }


   void renderSprite(int x, int y, const Sprite& sprite) {
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }

    void renderInRect(SDL_Texture* texture, SDL_Rect& rect)
    {
        renderTexture(texture, rect.x, rect.y, rect.w, rect.h, renderer);
    }

    void renderFullscreen(SDL_Texture* texture)
    {
        SDL_Rect rect;
        rect.x = 0; rect.y = 0; rect.w = 540; rect.h = 960;
        renderInRect(texture, rect);
    }

    TTF_Font* loadFont(const char* path, int size)
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
        return gFont;
    }

    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor)
    {
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }

        SDL_FreeSurface( textSurface );
        return texture;
    }

        Mix_Music *loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR,
                "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }

    void play(Mix_Music *gMusic)
    {
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }

     Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR,
               "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
        return gChunk;
    }
    void play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }




    void quit()
    {
        Mix_Quit();
        TTF_Quit();
        IMG_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }


};




#endif // GRAPHICS_H_INCLUDED
