#include "rule.h"
#include "base.h"
#include "grid.h"

void calculate_next_generation(Grid* grid) {
	int new_states[MAX_WIDTH][MAX_HEIGHT];

	for (u8 i = 0; i < grid->width; i++) {
		for (u8 j = 0; j < grid->height; j++) {
			u8 live_neighbors = 0;
			for (s32 dx = -1; dx <= 1; dx++) {
				for (s32 dy = -1; dy <= 1; dy++) {
					if (dx == 0 && dy == 0) continue;

					s32 ni = (i + dx + grid->width) % grid->width;
					s32 nj = (j + dy + grid->height) % grid->height;
					live_neighbors += grid->states[ni][nj];
				}
			}

			if (grid->states[i][j] == 1) {
				new_states[i][j] = (live_neighbors == 2 || live_neighbors == 3);
			} else {
				new_states[i][j] = (live_neighbors == 3);
			}
		}
	}

	for (u8 i = 0; i < grid->width; i++) {
		for (u8 j = 0; j < grid->height; j++) {
			grid->states[i][j] = new_states[i][j];
		}
	}
}
