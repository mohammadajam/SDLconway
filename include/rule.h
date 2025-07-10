#ifndef RULE_H
#define RULE_H

#include "grid.h"

/*
 * conway's game of life rules.
 * 1. if a live cell with fewer than two live neighbours dies, as if by underpopulation.
 * 2. if a live cell with two or three live neighbours lives on to the next generation.
 * 3. if a live cell with more than three live neighbours dies, as if by overpopulation.
 * 4. if a dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 */

void calculate_next_generation(Grid* grid);

#endif
