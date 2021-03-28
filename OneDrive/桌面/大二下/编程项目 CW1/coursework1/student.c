#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"





void insert(Student *head, Student *r){
	int i, flag = 1;
	Student *p, *q;

	while (r->email != NULL) {
		r = (Student *)malloc(sizeof(Student));
		/*r->next = NULL;
		r->id = id;
		printf("Please input book's title, authors, year, copies\n");
		scanf("%s, %s, %d, %d", &r->title, &r->authors, &r->year, &r->copies);*/
		q = head;
		p = head->next;
		while (q->next != NULL){
			p = p->next;
			q = q->next;
			if (q->next == NULL){
				p = NULL;
				q->next = r;
				r->next = NULL;
				flag = 0;
				break;
			}
		}
		if (flag){
			r->next = p;
			q->next = r;
		}

	}
}

int login(Student *head){
	Student *p;
	char *email, *password, *Password;
	p = head->next;
	printf("Please enter your email:");
	scanf("%s", &email);
	while(p != NULL)
	{
		if(strcmp(p->email, email) == 0){
			strcpy(password, p->password);
			break;
		}
		else{
			p = p->next;
		}
	}
	if(password == NULL){
		printf("Cannot find this email.\n");
		return 1;
	}
	else{
		printf("Please enter your password:");
		scanf("%s", &Password);
		while(password != NULL){
			if(strcmp(password, Password) == 0){
				printf("Successtully login.\n");
				return 0;
			}
			else{
				printf("Password is not correct, please enter again:");
			}
		}
	}
}


/*registration(Student student){
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
}*/
int store_student(FILE *file, Student *head)
{
	if (head != NULL){
		Student *p = head->next;
		file = fopen("student.txt", "w+");
		if(file != NULL){
			while(p != NULL){
				fprintf(file, "%s\t%s\t%s\n", p->email, p->password, p->name);
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

int load_student(FILE *file, Student *head){
	file = fopen("student.txt", "a+");
	Student *p;
	if(file != NULL){
		while (fscanf(file, "%s%s%s", &p->email, &p->password, &p->name) != EOF)
		{
			insert(head, p);
		}
		fclose(file);
		return 0;
	}
	else{
		printf("Failed to open file!\n");
		return 1;
	}
}

