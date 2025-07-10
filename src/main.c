#include "SDL3/SDL_mouse.h"
#define SDL_MAIN_USE_CALLBACKS 1
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "base.h"
#include "grid.h"
#include "rule.h"

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static Grid grid;

static const u32 SCREEN_WIDTH = 1280;
static const u32 SCREEN_HEIGHT = 720;

static SDL_FRect next_generation_button = {1200, 0, 80, 50};

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
	grid = new_grid(50, 50);

	SDL_SetAppMetadata("SDL Conway", "1.0", "com.conway.game");

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Couldn't Initialize Window %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("SDL Conway", SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
	if (event->key.scancode == SDL_SCANCODE_ESCAPE) {
		return SDL_APP_SUCCESS;
	}

	if (event->button.down) {
		f32 x;
		f32 y;
		SDL_GetMouseState(&x, &y);
		if (x >= next_generation_button.x &&
			x <= next_generation_button.x + next_generation_button.w &&
			y >= next_generation_button.y &&
			y <= next_generation_button.y + next_generation_button.h) {
			calculate_next_generation(&grid);
			return SDL_APP_CONTINUE;
		}
	}

	u8 xcell_count = grid.width;
	u8 ycell_count = grid.height;
	u32 cell_size = (xcell_count > ycell_count) ? (SCREEN_WIDTH-80)/xcell_count:SCREEN_HEIGHT/ycell_count;

	f32 x;
	f32 y;
	SDL_GetMouseState(&x, &y);

	if (event->button.button == SDL_BUTTON_RIGHT) {
		for (int i = 0; i < xcell_count; i++) {
			for (int j = 0; j < ycell_count; j++) {
				if (grid.states[i][j] &&
					(u32)x > cell_size*i &&
					(u32)x < cell_size*i + cell_size &&
					(u32)y > cell_size*j &&
					(u32)y < cell_size*j + cell_size) {
					grid.states[i][j] = 0;
				}
			}
		}
	}

	if (event->button.button == SDL_BUTTON_LEFT) {
		for (int i = 0; i < xcell_count; i++) {
			for (int j = 0; j < ycell_count; j++) {
				if (!grid.states[i][j] &&
					(u32)x > cell_size*i &&
					(u32)x < cell_size*i + cell_size &&
					(u32)y > cell_size*j &&
					(u32)y < cell_size*j + cell_size) {
					grid.states[i][j] = 1;
				}
			}
		}
	}

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	u8 xcell_count = grid.width;
	u8 ycell_count = grid.height;

	u32 cell_size = (xcell_count > ycell_count) ? (SCREEN_WIDTH-80)/xcell_count:SCREEN_HEIGHT/ycell_count;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderRect(renderer, &next_generation_button);

	for (int i = 0; i < xcell_count; i++) {
		for (int j = 0; j < ycell_count; j++) {
			if (grid.states[i][j]) {
				SDL_RenderFillRect(renderer, &(SDL_FRect){cell_size*i, cell_size*j, cell_size, cell_size});
			} else {
				SDL_RenderRect(renderer, &(SDL_FRect){cell_size*i, cell_size*j, cell_size, cell_size});
			}
		}
	}
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    
}
