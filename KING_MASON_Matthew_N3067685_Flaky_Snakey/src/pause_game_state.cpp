#include "../inc/pause_game_state.hpp"
#include <iostream>
PauseGameState::~PauseGameState()
{
}
bool PauseGameState::onCreate()
{
   aisnake_.pushfront(200,110);
   aisnake_.pushfront(200,130);
   aisnake_.pushfront(200,150);
   aisnake_.pushfront(200,170);
   apple1_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   apple2_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
    return true;
}

bool PauseGameState::onDestroy()
{
    return true;
}

void PauseGameState::onEntry()
{
    prg::application.addKeyListener( *this );
}

void PauseGameState::onExit()
{
    prg::application.removeKeyListener( *this );
}

void PauseGameState::onUpdate()
{
   aiMove();
   if (frame_ == 6)
   {
      aisnake_.move_();
      frame_ = 0;
   }
   frame_++;
   if (aisnake_.collide(apple1_, apple2_, badapple_))
   {
    appleeaten();
    fruit = rand() % 2 + 1;
   }
}

void PauseGameState::onRender( prg::Canvas& canvas )
{
    aisnake_.draw( canvas );
    apple1_.Apple1( canvas );
    apple2_.Apple2( canvas );
   const std::string text = "PAUSED R to resume and ESC to quit.";

    prg::uint text_dims[2];
    prg::Font::LARGE.computePrintDimensions(text_dims,text);
    prg::Font::LARGE.print(canvas,
                prg::application.getScreenWidth() / 2-text_dims[0]/2,
                prg::application.getScreenHeight() / 2-text_dims[1]/2,
                prg::Colour::RED,
                text);
}

bool PauseGameState::appleeaten()
{
    //DESTROY APPLE AND CREATE ANOTHER AT A RANDOM POSITION
   apple1_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   apple1_.popback();
   apple2_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   apple2_.popback();
   return false;
}
bool PauseGameState::aiMove()
{
     if(fruit == 1)
   {
        aisnake_.aiMove(apple1_);
   }
   else if (fruit == 2)
   {
        aisnake_.aiMove(apple2_);
   }
   return true;
}
bool PauseGameState::onKey( const prg::IKeyEvent::KeyEvent& key_event )
{
     if (key_event.key_state==KeyEvent::KB_DOWN) {
        switch( key_event.key)
        {
        case 'r': case 'R':
            {
               prg::application.setState("main_game_state");
            }
            break;
        case KeyEvent::KB_ESC_KEY:
                prg::application.exit();
            break;
        }
     }
    return true;
}
