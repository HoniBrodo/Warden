#include "raylib.h"
#include "core/Game.h"

int main() {

    InitWindow(1920, 1080, "Warden"); 

    Game warden;

    warden.Init();
    warden.Run();

    return 0;
}
