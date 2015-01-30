#include "../inc/main_game_state.hpp"
#include <iostream>
MainGameState::~MainGameState()
{
}
bool MainGameState::onCreate()
{
   player_.pushfront(110,110);
   player_.pushfront(110,130);
   player_.pushfront(110,150);
   player_.pushfront(110,170);
   aisnake_.pushfront(200,110);
   aisnake_.pushfront(200,130);
   aisnake_.pushfront(200,150);
   aisnake_.pushfront(200,170);
   apple1_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   apple2_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   badapple_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   return true;
}

bool MainGameState::onDestroy()
{
   return true;
}

void MainGameState::onEntry()
{
   prg::application.addKeyListener( *this );
}

void MainGameState::onExit()
{
   prg::application.removeKeyListener( *this );
}

void MainGameState::onUpdate()
{
   aiMove();
   if (frame_ == 12)
   {
      player_.move_();
      aisnake_.move_();
      frame_ = 0;
   }
   frame_++;
   if (player_.collide(apple1_, apple2_, badapple_)
     ||aisnake_.collide(apple1_, apple2_, badapple_))
   {
      appleeaten();
      fruit = rand() % 2 + 1;
   }
   if (player_.getX()>aisnake_.getX()-11 && player_.getY()>aisnake_.getY()-11 &&
      player_.getX()<aisnake_.getX()+11 && player_.getY()<aisnake_.getY()+11)
   {
       prg::application.setState("game_over_state");
   }
    //IF SNAKE HAS == POSITIONS TO APPLE
    //cALL APPLE EATEn
}

void MainGameState::onRender( prg::Canvas& canvas )
{
   player_.draw( canvas );
   player_.Gamelogic();
   apple1_.Apple1(canvas);
   apple2_.Apple2( canvas );
   badapple_.Badapple( canvas );
   aisnake_.draw(canvas);
}

bool MainGameState::appleeaten()
{
   //DESTROY APPLE AND CREATE ANOTHER AT A RANDOM POSITION
   apple1_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   apple1_.popback();
   apple2_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   apple2_.popback();
   badapple_.pushfront(rand() % 38 *20 + 20,rand() % 28 * 20 + 20);
   badapple_.popback();
   return false;
}
bool MainGameState::aiMove()
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
bool MainGameState::onKey( const prg::IKeyEvent::KeyEvent& key_event )
{
   if (key_event.key_state==KeyEvent::KB_DOWN) {
    switch( key_event.key)
    {
    case 'w': case 'W':
      if ( player_.getDirection()==2 )
      {

      }
      else
      {
       player_.setDirection(0);
      }
      break;
    case 'd': case 'D':
      if ( player_.getDirection()==3 )
      {

      }
      else
      {
       player_.setDirection(1);
      }
      break;
    case 's': case 'S':
      if ( player_.getDirection()==0 )
      {

      }
      else
      {
       player_.setDirection(2);
      }
      break;
    case 'a': case 'A':
      if ( player_.getDirection()==1 )
      {

      }
      else
      {
       player_.setDirection(3);
      }
      break;
    case 'p': case 'P':
      {
         prg::application.setState( "pause_game_state" );
      }
      break;
   case KeyEvent::KB_ESC_KEY:
      {
       prg::application.exit();
       return false;
      }
      break;
    }
   }
   return true;
}
