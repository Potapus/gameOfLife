#ifndef CELL_H_
#define CELL_H_

#include <iostream>

#include "general.h"

class cell
{
  bool alive;

public:
  cell() : alive(false) {}

  void draw(int row, int col) const;

  // Bring cell to life
  void create()
  {
    alive = true;
  }

  // End cell's life
  void erase()
  {
    alive = false;
  }

  bool is_alive() const { return alive; }
};

#endif 
