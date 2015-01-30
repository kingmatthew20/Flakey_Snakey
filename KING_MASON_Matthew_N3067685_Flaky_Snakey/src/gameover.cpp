#include "../inc/gameover.hpp"
#include <iostream>
GameOverState::~GameOverState()
{
}
bool GameOverState::onCreate()
{
   return true;

}

bool GameOverState::onDestroy()
{
   return true;
}

void GameOverState::onEntry()
{
   prg::application.addKeyListener( *this );

}

void GameOverState::onExit()
{
   prg::application.removeKeyListener( *this );
}

void GameOverState::onUpdate()
{

}

void GameOverState::onRender( prg::Canvas& canvas )
{
   const std::string text = "GAME OVER!";

    prg::uint text_dims[2];
    prg::Font::MASSIVE.computePrintDimensions(text_dims,text);
    prg::Font::MASSIVE.print(canvas,
                prg::application.getScreenWidth() / 2-text_dims[0]/2,
                prg::application.getScreenHeight() / 2-text_dims[1]/2,
                prg::Colour::RED,
                text);
}
bool GameOverState::onKey( const prg::IKeyEvent::KeyEvent& key_event )
{
   if (key_event.key_state==KeyEvent::KB_DOWN) {
    switch( key_event.key)
   case KeyEvent::KB_ESC_KEY:
      {
       prg::application.exit();
       break;
      }
    }
   return true;
}

