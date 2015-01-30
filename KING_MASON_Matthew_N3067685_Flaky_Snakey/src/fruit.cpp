#include "../inc/fruit.hpp"
using namespace std;
Fruit::~Fruit()
{
   while( !fruit.empty() )
   {
    fruit.pop_front();
   }
}
void Fruit::pushfront( int x, int y )
{

   fruit.push_front(NodeF( x, y ));

   pos_x=x;
   pos_y=y;
}

void Fruit::pushback()
{
   int x,y;
   x=fruit.back().pos_x_;
   y=fruit.back().pos_y_;
   fruit.push_back(NodeF( x, y ));
}
void Fruit::popback()
{
   fruit.pop_back();
}
void Fruit::Apple1(prg::Canvas& canvas)
{
   list<NodeF>::const_iterator iterator_;
   for (iterator_ = fruit.begin(); iterator_ != fruit.end(); ++iterator_)
   {
    canvas.drawCircle(iterator_->pos_x_,iterator_->pos_y_,10,prg::Colour::GREEN);
   }
}
void Fruit::Apple2(prg::Canvas& canvas)
{
   list<NodeF>::const_iterator iterator1_;
   for (iterator1_ = fruit.begin(); iterator1_ != fruit.end(); ++iterator1_)
   {
    canvas.drawCircle(iterator1_->pos_x_,iterator1_->pos_y_,10,prg::Colour::BLUE);
   }
}
void Fruit::Badapple(prg::Canvas& canvas)
{
   list<NodeF>::const_iterator iterator2_;
   for (iterator2_ = fruit.begin(); iterator2_ != fruit.end(); ++iterator2_)
   {
    canvas.drawCircle(iterator2_->pos_x_,iterator2_->pos_y_,10,prg::Colour::YELLOW);
   }
}
NodeF::NodeF(int x, int y)
{
   pos_x_=x;
   pos_y_=y;
}

