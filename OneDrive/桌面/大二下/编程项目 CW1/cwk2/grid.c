#include "grid.h"

#include <stdio.h>

int size;
int space;

int load_data() {
	FILE *file = fopen("data.txt", "r");
	fscanf(file, "%d", size);
	/*if (size >= 0){
		GRID_SIZE = size;//���ж� return 1;	
		}
	else {
		printf("Invalid data 'size'.\n");
		return 1;
	}*/
	fscanf(file, "%c", space);
	for (int i=0; i<GRID_SIZE; i++) {
		for (int j=0; j<GRID_SIZE; j++) {
			grid[i][j] = fgetc(file);
		}
	} 
	fclose(file);
	return 0;
} 

int store_data() {
	FILE *file = fopen("data.txt", "w");
	if (GRID_SIZE >= 0)
	fprintf(file, "%d\n", GRID_SIZE);
	else {
	printf("Invalid data 'GRID_SIZE'.\n");
	return 1;
	}
	for (int i=0; i<GRID_SIZE; i++) {
		for (int j=0; j<GRID_SIZE; j++) {
			fprintf(file, "%d", grid[i][j]);
		}
	}
	fclose(file);
	return 0;
} 

void update_cells() {
	int grid_temp[GRID_SIZE][GRID_SIZE] = { 0 };

	copy_grid(grid, grid_temp);

	for (int y = 0; y < GRID_SIZE; ++y) {
		for (int x = 0; x < GRID_SIZE; ++x) {
			if (x == 0 || y == 0) continue;
			
			int neighbours = get_neighbours(x, y);

			if (grid[y][x] == 1 && (neighbours < 2 || neighbours > 3)) {
				grid_temp[y][x] = 0;
			} else if (grid[y][x] == 0 && neighbours == 3) {
				grid_temp[y][x] = 1;
			}
		}	
	}

	copy_grid(grid_temp, grid);
}

void render_cells(SDL_Renderer *renderer, int paused) {
	for (int y = 0; y < GRID_SIZE; ++y) {
		if (y * CELL_SIZE < camera_y || y * CELL_SIZE > camera_y + 1200) continue; // Culling
		for (int x = 0; x < GRID_SIZE; ++x) {
			if (x * CELL_SIZE < camera_x || x * CELL_SIZE > camera_x + 1500) continue; // Culling
		
			if (grid[y][x] == 1) {
				if (!paused) {
					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				} else {
					SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
				}
				SDL_Rect rect = {(x - GRID_OFFSET) * CELL_SIZE + 1 - camera_x, (y - GRID_OFFSET) * CELL_SIZE + 1 - camera_y, CELL_SIZE - 1, CELL_SIZE - 1};
				SDL_RenderFillRect(renderer, &rect);
			}
		}		
	}
}

int get_neighbours(int x, int y) {
	int neighbours = 0;

	for (int sy = y - 1; sy < y+2; sy++) {
		for (int sx = x - 1; sx < x+2; sx++) {
			if (sx == x && sy == y) continue;

			if (grid[sy][sx] == 1) neighbours++;
		}
	}

	return neighbours;
}

void copy_grid(int src[GRID_SIZE][GRID_SIZE], int dest[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			dest[i][j] = src[i][j];
		}	
	}
}


int initialize_grid() {
	int a = 1;
	int choise;
	int choise1;
	int step;
	while(choise >0) {
		printf("Welcome to Conways' game of life.\n");
		printf("Please choose one way to start your game:\n");
		printf("1. Start with data stored before.\n");
		printf("2. Start with a new universe.\n");
		printf("Press '1' or '2' to continue:");
		scanf("%d", choise);
		if (choise == 1 || choise == 2) {
			switch (choise) {
				case 1:{
					load_data();
				}break;
				case 2:{
					for (int i=0; i<GRID_SIZE; i++) {
						for (int j=0; j<GRID_SIZE; j++) {
							grid[i][j] = 0;
						}
					}
				}break;
			}
			printf("Do you want to set the step(generation) of the game?\n");
			printf("1. Yes\n");
			printf("1. No\n");
			scanf("%d", choise1);
			if (choise1 == 1 || choise1 == 2) {
				switch (choise1) {
					case 1:{
						printf("Type in the step you want to set.\n");
						scanf("%d",step);
						break;
					}
					case 2:{
						break;
					}
				}
			}
		}
		else
		continue;
	}
}
