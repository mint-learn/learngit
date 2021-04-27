#pragma once

#define GRID_OFFSET 12 // Offset to the left and top of the screen.

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <SDL.h>

int grid[GRID_SIZE][GRID_SIZE];
int camera_x, camera_y, camera_spd;
int load_data();
int store_data();
int initialize_grid();

void update_cells();
void render_cells(SDL_Renderer *renderer, int paused);

int get_neighbours();


