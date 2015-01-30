#include "../inc/flake.hpp"
using namespace std;
Flake::~Flake()
{
   while( !flake_.empty() )
   {
    flake_.pop_front();
   }
}
void Flake::pushfront( int x, int y )
{

   flake_.push_front(NodeB( x, y ));

   pos_x=x;
   pos_y=y;
}

void Flake::pushback()
{
   int x,y;
   x=flake_.back().pos_x_;
   y=flake_.back().pos_y_;
   flake_.push_back(NodeB( x, y ));

}
void Flake::popback()
{
   flake_.pop_back();
}
void Flake::wall(prg::Canvas& canvas)
{
   list<NodeB>::const_iterator iterator2_;
   for (iterator2_ = flake_.begin(); iterator2_ != flake_.end(); ++iterator2_)
   {
    canvas.drawCircle(iterator2_->pos_x_,iterator2_->pos_y_,10,prg::Colour::MAGENTA);
   }
}
NodeB::NodeB(int x, int y)
{
   pos_x_=x;
   pos_y_=y;
}


