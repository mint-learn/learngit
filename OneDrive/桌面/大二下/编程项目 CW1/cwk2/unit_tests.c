#include "grid.h"
#include "unity.h"

#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#define DATAFILE "data.txt"




void test_load_data() {
	int a = load_data();
	TEST_ASSERT_EQUAL_INT_MESSAGE (20, a, "Cannot read from data file.");
	
}

void test_store_data() {
	int a = store_data();
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, a, "Cannot read store data to the file.");
}

void test_get_neighbours() {
	int size = 20;
	for (int i=0; i<20;i++){
		for (int j=0; j<20; j++) {
			grid[i][j] = 0;
		}
	}
	grid[1][1] = 1;
	grid[1][2] = 1;
	grid[1][3] = 1;
	grid[2][2] = 1;
	int a = get_neighbours(1, 2);
	int b = get_neighbours(1, 1);
	int c = get_neighbours(5, 5);
	TEST_ASSERT_EQUAL_INT_MESSAGE (3, a, "Cannot get the right neighbours of a cell.");
	TEST_ASSERT_EQUAL_INT_MESSAGE (2, b, "Cannot get the right neighbours of a cell.");
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, c, "Cannot get the right neighbours of a cell.");
}

void test_update_cells() {
	int size = 20;
	for (int i=0; i<20;i++){
		for (int j=0; j<20; j++) {
			grid[i][j] = 0;
		}
	}
	grid[1][3] = 1;
	int a = update_cells();
	int b = grid[1][3];
	
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, a,"Cannot successfully update the grid.");
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, a,"Cannot successfully update a cell.");
	
}


void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();
	//begin test
	RUN_TEST(test_load_data);
	RUN_TEST(test_store_data);
	RUN_TEST(test_get_neighbours);
	RUN_TEST(test_update_cells);
	
	//end test
	return UNITY_END();
}
