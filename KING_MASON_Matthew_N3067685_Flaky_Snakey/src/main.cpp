#include <stdexcept>
#include <iostream>
#include "../inc/menu_game_state.hpp"
#include "../inc/main_game_state.hpp"
#include "../inc/pause_game_state.hpp"
#include "../inc/gameover.hpp"
int main()
{
   try
   {
      MenuGameState menu_game_state;
      MainGameState main_game_state;
      PauseGameState pause_game_state;
      GameOverState game_over_state;

      prg::application.addState( "menu_game_state", menu_game_state );
      prg::application.addState( "main_game_state", main_game_state );
      prg::application.addState( "pause_game_state", pause_game_state );
      prg::application.addState( "game_over_state", game_over_state );
      prg::application.run( 800, 600, "Matthew King-Mason", "n3067685" );
   }
   catch( std::exception& error )
   {
   std::cerr << "An error caused the program to terminate: " << error.what() << std::endl;
   }


   return 0;
}
