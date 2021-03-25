##ifndef STUDENT_GUARD__H 
#define STUDENT_GUARD__H
#include <stdio.h>
typedef struct Student {
	unsigned int id;
	unsigned int password;
	char *name;
	char *bookname;
	unsigned int tag;
	struct Student *next;
}student;

int store_student(FILE *file);


int load_student(FILE *file);



int registration(Student student);


int remove_student(Student student);





#endif
