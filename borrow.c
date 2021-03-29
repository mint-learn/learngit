#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "borrow.h"

void insert_borrow(Borrow *head_borr, Borrow *r){
	Borrow *p, *q;

	while (r->id_book != 0) {
		r = (Borrow *)malloc(sizeof(Borrow));
		/*r->next = NULL;
		r->id = id;
		printf("Please input book's title, authors, year, copies\n");
		scanf("%s, %s, %d, %d", &r->title, &r->authors, &r->year, &r->copies);*/
		q = head_borr;
		p = head_borr->next;
		while (q->next != NULL){
			p = p->next;
			q = q->next;
			if (q->next == NULL){
				p = NULL;
				q->next = r;
				r->next = NULL;
				break;
			}
		}

	}
}

void remove_borrow(Borrow *head_borr)
{
	Borrow *p, *q;
	int b;
	p = head_borr;
	q = head_borr->next;
	printf("Please type in book's id that need to delete:");
	scanf("%d", &b);
	while(q != NULL){
		if (q->id_book == b){
			p->next = q->next;
			free(q);
			q = NULL;
		}
		else{
			p = p->next;
			q = q->next;
		}
	}
	if (p == NULL)
		printf("Invalid id\n");
}

int store_borrow(FILE *file, Borrow *head_borr)
{
	if (head_borr != NULL){
		Borrow *p = head_borr->next;
		file= fopen("borrow.txt", "w+");
		if(file != NULL){
			while(p != NULL){
				fprintf(file, "%s\t%d\t%d\n", p->name_stu, p->id_book, p->flag);
				p = p->next;
			}
			fclose(file);
			return 0;//success
		}
		else{
			printf("Failed to open file!\n");
			return 1;//fail
		}
	}
}

int load_borrow(FILE *file, Borrow *head_borr){
	file = fopen("borrow.txt", "a+");
	Borrow *p;
	if(file != NULL){
		while (fscanf(file, "%s\t%d\t%d\n", p->name_stu, p->id_book, p->flag) != EOF)
		{
			insert_borrow(head_borr, p);
		}
		fclose(file);
		return 0;
	}
	else{
		printf("Failed to open file!\n");
		return 1;
	}
}

void return_borrow(Borrow *head_borr, int id_book){
	Borrow *p, *q;
	FILE* file; 
	while (id_book != 0) {
		/*r->next = NULL;
		r->id = id;
		printf("Please input book's title, authors, year, copies\n");
		scanf("%s, %s, %d, %d", &r->title, &r->authors, &r->year, &r->copies);*/
		q = head_borr;
		p = head_borr->next;
		while (q != NULL){
			p = p->next;
			q = q->next;
			if (id_book == q->id_book && q->flag == 1){
				q->flag = 0;
				store_borrow(file, head_borr);
				break;
			}
		}

	}
}

int search_borrow(Borrow *head_borr, int id_book, char *name){
	Borrow *p, *q;
	q = head_borr;
	p = head_borr->next;
	while(q != NULL){
		p = p->next;
		q = q->next;
		if(id_book == q->id_book){
			if(strcmp(q->name_stu, name) == 0 && q->flag == 1)
			return 1;
		}
	}
	return 0;
}

void search_book(Borrow *head_borr, char *name){
	Borrow *p, *q;
	q = head_borr;
	p = head_borr->next;
	while(q != NULL){
		p = p->next;
		q = q->next;
		if(strcmp(q->name_stu, name) == 0 && q->flag == 1){
			printf("%d %s", &q->id_book, &q->name_stu);
		}
	}
	printf("That's all books you borrowed before.\n");
}
