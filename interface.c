#include "interface.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void showmenu_4(Book *head_book, Borrow *head_borr){
	FILE *file;
	int c = 1, choice_3, borrow, year;
	char *search, *name;
	Borrow *borr;
	load_borrow(file, head_borr);
	while(c > 0){
		printf("-------Search and borrow Book-------\n");
		printf("Choose one way to continue:\n");
		printf("1.Search by title.\n");
		printf("2.Search by author.\n");
		printf("3.Search by year.\n");
		printf("0.Exist.\n");
		scanf("%d", &choice_3);
		switch(choice_3){
			case 1:{

				printf("Type in the title of the book:");
				scanf("%s", &search);
				BookArray p = find_book_by_title (search, head_book);
				if(p.length != 0){
					printf("There's 1 book in the libiary:\n");
					printf("%d %s %s %d %d", &p.array->id, &p.array->title, &p.array->authors, &p.array->year, &p.array->copies);
					if(p.array->copies >= 1){
						printf("Press 1 if you want to borrow this book, or press 0 to exist.\n");
						scanf("%d", &borrow);
						if(borrow == 1){
							printf("Please type in your Student name:");
							scanf("%s", &name);
							if(search_borrow(head_borr, p.array->id, name) == 1){
								printf("You have already borrowed this book!\n");
								continue;
							}
							else{
								borr->id_book = p.array->id;
								
								strcpy(borr->name_stu, name);
								borr->flag = 1;
								change_book(head_book, p.array->id, -1);
								store_books(file, head_book);
								insert_borrow(head_borr, borr);
								store_borrow(file, head_borr);
							}
						}
						else
						continue;
						
					}
					else{
						printf("Sorry, the book has already been borrowed.\n");
						continue;
					}
				}
				else{
					printf("Sorry, there's no such book in the libiary!\n");
					continue;
				}
			}
			case 2:{

				printf("Type in the author you want to search:");
				scanf("%s", &search);
				BookArray p = find_book_by_author (search, head_book);
				if(p.length != 0){
					printf("There's %d book written by this author:", &p.length);
					while(p.array->next != NULL){
						printf("%d %s %s %d %d", &p.array->id, &p.array->title, &p.array->authors, &p.array->year, &p.array->copies);
						printf("\n");
						p.array = p.array->next;
					}
					printf("Remember the id and press 1 if you want to borrow book, or press 0 to exist.\n");
					scanf("%d", &borrow);
						if(borrow == 1){
							printf("Please type in your Student name:");
							scanf("%s", &name);
							if(search_borrow(head_borr, p.array->id, name) == 1){
								printf("You have already borrowed this book!\n");
								continue;
							}
							else{
								borr->id_book = p.array->id;
								
								strcpy(borr->name_stu, name);
								borr->flag = 1;
								change_book(head_book, p.array->id, -1);
								store_books(file, head_book);
								insert_borrow(head_borr, borr);
								store_borrow(file, head_borr);
							}
						}
						else
						continue;
				}
				else{
					printf("Sorry, there's no such book in the libiary!\n");
					continue;
				}
			}
			case 3:{

				printf("Type in the year you want to search:");
				scanf("%d", year);
				BookArray p = find_book_by_year (year, head_book);
				if(p.length != 0){
					printf("There's %d book in this year:", &p.length);
					while(p.array->next != NULL){
						printf("%d %s %s %d %d", &p.array->id, &p.array->title, &p.array->authors, &p.array->year, &p.array->copies);
						printf("\n");
						p.array = p.array->next;
					}
					printf("Remember the id and press 1 if you want to borrow book, or press 0 to exist.\n");
					scanf("%d", &borrow);
						if(borrow == 1){
							printf("Please type in your Student name:");
							scanf("%s", &name);
							if(search_borrow(head_borr, p.array->id, name) == 1){
								printf("You have already borrowed this book!\n");
								continue;
							}
							else{
								borr->id_book = p.array->id;
								
								strcpy(borr->name_stu, name);
								borr->flag = 1;
								change_book(head_book, p.array->id, -1);
								store_books(file, head_book);
								insert_borrow(head_borr, borr);
								store_borrow(file, head_borr);
							}
						}
						else
						continue;
				}
				else{
					printf("Sorry, there's no such book in the libiary!\n");
					continue;
				}
			}
			case 0:{

				c = -1;
				break;
			}
		}
	}
	
}



