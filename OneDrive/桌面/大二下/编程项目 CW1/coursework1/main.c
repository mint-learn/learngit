#include "book_management.h"
#include "student.h"
#include "interface.h"
#include "book_management.c"
#include "student.c"
#include "borrow.h"
#include "borrow.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	Book *head_book;
	head_book = (Book *)malloc(sizeof(Book));
	head_book->next = NULL;//head_book

	Student *head;
	head= (Student *)malloc(sizeof(Student));
	head->next = NULL;//head student

	Borrow *head_borr;
	head_borr = (Borrow *)malloc(sizeof(Borrow));
	head_borr->next = NULL;//head borrow

	Student *register1;

	int a = 1, choice, re;
	while(a > 0){
		showmenu_1();
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				re = login(head);
				if(re = 1){
					continue;
				}
				else{
					showmenu_2(head_book);
				}
			}continue;
			case 2:{
				
				char *email, *password, *name;
				printf("input your email(one email adress can regist once.)\n, password(consisting of numbers or characters.)\n, name(consisting of numbers or charactors.)\n");
				scanf("%s, %s, %s", &email, &password, &name);
				strcpy(register1->email, email);
				strcpy(register1->password, password);
				strcpy(register1->name, name);
				insert(head, register1);
				store_books(file, head_book);
				showmenu_2(head_book);
			}
			case 3:{
				char *admin_id, *admin_password;
				printf("Please enter the administrator id:");
				scanf("%s", &admin_id);
				if (admin_id == "administrator"){
					printf("Please enter the administrator password:");
					scanf("%s", admin_password);
					if(admin_password == "administrator"){
						showmenu_3(head_book);
					}
				}
				else{
					printf("This is not a administrator id.\n");
					continue;
				}
			}
			case 0:{

				a = -1;
				break;
			}
	}
}
} 


