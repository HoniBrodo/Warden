#pragma once
#include "raylib.h"
#include <string>
#include <map>

class TextureManager {
public:
    TextureManager();
    ~TextureManager();

    // Load and store a texture with a key
    void LoadTexture(const std::string& id, const std::string& filepath);

    // Unload all textures
    void UnloadAll();   

private:
    std::map<std::string, Texture2D> textures;

};