void showmenu_1()
{
	printf("-------Welcome-------\n");
	printf("This is the menu of the libary system:\n");
	printf("1.Login to the system as a student.\n");
	printf("2.Register and login as a student.\n");
	printf("3.Login to the system as the administrator.\n");
	printf("0.Exist.\n");
}



void showmenu_2(Book *head_book, Student *head, Borrow *head_borr){
	int b = 1, choice_2;
	FILE *file;
	while(b > 0){
		printf("-------Welcome-------\n");
		printf("System provides the following functions for students.\n");
		printf("1.View all books.\n");
		printf("2.Serch and borrow book.\n");
		printf("3.Return book.\n");
		printf("4.View books you borrowed.\n");
		printf("0.Logout.\n");
		scanf("%d", &choice_2);
		load_books(file, head_book);
		load_student(file, head);
		switch(choice_2){
			case 1:{

				Book *p = head_book;
				printf("id \t title \t authors \t year \t copies");
				while(p->next != NULL){
					p = p->next;
					printf("%d %s %s %d %d", &p->id, &p->title, &p->authors, &p->year, &p->copies);
					printf("\n");
				}
				continue;
			}
			case 2:{
				showmenu_4(head_book, head_borr);
			}
			case 3:{
				int id;
				char *name;
				printf("Please type in your book id:");
				scanf("%d", id);
				printf("\n");
				printf("Please type in your username:");
				scanf("%s", name);
				if(search_borrow(head_borr, id, name) == 1){
					printf("Sorry, you had not borrow this book!\n");
					continue;
				}
				else{
					return_borrow(head_borr, id);
					continue;
				}
				
			}
				
			
			
			case 4:{
				char *name;
				printf("Please enter your username:");
				scanf("%s", name);
				search_book(head_borr, name);
				continue;
			}
				
				
				
			case 0:{

				b = -1;
				break;
			}
		}
		}
}

void showmenu_3(Book *head_book, Student *head){
	int d = 1, choice_4;
	FILE *file;
	while(d > 0){
		printf("-------Welcome-------\n");
		printf("System provides the following functions for administrator.\n");
		printf("1.Insert book.\n");
		printf("2.Delete book.\n");
		printf("3.Show users who borrow books and havenot return.\n");
		printf("0.Logout.\n");
		load_books(file, head_book);
		load_student(file, head);
		scanf("%d", &choice_4);
		switch(choice_4){
			case 1:{
				int d_1 = 1, d_2;
				while (d_1 > 0){
					Book *in;
					in = (Book *)malloc(sizeof(Book));
					in->title = (char*)malloc(sizeof(char)*50);
					in->authors = (char*)malloc(sizeof(char)*50);
				
					printf("please input id title authors year copies:\n");
					scanf("%d", &in->id);
					scanf("%s", in->title);
					scanf("%s", in->authors);
					scanf("%d", &in->year);
					scanf("%d", &in->copies);
					insert_book(head_book, in);
					free(in);
					printf("Press 1 to continue insert, or press 0 to exist.\n");
					scanf("%d", &d_2);
					if(d_2 == 1){
						continue;
					}
					else if(d_2 == 0){
						d = -1;
						store_books(file, head_book);
						break;
					}
				}
				
				////////save
			}
			break;
			case 2:{
				int d_1, d_2;
				d_1 = 1;
				while (d_1 > 0){
					remove_book(head_book);
					printf("Press 1 to continue insert, or press 0 to exist.\n");
					scanf("%d", &d_2);
					if(d_2 == 1){
						continue;
					}
					else{
						d = -1;
						store_books(file, head_book);
						break;
					}
				}
			}
		case 3:{
			break;////users
		}
		case 0:{
			break;
		}
				
		}
	}
}




