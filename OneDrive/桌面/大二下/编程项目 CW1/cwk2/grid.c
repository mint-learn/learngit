#include "grid.h"

#include <stdio.h>


int size;
int space;

int load_data() {
	//printf("in load\n");
	FILE *file = fopen("data.txt", "r");
	//printf("in file\n");
	fscanf(file, "%d", &size);
	//printf("%d\n", size);
	//printf("in size\n");
	/*if (size >= 0){
		GRID_SIZE = size;//×öÅÐ¶Ï return 1;	
		}
	else {
		printf("Invalid data 'size'.\n");
		return 1;
	}*/
	//printf("in c\n");
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			fscanf(file, "%d", &grid[i][j]);
		}
	}
	
	/*printf("%d\n", size);
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}*/
	fclose(file);
	//printf(" in close\n");
	return size;
} 

int store_data() {
	FILE *file = fopen("data.txt", "w");
	if (size >= 0)
	fprintf(file, "%d\n", size);
	else {
	printf("Invalid data 'SIZE'.\n");
	return 1;
	}
	//printf("%d\n", size);
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			fprintf(file, "%d ", grid[i][j]);
		}
		fprintf(file, "\n");
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

	while(a >0) {
		printf("Welcome to Conways' game of life.\n");
		printf("Please choose one way to start your game:\n");
		printf("1. Start with data stored before.\n");
		printf("2. Start with a new universe.\n");
		printf("Press '1' or '2' to continue:");
		scanf("%d", &choise);
		if (choise == 1) {
			//printf("if\n");
			size = load_data();
		}
		else if (choise == 2) {
			//printf("else if\n");
			for (int i=0; i<size; i++) {
				for (int j=0; j<size; j++) {
					grid[i][j] = 0;
				}
			}
			printf("Please set the size of the universe:\n");
			scanf("%d", &size);
		}
		else
			continue;
		
		
		
		return size;
			
			}
		}


int get_steps() {
	int choise1;
	int step;
	int b = 1;
	while (b>0) {
		printf("Do you want to set the steps(generation)?\n");
		printf("1. Yes.\n");
		printf("2. No.\n");
		scanf("%d", &choise1);
		if (choise1 == 1) {
			printf("Please type in the steps:");
			scanf("%d", &step);
		}	
		else if (choise1 == 2 ) {
			step == 999;
		}
		else
			continue;
		return step;
	}
}
