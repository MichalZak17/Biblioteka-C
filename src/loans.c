/**
 * @file loans.c
 * @brief This file contains functions for managing book loans in the library system.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "loans.h"

/**
 * @brief Loans a book to a reader.
 * 
 * @param loans Pointer to the array of loans.
 * @param loanCount Pointer to the number of loans.
 * @param books Array of books.
 * @param bookCount Number of books.
 * @param readers Array of readers.
 * @param readerCount Number of readers.
 */
void loanBook(Loan **loans, int *loanCount, Book *books, int bookCount, Reader *readers, int readerCount) {
    int bookId, readerId;
    printf("Podaj ID książki do wypożyczenia: ");
    scanf("%d", &bookId);
    printf("Podaj ID czytelnika: ");
    scanf("%d", &readerId);

    Book *book = NULL;
    Reader *reader = NULL;

    // Find the book by ID
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId) {
            book = &books[i];
            break;
        }
    }

    // Find the reader by ID
    for (int i = 0; i < readerCount; i++) {
        if (readers[i].id == readerId) {
            reader = &readers[i];
            break;
        }
    }

    if (book == NULL) {
        printf("Nie znaleziono książki o podanym ID.\n");
        return;
    }

    if (reader == NULL) {
        printf("Nie znaleziono czytelnika o podanym ID.\n");
        return;
    }

    if (book->available_copies <= 0) {
        printf("Brak dostępnych egzemplarzy książki.\n");
        return;
    }

    (*loanCount)++;
    *loans = realloc(*loans, (*loanCount) * sizeof(Loan));
    Loan *newLoan = &(*loans)[(*loanCount) - 1];

    newLoan->id = *loanCount;
    newLoan->book_id = bookId;
    newLoan->reader_id = readerId;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newLoan->loan_date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    strcpy(newLoan->return_date, "N/A");
    newLoan->status = ACTIVE;

    book->available_copies--;

    printf("Książka została wypożyczona.\n");
}

/**
 * @brief Returns a book that was loaned.
 * 
 * @param loans Array of loans.
 * @param loanCount Number of loans.
 * @param books Array of books.
 * @param bookCount Number of books.
 * @param loanId ID of the loan to be returned.
 */
void returnBook(Loan *loans, int loanCount, Book *books, int bookCount, int loanId) {
    Loan *loan = NULL;
    for (int i = 0; i < loanCount; i++) {
        if (loans[i].id == loanId) {
            loan = &loans[i];
            break;
        }
    }

    if (loan == NULL) {
        printf("Nie znaleziono wypożyczenia o podanym ID.\n");
        return;
    }

    if (loan->status != ACTIVE) {
        printf("To wypożyczenie zostało już zakończone.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == loan->book_id) {
            books[i].available_copies++;
            break;
        }
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(loan->return_date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    loan->status = RETURNED;

    printf("Książka została zwrócona.\n");
}

/**
 * @brief Lists all loans in the library.
 * 
 * @param loans Array of loans.
 * @param loanCount Number of loans.
 */
void listLoans(Loan *loans, int loanCount) {
    printf("Lista wypożyczeń:\n");
    for (int i = 0; i < loanCount; i++) {
        printf("ID: %d, ID Książki: %d, ID Czytelnika: %d, Data wypożyczenia: %s, Data zwrotu: %s, Status: %d\n",
               loans[i].id, loans[i].book_id, loans[i].reader_id,
               loans[i].loan_date, loans[i].return_date, loans[i].status);
    }
}
