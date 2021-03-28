#ifndef STUDENT_GUARDS__H 
#define STUDENT_GUARDS__H
#include <stdio.h>
typedef struct Student {
	char *email;
	char *password;
	char *name;
	struct Student *next;
}Student;

int store_student(FILE *file, Student *head_book);


int load_student(FILE *file, Student *head_book);






void insert(Student *, Student *);

int login(Student *head);





#endif
