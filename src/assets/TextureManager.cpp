#include "TextureManager.h"
#include <stdexcept>

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {
    UnloadAll();
}

void TextureManager::LoadTexture(const std::string& id, const std::string& filepath) {
    if (textures.find(id) == textures.end()) {
        Texture2D tex = ::LoadTexture(filepath.c_str());
        if (tex.id == 0) {
            throw std::runtime_error("Failed to load texture: " + filepath);
        }
        textures[id] = tex;
    }
}

void TextureManager::UnloadAll() {
    for (auto& pair : textures) {
        ::UnloadTexture(pair.second);
    }
    textures.clear();
}