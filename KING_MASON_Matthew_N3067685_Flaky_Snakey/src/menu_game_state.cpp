#include "../inc/menu_game_state.hpp"
#include <iostream>
MenuGameState::~MenuGameState()
{
}
bool MenuGameState::onCreate()
{
   return true;

}

bool MenuGameState::onDestroy()
{
   return true;
}

void MenuGameState::onEntry()
{
   prg::application.addKeyListener( *this );

}

void MenuGameState::onExit()
{
   prg::application.removeKeyListener( *this );
}

void MenuGameState::onUpdate()
{

}

void MenuGameState::onRender( prg::Canvas& canvas )
{
   const std::string text = "Welcome to Flakey Sankey.";
   const std::string text2 = "Q to play P to pause R to resume and ESC to quit.";
   const std::string text3 = "Green fruit = 1 blue = 2 but yellow = 1/2 ";

    prg::uint text_dims[2];
    prg::Font::LARGE.computePrintDimensions(text_dims,text);
    prg::Font::LARGE.print(canvas,
                prg::application.getScreenWidth() / 2-text_dims[0]/2,
                prg::application.getScreenHeight() / 2-text_dims[1]/2,
                prg::Colour::RED,
                text);
   prg::uint text_dims2[2];
    prg::Font::SMALL.computePrintDimensions(text_dims2,text2);
    prg::Font::SMALL.print(canvas,
                prg::application.getScreenWidth() / 2-text_dims2[0]/2,
                prg::application.getScreenHeight() / 4-text_dims2[1]/2,
                prg::Colour::GREEN,
                text2);
    prg::uint text_dims3[2];
    prg::Font::SMALL.computePrintDimensions(text_dims3,text3);
    prg::Font::SMALL.print(canvas,
                prg::application.getScreenWidth() / 2-text_dims3[0]/2,
                prg::application.getScreenHeight() / 6-text_dims3[1]/2,
                prg::Colour::BLUE,
                text3);

}
bool MenuGameState::onKey( const prg::IKeyEvent::KeyEvent& key_event )
{
   if (key_event.key_state==KeyEvent::KB_DOWN) {
    switch( key_event.key)
    {
    case 'q': case 'Q':
      {
         prg::application.setState( "main_game_state" );
      }
      break;
   case KeyEvent::KB_ESC_KEY:
      {
       prg::application.exit();
      }
      break;
    }
   }
   return true;
}
