#ifndef AI_HPP
#define AI_HPP

#include <string>
#include <prg_interactive.hpp>
#include <list>
#include <string>
#include "../inc/player.hpp"
#include "../inc/fruit.hpp"

using namespace std;

class NodeA;

class Ai : public Player
{
   public:
    void aiMove(Fruit& app);
    void draw( prg::Canvas& canvas);

   private:
     friend class Player;
};

class NodeA : public Node
{
   public:

   private:
   friend class Node;
    friend class Ai;
};
#endif // AI_HPP
