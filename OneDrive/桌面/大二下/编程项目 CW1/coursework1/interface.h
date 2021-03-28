#ifndef INTERFACE_GUARDI__H 
#define INTERFACE_GUARDI__H

#include "book_management.h"
#include "student.h"
#include "interface.h"
#include "book_management.c"
#include "borrow.h"
#include "borrow.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void showmenu_1();



void showmenu_2(Book *head_book);

void showmenu_3(Book *head_book);

void shoumenu_4(Book *head_book, Borrow *head_borr);

#endif 
