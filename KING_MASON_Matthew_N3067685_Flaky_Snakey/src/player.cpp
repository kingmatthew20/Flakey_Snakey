#include "../inc/player.hpp"
#include <iostream>
#include <prg_interactive.hpp>
using namespace std;
Player::~Player()
{
   while( !snake_positions_.empty() )
   {
    snake_positions_.pop_front();
   }
}

void Player::pushfront( int x, int y )
{

   snake_positions_.push_front(Node( x, y ));

}

void Player::pushback()
{
   int x,y;
   x=snake_positions_.back().pos_x_;
   y=snake_positions_.back().pos_y_;
   snake_positions_.push_back(Node( x, y ));
}

void Player::move_()
{
   switch( direction_ )
   {
   case 0:  // NORTH
    snake_positions_.push_front(Node(front_x,front_y+20));
    break;
   case 1:  // EAST
    snake_positions_.push_front(Node(front_x+20,front_y));
    break;
   case 2:  // SOUTH
    snake_positions_.push_front(Node(front_x,front_y-20));
    break;
   case 3:  // WEST
    snake_positions_.push_front(Node(front_x-20,front_y));
    break;
   }
   if(grow_ == 0)
   {
      snake_positions_.pop_back();
   }
   else
   {
      grow_--;
   }
   front_x=snake_positions_.front().pos_x_;
   front_y=snake_positions_.front().pos_y_;
}
bool Player::collide(Fruit& app, Fruit& app2, Fruit& app3)
{
   front_x=snake_positions_.front().pos_x_;
   front_y=snake_positions_.front().pos_y_;
   if(front_x>app.getX()-16 && front_y>app.getY()-16 &&
      front_x<app.getX()+16 && front_y<app.getY()+16)
    {
      growby(1);
      return true;
    }
   if(front_x>app2.getX()-16 && front_y>app2.getY()-16 &&
      front_x<app2.getX()+16 && front_y<app2.getY()+16)
    {
      growby(2);
      return true;
    }
    int x = snake_positions_.size()/2;
    int y = snake_positions_.size();
   if(front_x>app3.getX()-16 && front_y>app3.getY()-16 &&
      front_x<app3.getX()+16 && front_y<app3.getY()+16)
   {
      for (shrink_ = x; shrink_ < y; shrink_++)
      {
         snake_positions_.pop_back();
      }
      return true;
   }
   return false;
}
void Player::Gamelogic()
{
   front_x=snake_positions_.front().pos_x_;
   front_y=snake_positions_.front().pos_y_;
   if (front_x >= 800 || front_x <= 0 || front_y <= 0 || front_y >= 600)
   {
      prg::application.setState("game_over_state");
   }
}
void Player::draw( prg::Canvas& canvas)
{
   list<Node>::const_iterator iterator_;
   for (iterator_ = snake_positions_.begin(); iterator_ != snake_positions_.end(); ++iterator_)
   {
    canvas.drawCircle(iterator_->pos_x_,iterator_->pos_y_,10,prg::Colour::RED);
   }
}

void Player::setDirection( int direction )
{
   if( direction >= 0 && direction < 4 )
   {
    direction_ = direction;
   }
}

int Player::getDirection()
{
   return direction_;
}
int Player::getX()
{
   return front_x=snake_positions_.front().pos_x_;
}
int Player::getY()
{
   return front_y=snake_positions_.front().pos_y_;
}
// --------------------------------------------------------
// Node Implementation
// --------------------------------------------------------
Node::Node(int x, int y)
{
   pos_x_=x;
   pos_y_=y;
}
