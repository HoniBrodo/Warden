#pragma once
#include <string>
#include "../core/Renderer.h"
#include "../ui/UIButton.h"
#include "raylib.h" 

class MainMenu {
public:
    MainMenu();
    ~MainMenu();

    void InitMenuButtons(Renderer& renderRef);
    void Run(Renderer& renderRef);

private:

    UIButton startButton;
    UIButton exitButton;
};