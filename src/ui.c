#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "books.h"
#include "readers.h"
#include "loans.h"
#include "reports.h"
#include "files.h"

void booksMenu(Book **books, int *bookCount);
void readersMenu(Reader **readers, int *readerCount);
void loansMenu(Loan **loans, int *loanCount, Book *books, int bookCount, Reader *readers, int readerCount);
void reportsMenu(Loan *loans, int loanCount, Book *books, int bookCount);

void mainMenu() {
    Book *books = NULL;
    int bookCount = 0;
    Reader *readers = NULL;
    int readerCount = 0;
    Loan *loans = NULL;
    int loanCount = 0;

    loadBooks(&books, &bookCount, "books.txt");
    loadReaders(&readers, &readerCount, "readers.txt");
    loadLoans(&loans, &loanCount, "loans.txt");

    int choice;
    do {
        printf("\n--- System Zarządzania Biblioteką ---\n");
        printf("1. Zarządzanie książkami\n");
        printf("2. Zarządzanie czytelnikami\n");
        printf("3. Zarządzanie wypożyczeniami\n");
        printf("4. Raporty\n");
        printf("0. Zakończ\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                booksMenu(&books, &bookCount);
                break;
            case 2:
                readersMenu(&readers, &readerCount);
                break;
            case 3:
                loansMenu(&loans, &loanCount, books, bookCount, readers, readerCount);
                break;
            case 4:
                reportsMenu(loans, loanCount, books, bookCount);
                break;
            case 0:
                saveBooks(books, bookCount, "books.txt");
                saveReaders(readers, readerCount, "readers.txt");
                saveLoans(loans, loanCount, "loans.txt");
                printf("Do widzenia!\n");
                break;
            default:
                printf("Nieprawidłowy wybór.\n");
        }
    } while (choice != 0);

    free(books);
    free(readers);
    free(loans);
}

void booksMenu(Book **books, int *bookCount) {
    int choice;
    char keyword[100];
    int id;

    do {
        printf("\n--- Zarządzanie książkami ---\n");
        printf("1. Dodaj książkę\n");
        printf("2. Usuń książkę\n");
        printf("3. Aktualizuj książkę\n");
        printf("4. Wyszukaj książkę\n");
        printf("5. Wyświetl wszystkie książki\n");
        printf("0. Powrót do menu głównego\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                printf("Podaj ID książki do usunięcia: ");
                scanf("%d", &id);
                removeBook(books, bookCount, id);
                break;
            case 3:
                printf("Podaj ID książki do aktualizacji: ");
                scanf("%d", &id);
                updateBook(*books, *bookCount, id);
                break;
            case 4:
                printf("Podaj słowo kluczowe: ");
                scanf(" %[^\n]", keyword);
                searchBooks(*books, *bookCount, keyword);
                break;
            case 5:
                listBooks(*books, *bookCount);
                break;
            case 0:
                break;
            default:
                printf("Nieprawidłowy wybór.\n");
        }
    } while (choice != 0);
}

void readersMenu(Reader **readers, int *readerCount) {
    int choice;
    char keyword[100];
    int id;

    do {
        printf("\n--- Zarządzanie czytelnikami ---\n");
        printf("1. Dodaj czytelnika\n");
        printf("2. Usuń czytelnika\n");
        printf("3. Wyszukaj czytelnika\n");
        printf("4. Wyświetl wszystkich czytelników\n");
        printf("0. Powrót do menu głównego\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReader(readers, readerCount);
                break;
            case 2:
                printf("Podaj ID czytelnika do usunięcia: ");
                scanf("%d", &id);
                removeReader(readers, readerCount, id);
                break;
            case 3:
                printf("Podaj słowo kluczowe: ");
                scanf(" %[^\n]", keyword);
                searchReaders(*readers, *readerCount, keyword);
                break;
            case 4:
                listReaders(*readers, *readerCount);
                break;
            case 0:
                break;
            default:
                printf("Nieprawidłowy wybór.\n");
        }
    } while (choice != 0);
}

void loansMenu(Loan **loans, int *loanCount, Book *books, int bookCount, Reader *readers, int readerCount) {
    int choice;
    int id;

    do {
        printf("\n--- Zarządzanie wypożyczeniami ---\n");
        printf("1. Wypożycz książkę\n");
        printf("2. Zwróć książkę\n");
        printf("3. Wyświetl wszystkie wypożyczenia\n");
        printf("0. Powrót do menu głównego\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loanBook(loans, loanCount, books, bookCount, readers, readerCount);
                break;
            case 2:
                printf("Podaj ID wypożyczenia do zakończenia: ");
                scanf("%d", &id);
                returnBook(*loans, *loanCount, books, bookCount, id);
                break;
            case 3:
                listLoans(*loans, *loanCount);
                break;
            case 0:
                break;
            default:
                printf("Nieprawidłowy wybór.\n");
        }
    } while (choice != 0);
}

void reportsMenu(Loan *loans, int loanCount, Book *books, int bookCount) {
    int choice;

    do {
        printf("\n--- Raporty ---\n");
        printf("1. Historia wypożyczeń\n");
        printf("2. Najczęściej wypożyczane książki\n");
        printf("0. Powrót do menu głównego\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateLoanHistory(loans, loanCount);
                break;
            case 2:
                mostBorrowedBooks(loans, loanCount, books, bookCount);
                break;
            case 0:
                break;
            default:
                printf("Nieprawidłowy wybór.\n");
        }
    } while (choice != 0);
}
