#pragma once
#include "raylib.h"
#include <string>
#include <map>

class TextureManager {
public:
    TextureManager();
    ~TextureManager();

    // Load and store a texture with a key
    void LoadTextureFromFile(const std::string& id, const std::string& filepath);

    // Get a texture by key (throws if missing)
    Texture2D& GetTexture(const std::string& id);

    // Check if a texture is already loaded
    bool HasTexture(const std::string& id) const;

    // Unload a single texture
    void UnloadTexture(const std::string& id);

    // Unload all textures
    void UnloadAll();   

private:
    std::map<std::string, Texture2D> textures;

};