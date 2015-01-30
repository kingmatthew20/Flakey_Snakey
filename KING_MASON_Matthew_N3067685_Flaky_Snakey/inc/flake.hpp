#ifndef FLAKE_HPP
#define FLAKE_HPP

#include <string>
#include <prg_interactive.hpp>
#include <list>

class NodeB;

class Flake
{
   public:
      ~Flake();
      void pushfront(int x, int y);
      void pushback();
      void popback();
      bool empty() const { return flake_.size() == 0; }
      unsigned int size(){ return flake_.size(); }
      void wall(prg::Canvas& canvas);
      int getX() { return pos_x; }
      int getY() { return pos_y; }

   private:
      int pos_x;
      int pos_y;
      std::list<NodeB> flake_;
};
class NodeB
{
   private:
    friend class Flake;
    int pos_x_;
    int pos_y_;

   public:
    NodeB(int x, int y);
    int getX() const
    {
    return pos_x_;
    }
    int getY() const
    {
      return pos_y_;
    }
};
#endif //FLAKE_HPP
