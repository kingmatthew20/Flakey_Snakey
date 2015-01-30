#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <prg_interactive.hpp>
#include <list>
#include "../inc/fruit.hpp"


using namespace std;

class Node;

class Player
{
   public:
    ~Player();
    void pushfront(int x, int y);
    void pushback();
    bool empty() const
    {
      return snake_positions_.size() == 0;
    }
    unsigned int sizel()
    {
      return snake_positions_.size();
    }
    void setDirection( int direction );
    void Gamelogic();
    void draw( prg::Canvas& canvas );
    void move_();
    bool collide(Fruit& app, Fruit& app2, Fruit& app3);
    int getDirection();
    int getX();
    int getY();
    int growby(int grow)
    {
      grow_ = grow;
      return 0;
    }
    int shrinkby(int shrink)
    {
      shrink_ = shrink;
      return 0;
    }
   private:
    int front_x = 100;
    int front_y = 100;
    int grow_ = 0;
    int shrink_ = 0;
    unsigned int direction_  = 0;
    friend class Ai;
    list<Node> snake_positions_;

};
class Node
{
   public:
    Node(int x, int y);
    int getX() const
    {
    return pos_x_;
    }
    int getY() const
    {
      return pos_y_;
    }

private:
   friend class Player;
   friend class Ai;
   int pos_x_;
   int pos_y_;

};
#endif // PLAYER_H
