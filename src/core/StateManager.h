#pragma once

class StateManager {
public:
    StateManager();
    ~StateManager();

    enum class GameState
    {
        DEBUG_WINDOW,
        MAIN_MENU,
        CHARATER_CREATOR,
        PLAYING,
        PAUSED,
        DIALOGUE,
        GAME_OVER
    };

    void SetState(GameState newState) { state = newState; }
    GameState GetState() const { return state; }

private:
    GameState state = GameState::MAIN_MENU;
};