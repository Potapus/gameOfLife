#include "board.h"

int main(int argc, char *argv[])
{
    std::cout << "Conway's game of Life\n";
    std::cout << "Press the return key to display each generation\n";

    std::cin.get();

    board current_generation;

    current_generation.randomize();

    while (true)
    {

        current_generation.draw();

        std::cin.get();

        board next_generation;

        calculate(current_generation, next_generation);

        current_generation.update(next_generation);
    }

    std::cout << "\x1b[" << 0 << ";" << maxRow - 1 << "H";
}
