#ifndef BOARD_H_
#define BOARD_H_

#include <string>
#include <vector>
#include <cstdlib>

#include "cell.h"

class board
{

  cell cells[maxRow + 2][maxCol + 2];

public:
  void create(int row, int column);

  void draw();

  void randomize();

  // survive
  bool will_survive(int row, int column);

  // born
  bool will_create(int row, int column);

  void update(const board &next);
};

void calculate(board &old_generation, board &new_generation);

#endif
