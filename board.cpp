#include "board.h"
#include <ctime>

void board::create(int row, int column)
{
    cells[row][column].create();
}

void board::draw()
{

    std::cout << "\x1b[2J";

    for (int row = 0; row < maxRow; ++row)
    {
        for (int column = 0; column < maxCol; ++column)
        {
            cells[row][column].draw(row, column);
        }
    }
}

void board::randomize()
{
    const int factor = 5;
    const int cutoff = RAND_MAX / factor;
    time_t now;
    time(&now);
    srand(now);

    for (int row = 1; row < maxRow; ++row)
    {
        for (int column = 1; column < maxCol; ++column)
        {
            if (rand() / cutoff == 0)
            {
                create(row, column);
            }
        }
    }
}

bool board::will_survive(int row, int column)
{
    if (!cells[row][column].is_alive())
    {
        // There is no cell at this position!
        return false;
    }

    int neighbours = cells[row - 1][column - 1].is_alive() +
                     cells[row - 1][column].is_alive() +
                     cells[row - 1][column + 1].is_alive() +
                     cells[row][column - 1].is_alive() +
                     cells[row][column + 1].is_alive() +
                     cells[row + 1][column - 1].is_alive() +
                     cells[row + 1][column].is_alive() +
                     cells[row + 1][column + 1].is_alive();

    if (neighbours < min_neighbours || neighbours > max_neighbours)
    {
        // Cell has died
        return false;
    }

    // survived
    return true;
}

bool board::will_create(int row, int column)
{
    if (cells[row][column].is_alive())
    {
        // There already is a cell at this position!
        return false;
    }

    int parents = cells[row - 1][column - 1].is_alive() +
                  cells[row - 1][column].is_alive() +
                  cells[row - 1][column + 1].is_alive() +
                  cells[row][column - 1].is_alive() +
                  cells[row][column + 1].is_alive() +
                  cells[row + 1][column - 1].is_alive() +
                  cells[row + 1][column].is_alive() +
                  cells[row + 1][column + 1].is_alive();

    if (parents < min_parents || parents > max_parents)
    {
        // Cannot create a cell here
        return false;
    }

    // If we get here, a new cell can be born
    return true;
}

void board::update(const board &next)
{
    for (int row = 1; row < maxRow; ++row)
    {
        for (int column = 1; column < maxCol; ++column)
        {
            cells[row][column] = next.cells[row][column];
        }
    }
}

// By default, all cells in the next generation are initially dead.
// Calculate which live cells survive to the next generation
// and dead cells are revived in the next generation
void calculate(board &old_generation, board &new_generation)
{
    for (int row = 1; row < maxRow; ++row)
    {
        for (int column = 1; column < maxCol; ++column)
        {

            if (old_generation.will_survive(row, column))
            {
                new_generation.create(row, column);
            }
            else if (old_generation.will_create(row, column))
            {
                new_generation.create(row, column);
            }
        }
    }
}
