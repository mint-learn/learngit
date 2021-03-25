#include <stdio.h>
#include "student.h"
extern struct Student* head_student;
head_student = NULL;

registration(Student student){
	Student *p_student;
	int id, password, tag;
	char *name, *bookname;
	int size_student = sizeof(student);
	
	for(student->id != NULL, student->next = student){
		if(student->next == NULL){
			id = student->id + 1;
			break;
		}
	};
	printf("Your student id is:"%d, id);
	printf("\n");
	printf("Please set your username:");
	scanf("%s",&name);
	printf("Please set your password:");
	scanf("%d",&password);
	p_student->id = id;
	strcpy(p_student->name, name);
	p_student->password = password;
	p_student->bookname = NULL;
	p_student->tag = 0;

    head_student = Insert_student(head_student, p_student);
    printf("Successfully registrated.")
    return 0;
}

int Insert_student(struct Student *head_student, Student *new_student){
	Student *p, *q;
	p = q = head_student;
	
	if(head_student == NULL){
		head_student = new_student;
		new_student->next = NULL;
	}
	else{
		while((new_student->id > p->id) && (p->next != NULL)){
			q = p;
			p = p->next;
		}
		if(new_student->id <= p->id){
			new_student->next = p;
			if(head_student == p)
				head_student = new_student;
			else
				q->next = new_student;
		}
		else{
			p->next = new_student;
			new_student->next = NULL;
		}
	}
	return head_student;
}


