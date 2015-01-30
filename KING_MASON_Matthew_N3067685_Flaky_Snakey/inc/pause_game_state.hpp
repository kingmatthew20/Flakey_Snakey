#pragma once
#if !defined    PAUSE_GAME_STATE_HPP
#define         PAUSE_GAME_STATE_HPP

#include <prg_interactive.hpp>
#include <iostream>
#include <string>
#include "../inc/ai.hpp"
#include "../inc/fruit.hpp"


using namespace prg;

class PauseGameState : public IAppState, public IKeyEvent
{
public:
   // Implements IAppState
   ~PauseGameState();
   bool onCreate();
   bool onDestroy();
   void onEntry();
   void onExit();
   void onUpdate();
   void onRender( prg::Canvas& canvas );
   // Implements IKeyEventPlayer
   bool onKey( const prg::IKeyEvent::KeyEvent& key_event );
   bool appleeaten();
   bool aiMove();
private:
   Ai aisnake_;
   int frame_ = 0;
   int fruit = 1;
   Fruit apple1_;
   Fruit apple2_;
   Fruit badapple_;
};
#endif // PAUSE_GAME_STATE_HPP

