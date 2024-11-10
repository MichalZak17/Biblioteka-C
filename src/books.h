#ifndef BOOKS_H
#define BOOKS_H

typedef struct {
    int id;
    char title[100];
    char author[100];
    char publisher[100];
    int year;
    int available_copies;
    int total_copies;
} Book;

void addBook(Book **books, int *bookCount);
void removeBook(Book **books, int *bookCount, int bookId);
void updateBook(Book *books, int bookCount, int bookId);
void searchBooks(Book *books, int bookCount, char *keyword);
void listBooks(Book *books, int bookCount);

#endif // BOOKS_H
