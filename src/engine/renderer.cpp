#include "renderer.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>

bool Renderer::loadTexture(const std::string& id, const std::string& path) {
    SDL_Texture* texture = IMG_LoadTexture(sdlRenderer, path.c_str());
    if (!texture) {
        std::cerr << "Failed to load texture: " << path << " SDL_image error: " << SDL_GetError() << std::endl;
        return false;
    }
    textures[id] = texture;
    return true;
}

void Renderer::drawTexture(const std::string& id, int x, int y, int w, int h) {
    auto it = textures.find(id);
    if (it == textures.end()) {
        std::cerr << "Texture ID not found: " << id << std::endl;
        return;
    }
    SDL_FRect dstRect = { static_cast<float>(x), static_cast<float>(y), static_cast<float>(w), static_cast<float>(h) };
    SDL_RenderTexture(sdlRenderer, it->second, nullptr, &dstRect);
}

void Renderer::drawTilemap(const Tilemap& map, int tileSize) {
    // TODO Implement tilemap rendering (stub)
}

void Renderer::drawText(const std::string& text, int x, int y) {
    if (!font) {
        std::cerr << "Font not loaded!" << std::endl;
        return;
    }
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), text.length(), color);
    if (!surface) {
        std::cerr << "Failed to render text surface: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sdlRenderer, surface);
    int texW = surface->w;
    int texH = surface->h;
    SDL_DestroySurface(surface);
    if (!texture) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_FRect dstRect = { static_cast<float>(x), static_cast<float>(y), static_cast<float>(texW), static_cast<float>(texH) };
    SDL_RenderTexture(sdlRenderer, texture, nullptr, &dstRect);
    SDL_DestroyTexture(texture);
}

bool Renderer::loadFont(const std::string& path, int size) {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    font = TTF_OpenFont(path.c_str(), static_cast<float>(size));
    if (!font) {
        std::cerr << "Failed to load font: " << path << " SDL_ttf error: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}
