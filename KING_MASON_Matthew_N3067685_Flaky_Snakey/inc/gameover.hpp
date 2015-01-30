#pragma once
#if !defined   GAMEOVER_HPP
#define     GAMEOVER_HPP

#include <prg_interactive.hpp>

using namespace prg;

class GameOverState : public IAppState, public IKeyEvent
{
public:
   // Implements IAppState
   ~GameOverState();
   bool onCreate();
   bool onDestroy();
   void onEntry();
   void onExit();
   void onUpdate();
   void onRender( prg::Canvas& canvas );
   // Implements IKeyEventPlayer
   bool onKey( const prg::IKeyEvent::KeyEvent& key_event );

private:

};
#endif // GAMEOVER_HPP
