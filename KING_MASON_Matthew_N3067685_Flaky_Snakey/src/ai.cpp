#include "../inc/ai.hpp"
void Ai::aiMove(Fruit& app_)
{
    if (getX() != app_.getX())
    {
         if (getX()>app_.getX())
         {
            setDirection(3);
         }
         if (getX()<app_.getX())
         {
             setDirection(1);
         }
    }
     if (getX() == app_.getX())
     {
         if (getY()>app_.getY())
         {
             setDirection(2);
         }
         if (getY()<app_.getY())
         {
             setDirection(0);
         }
     }
}
void Ai::draw( prg::Canvas& canvas)
{
   list<Node>::const_iterator iteratorA_;
   for (iteratorA_ = snake_positions_.begin(); iteratorA_ != snake_positions_.end(); ++iteratorA_)
   {
    canvas.drawCircle(iteratorA_->pos_x_,iteratorA_->pos_y_,10,prg::Colour::MAGENTA);
   }
}
