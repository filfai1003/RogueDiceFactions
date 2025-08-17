#pragma once
#include <string>
#include <unordered_map>
#include <SDL3/SDL.h>

class Tilemap;

class Renderer {
public:
    bool loadTexture(const std::string& id, const std::string& path);
    void drawTexture(const std::string& id, int x, int y, int w, int h);
    void drawTilemap(const Tilemap& map, int tileSize);
    void drawText(const std::string& text, int x, int y);
    bool loadFont(const std::string& path, int size);
private:
    std::unordered_map<std::string, SDL_Texture*> textures;
    SDL_Renderer* sdlRenderer = nullptr;
    TTF_Font* font = nullptr;
};
