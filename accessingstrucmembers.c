#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main() {
    struct Books book1;
    struct Books book2;

    strcpy(book1.title, "C PROGRAMMING");
    strcpy(book1.author, "balguruswami");
    strcpy(book1.subject, "Programming Language");
    book1.book_id = 67892;

    strcpy(book2.title, "OOPS");
    strcpy(book2.author, "balguruswami");
    strcpy(book2.subject, "Object Oriented Programming");
    book2.book_id = 1234;

    printf("Book 1: \n");
    printf("Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Subject: %s\n", book1.subject);
    printf("Book ID: %d\n\n", book1.book_id);

    printf("Book 2: \n");
    printf("Title: %s\n", book2.title);
    printf("Author: %s\n", book2.author);
    printf("Subject: %s\n", book2.subject);
    printf("Book ID: %d\n", book2.book_id);

    return 0;
}
