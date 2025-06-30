#include "grid.h"

Grid new_grid(u8 width, u8 height) {
	LOG("Creating a new grid with size (%u, %u)\n", width, height);
	return (Grid) {
		.width = width,
		.height = height
	};
}

void reset_grid(Grid* grid) {
	LOG("Grid got reset");
	memset(grid->states, 0, sizeof(bool));
}

void set_cell(Grid* grid, u8 x, u8 y) {
	if (x <= grid->width && y <= grid->height) {
		grid->states[x][y] = true;
	}
}

void reset_cell(Grid* grid, u8 x, u8 y) {
	if (x <= grid->width && y <= grid->height) {
		grid->states[x][y] = false;
	}
}
