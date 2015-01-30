#pragma once
#if !defined   MENU_GAME_STATE_HPP
#define     MENU_GAME_STATE_HPP

#include <prg_interactive.hpp>
#include <String>
#include "../inc/main_game_state.hpp"
using namespace prg;

class MenuGameState : public IAppState, public IKeyEvent
{
public:
   // Implements IAppState
   ~MenuGameState();
   bool onCreate();
   bool onDestroy();
   void onEntry();
   void onExit();
   void onUpdate();
   void onRender( prg::Canvas& canvas );
   // Implements IKeyEventPlayer
   bool onKey( const prg::IKeyEvent::KeyEvent& key_event );

private:
   MainGameState main_game_state;
};
#endif // MENU_GAME_STATE_HPP

