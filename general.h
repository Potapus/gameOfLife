#ifndef GENERAL_H
#define GENERAL_H

const char liveCell{'O'};
const char deadCell{' '};
const char bornCell{'N'};
const int maxRow = 48;
const int maxCol = 78;
// Conway's parameters
const int min_neighbours = 2;
const int max_neighbours = 3;
const int min_parents = 3;
const int max_parents = 3;

#endif