#ifndef GRID_H
#define GRID_H

#include "base.h"
#include <stdbool.h>
#include <string.h>

#define MAX_WIDTH 255
#define MAX_HEIGHT 255

typedef struct {
	u8 width;
	u8 height;
	bool states[MAX_WIDTH][MAX_HEIGHT];

} Grid;

Grid new_grid(u8 width, u8 height);
void reset_grid(Grid* grid);
void set_cell(Grid* grid, u8 x, u8 y);
void reset_cell(Grid* grid, u8 x, u8 y);

#endif
