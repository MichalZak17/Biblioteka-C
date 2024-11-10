#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"

void addBook(Book **books, int *bookCount) {
    (*bookCount)++;
    *books = realloc(*books, (*bookCount) * sizeof(Book));
    Book *newBook = &(*books)[(*bookCount) - 1];

    newBook->id = *bookCount;
    printf("Podaj tytuł książki: ");
    scanf(" %[^\n]", newBook->title);
    printf("Podaj autora: ");
    scanf(" %[^\n]", newBook->author);
    printf("Podaj wydawnictwo: ");
    scanf(" %[^\n]", newBook->publisher);
    printf("Podaj rok wydania: ");
    scanf("%d", &newBook->year);
    printf("Podaj liczbę egzemplarzy: ");
    scanf("%d", &newBook->total_copies);
    newBook->available_copies = newBook->total_copies;

    printf("Książka została dodana.\n");
}

void removeBook(Book **books, int *bookCount, int bookId) {
    int found = 0;
    for (int i = 0; i < *bookCount; i++) {
        if ((*books)[i].id == bookId) {
            for (int j = i; j < (*bookCount) - 1; j++) {
                (*books)[j] = (*books)[j + 1];
            }
            (*bookCount)--;
            *books = realloc(*books, (*bookCount) * sizeof(Book));
            found = 1;
            printf("Książka została usunięta.\n");
            break;
        }
    }
    if (!found) {
        printf("Nie znaleziono książki o podanym ID.\n");
    }
}

void updateBook(Book *books, int bookCount, int bookId) {
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            printf("Aktualizacja danych książki ID %d:\n", bookId);
            printf("Podaj nowy tytuł (obecny: %s): ", books[i].title);
            scanf(" %[^\n]", books[i].title);
            printf("Podaj nowego autora (obecny: %s): ", books[i].author);
            scanf(" %[^\n]", books[i].author);
            printf("Podaj nowe wydawnictwo (obecne: %s): ", books[i].publisher);
            scanf(" %[^\n]", books[i].publisher);
            printf("Podaj nowy rok wydania (obecny: %d): ", books[i].year);
            scanf("%d", &books[i].year);
            printf("Podaj nową liczbę egzemplarzy (obecna: %d): ", books[i].total_copies);
            scanf("%d", &books[i].total_copies);
            books[i].available_copies = books[i].total_copies;
            printf("Dane książki zostały zaktualizowane.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Nie znaleziono książki o podanym ID.\n");
    }
}

void searchBooks(Book *books, int bookCount, char *keyword) {
    printf("Wyniki wyszukiwania dla \"%s\":\n", keyword);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword)) {
            printf("ID: %d, Tytuł: %s, Autor: %s\n", books[i].id, books[i].title, books[i].author);
            found = 1;
        }
    }
    if (!found) {
        printf("Brak wyników.\n");
    }
}

void listBooks(Book *books, int bookCount) {
    printf("Lista książek:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Tytuł: %s, Autor: %s, Dostępne: %d/%d\n",
               books[i].id, books[i].title, books[i].author,
               books[i].available_copies, books[i].total_copies);
    }
}

