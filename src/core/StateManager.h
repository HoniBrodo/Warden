#pragma once
#include <memory>
#include "../player/Player.h"

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

    void SetPlayer(std::unique_ptr<Player> player) { m_player = std::move(player); }
    Player* GetPlayer() { return m_player.get(); }
    bool HasPlayer() const { return m_player != nullptr; }

    void SetState(GameState newState) { state = newState; }
    GameState GetState() const { return state; }

private:
    GameState state = GameState::MAIN_MENU;
    std::unique_ptr<Player> m_player;
};