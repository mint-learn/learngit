
#pragma once

#define GRID_OFFSET 12 // Offset to the left and top of the screen.

#define GRID_SIZE 256
#define CELL_SIZE 16

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <SDL.h>
 
int grid[GRID_SIZE][GRID_SIZE];

int camera_x, camera_y, camera_spd;


int load_data();
int store_data();
int initialize_grid();
int get_steps();

void update_cells();
void render_cells(SDL_Renderer *renderer, int paused);


int get_neighbours();

void copy_grid(int src[GRID_SIZE][GRID_SIZE], int dest[GRID_SIZE][GRID_SIZE]);


