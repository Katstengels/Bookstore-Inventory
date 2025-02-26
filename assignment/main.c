#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

typedef struct
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;

void listbook (Book *bk, int size);
int addbook (Book *bk, int size);
int removebook (Book *bk, int size);
void findbook(Book *bk, int size);
void updatebook (Book *bk, int size);

int main(){
    int choose, size =0;
    Book books[MAX];

    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n1: listBooks()\n2: addBook()\n3: removeBook()\n4: findBook()\n5: updateBook()\n6: quit\n");

    do{
        printf("Enter your choice:\n");
        scanf ("%d", &choose);

        switch (choose){
            case 1:
                printf("listBooks():\n");
                listbook(books, size);
                break;
            case 2:
                printf("addBook():\n");
                size = addbook(books, size);
                break;
            case 3:
                printf("removeBook():\n");
                size = removebook(books, size);
                break;
            case 4:
                printf("findBook():\n");
                findbook(books, size);
                break;
            case 5:
                printf("updateBook():\n");
                updatebook(books, size);
                break;
            }
        }while (choose<6);

    return 0;
}


void listbook (Book *bk, int size){
    int i;

    if (size==0)
        printf("The bookshop is empty\n");
    else {
        for (i=0; i<size; i++){
            printf("BookID: %d\n", bk[i].bookID);
            printf("Book title: %s\n", bk[i].title);
            printf("Author name: %s\n", bk[i].author);
            printf("Book price: %.2f\n", bk[i].price);
            printf("Quantity: %d\n", bk[i].quantity);
        }
    }
}


int addbook(Book *bk, int size){
    int i, a, qnt, id;
    char ttl[40], aut[40], *p, dum;
    double pr;
    Book temp;

    printf("Enter bookID:\n");
    scanf("%d", &id);
    scanf("%c", &dum);
    printf("Enter book title:\n");
    fgets(ttl, 40, stdin);
    if (p=strchr(ttl,'\n'))
        *p = '\0';
    printf("Enter author name:\n");
    fgets(aut, 40, stdin);
    if (p=strchr(aut,'\n'))
        *p = '\0';
    printf("Enter price:\n");
    scanf("%lf", &pr);
    scanf("%c", &dum);
    printf("Enter quantity:\n");
    scanf("%d", &qnt);
    scanf("%c", &dum);

    if (size==MAX){
        printf("The bookshop is full! Unable to addBook()\n");
    }
    else {
        for (i=0; i<size; i++){
            if (id == bk[i].bookID){
                printf("The bookID has already existed! Unable to addBook()\n");
                return size;
            }
        }
        bk[size].bookID = id;
        strcpy(bk[size].title, ttl);
        strcpy(bk[size].author, aut);
        bk[size].price = pr;
        bk[size].quantity = qnt;
        printf("The book has been added successfully\n");
        size = size+1;

        for (i=0; i<size; i++){
            for (a=0; a<size; a++){
                if (bk[i].bookID<bk[a].bookID){
                    temp = bk[i];
                    bk[i] = bk[a];
                    bk[a] = temp;
                }
            }
        }
        }
        return size;
    }

int removebook(Book *bk, int size){
    char title[20], author[20], ttl[20], aut[20], *p, dum;
    int i, a;

    scanf("%c", &dum);
    printf("Enter the target book title:\n");
    fgets(title, 20, stdin);
    if (p=strchr(title,'\n'))
        *p = '\0';
    printf("Enter the target author name:\n");
    fgets(author, 20, stdin);
    if (p=strchr(author,'\n'))
        *p = '\0';
    for (i=0; i<20; i++){
        title[i] = toupper (title[i]);
        author[i] = toupper (author[i]);
    }

    if (size == 0){
        printf("The bookshop is empty\n");
        return size;
    }
    else {
        for (i=0; i<size; i++){
            strcpy (ttl, bk[i].title);
            strcpy (aut, bk[i].author);
            for (a=0; a<20; a++){
                ttl[a] = toupper(ttl[a]);
                aut[a] = toupper(aut[a]);
            }
            if (strcmp(title, ttl)==0 && strcmp(author, aut)==0){
                printf("The target book is removed\n");
                printf("BookID: %d\n", bk[i].bookID);
                printf("Book title: %s\n", bk[i].title);
                printf("Author name: %s\n", bk[i].author);
                printf("Book price: %.2f\n", bk[i].price);
                printf("Quantity: %d\n", bk[i].quantity);
                for (a=i; a<size; a++){
                    bk[a]=bk[a+1];
                }
                size--;
                return size;
            }
        }
        printf("The target book is not in the bookshop\n");
    }
    return size;
}

void findbook(Book *bk, int size){
    int i, a;
    char title[20], author[20], ttl[20], aut[20], *p, dum;

    scanf("%c", &dum);
    printf("Enter the target book title:\n");
    fgets(title, 20, stdin);
    if (p=strchr(title,'\n'))
        *p = '\0';
    printf("Enter the target author name:\n");
    fgets(author, 20, stdin);
    if (p=strchr(author,'\n'))
        *p = '\0';
    for (i=0; i<20; i++){
        title[i] = toupper (title[i]);
        author[i] = toupper (author[i]);
    }

    for (i=0; i<size; i++){
        strcpy (ttl, bk[i].title);
        strcpy (aut, bk[i].author);
        for (a=0; a<20; a++){
            ttl[a] = toupper(ttl[a]);
            aut[a] = toupper(aut[a]);
            }
        if (strcmp(ttl, title)==0 && strcmp(aut, author)==0){
            printf("The target book is found\n");
            printf("BookID: %d\n", bk[i].bookID);
            printf("Book title: %s\n", bk[i].title);
            printf("Author name: %s\n", bk[i].author);
            printf("Book price: %.2f\n", bk[i].price);
            printf("Quantity: %d\n", bk[i].quantity);
            return;
        }
    }
    printf("The target book is not found\n");
}

void updatebook(Book *bk, int size){
    int i, a, quantity;
    char title[20], author[20], ttl[20], aut[20], *p, dum;
    double price;

    scanf("%c", &dum);
    printf("Enter the target book title:\n");
    fgets(title, 20, stdin);
    if (p=strchr(title,'\n'))
        *p = '\0';
    printf("Enter the target author name:\n");
    fgets(author, 20, stdin);
    if (p=strchr(author,'\n'))
        *p = '\0';
    for (i=0; i<20; i++){
        title[i] = toupper (title[i]);
        author[i] = toupper (author[i]);
    }

    for (i=0; i<size; i++){
        strcpy (ttl, bk[i].title);
        strcpy (aut, bk[i].author);
        for (a=0; a<20; a++){
            ttl[a] = toupper(ttl[a]);
            aut[a] = toupper(aut[a]);
        }
        if (strcmp(ttl, title)==0 && strcmp(aut, author)==0){
            printf("Enter updated book price:\n");
            scanf("%lf", &price);
            scanf("%c", &dum);
            printf("Enter updated quantity:\n");
            scanf("%d", &quantity);
            scanf("%c", &dum);
            bk[i].price=price;
            bk[i].quantity=quantity;
            printf("The target book is updated\n");
            printf("BookID: %d\n", bk[i].bookID);
            printf("Book title: %s\n", bk[i].title);
            printf("Author name: %s\n", bk[i].author);
            printf("Book price: %.2f\n", bk[i].price);
            printf("Quantity: %d\n", bk[i].quantity);
            return;
        }
    }
    printf("The target book is not in the bookshop\n");
    return;
}
