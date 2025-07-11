#include "grid.h"
#include "base.h"

Grid new_grid(u8 width, u8 height) {
	LOG("Creating a new grid with size (%u, %u)\n", width, height);
	return (Grid) {
		.width = width,
		.height = height
	};
}

void reset_grid(Grid* grid) {
	LOG("Grid got reset\n");
	memset(grid->states, 0, sizeof(int) * MAX_WIDTH * MAX_HEIGHT);
}

void set_cell(Grid* grid, u8 x, u8 y) {
	LOG("Setting cell on (%u, %u)\n", x, y);
	if (x <= grid->width && y <= grid->height) {
		grid->states[x][y] = 1;
	}
}

void reset_cell(Grid* grid, u8 x, u8 y) {
	LOG("Resetting cell on (%u, %u)\n", x, y);
	if (x <= grid->width && y <= grid->height) {
		grid->states[x][y] = 0;
	}
}
