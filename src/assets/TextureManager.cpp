#include "TextureManager.h"
#include <stdexcept>

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {
    UnloadAll();
}

void TextureManager::LoadTextureFromFile(const std::string& id, const std::string& filepath) {
    // this initial check prevents duplicates, .find will return .end if no pair with that id is currently in the map
    if (textures.find(id) == textures.end()) {
        Texture2D tex = LoadTexture(filepath.c_str()); 
        if (tex.id == 0) {
            throw std::runtime_error("Failed to load texture: " + filepath); // In raylib, if a texture fails to load, its internal id will be 0, we throw an exception so the game crashes with a clear error message — easier to debug missing files.
        }
        textures[id] = tex; // store in the map
    }
}

Texture2D& TextureManager::GetTexture(const std::string& id) {
    auto it = textures.find(id); // it is just a convention meaning “iterator”
    if (it == textures.end()) {
        throw std::runtime_error("Texture not found: " + id);
    }
    return it->second; // map contains std::pair datd (the id and the value), this is accessing the second part of the pair (the value)
}

bool TextureManager::HasTexture(const std::string& id) const {
    return textures.find(id) != textures.end();
}

void TextureManager::UnloadTexture(const std::string& id) {
    auto it = textures.find(id);
    if (it != textures.end()) {
        ::UnloadTexture(it->second);
        textures.erase(it);
    }
}

void TextureManager::UnloadAll() {
    for (auto& pair : textures) {
        ::UnloadTexture(pair.second);
    }
    textures.clear();
}