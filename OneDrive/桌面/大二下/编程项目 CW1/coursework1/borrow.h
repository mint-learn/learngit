#ifndef BORROW_GUARDB__H 
#define BORROW_GUARDB__H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Borrow {
	char *name_stu;
	unsigned int id_book;
	unsigned int flag;
	struct Borrow *next;
}Borrow;

void insert_borrow(Borrow *, Borrow *);

void remove_borrow(Borrow *head_borr);

int store_borrow(FILE *file, Borrow *head_borr);

int load_borrow(FILE *file, Borrow *head_borr);

void return_borrow(Borrow *head_borr, int id_book);

int search_borrow(Borrow *head_borr, int id_book, char *name);

void search_book(Borrow *head_borr, char *name);


#endif
