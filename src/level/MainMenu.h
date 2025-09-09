#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "raylib.h" 

class MainMenu {
public:
    MainMenu();
    ~MainMenu();

    void InitMenuButtons();

    void Run();

private:

    Renderer render;

    UIButton startButton;
    UIButton exitButton;
};