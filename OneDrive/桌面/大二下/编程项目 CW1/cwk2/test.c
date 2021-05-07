#include "grid.h"
#include "unity.h"

#include<stdlib.h>
#include<string.h>

#define DATAFILE "data.txt"

void test_load_data() {
	char *fp = "data.txt";
}

void test_store_data() {
	
}

void test_update_cells() {
	
}

void test_get_neighbours() {
	
}

void test_initialize_grid() {
	
}

void test_get_steps() {
	
}

int main {
	UNITY_BEGIN();
	
	
	//begin test
	RUN_TEST(test_load_data);
	RUN_TEST(test_store_data);
	RUN_TEST(test_update_cells);
	RUN_TEST(test_get_neighbours);
	RUN_TEST(test_initialize_grid);
	RUN_TEST(test_get_steps);
	
	//end test
	return UNITY_END();
}
