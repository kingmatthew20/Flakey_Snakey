#ifndef Fruit_H
#define Fruit_H

#include <string>
#include <prg_interactive.hpp>
#include <cstdlib>
#include <list>
class NodeF;

class Fruit
{
   public:
    ~Fruit();
    void pushfront(int x, int y);
    void pushback();
    bool empty() const
    {
      return fruit.size() == 0;
    }
    unsigned int size()
    {
      return fruit.size();
    }
    void Apple1(prg::Canvas& canvas);
    void Apple2(prg::Canvas& canvas);
    void Badapple(prg::Canvas& canvas);
    void popback();
    int getX() const { return pos_x; }
    int getY() const { return pos_y; }

   private:
    int pos_x = rand() % 800 + 10;
    int pos_y = rand() % 600 + 10;

    std::list<NodeF> fruit;
};
class NodeF
{
   private:
    friend class Fruit;
    int pos_x_;
    int pos_y_;

   public:
    NodeF(int x, int y);
    int getX() const
    {
    return pos_x_;
    }
    int getY() const
    {
      return pos_y_;
    }

};
#endif //Fruit_H
