#ifndef STUDENT_GUARDS__H 
#define STUDENT_GUARDS__H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Student {
	char *email;
	char *password;
	char *name;
	struct Student *next;
}Student;

int store_student(FILE *file, Student *head);


int load_student(FILE *file, Student *head);






void insert(Student *head, Student *r);

int login(Student *head);





#endif
