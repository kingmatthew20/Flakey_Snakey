#pragma once
#if !defined   MAIN_GAME_STATE_HPP
#define     MAIN_GAME_STATE_HPP

#include <prg_interactive.hpp>
#include "../inc/player.hpp"
#include "../inc/fruit.hpp"
#include "../inc/ai.hpp"
#include "../inc/pause_game_state.hpp"

using namespace prg;

class MainGameState : public IAppState, public IKeyEvent
{
public:
   // Implements IAppState
   ~MainGameState();
   bool onCreate();
   bool onDestroy();
   void onEntry();
   void onExit();
   void onUpdate();
   void onRender( prg::Canvas& canvas );
   // Implements IKeyEventPlayer
   bool aiMove();
   bool onKey( const prg::IKeyEvent::KeyEvent& key_event );
   bool appleeaten();
   bool snakecol();

private:
   int fruit = 1;
   int frame_ = 0;
   Player player_;
   Fruit apple1_;
   Fruit apple2_;
   Fruit badapple_;
   Ai aisnake_;
   //PauseGameState pause_game_state;
};
#endif // MAIN_GAME_STATE_HPP
