#include <stdio.h>
#include <stdlib.h>
#include "reports.h"

void generateLoanHistory(Loan *loans, int loanCount) {
    printf("Historia wypożyczeń:\n");
    for (int i = 0; i < loanCount; i++) {
        printf("ID Wypożyczenia: %d, Książka ID: %d, Czytelnik ID: %d, Data wypożyczenia: %s, Data zwrotu: %s\n",
               loans[i].id, loans[i].book_id, loans[i].reader_id,
               loans[i].loan_date, loans[i].return_date);
    }
}

void mostBorrowedBooks(Loan *loans, int loanCount, Book *books, int bookCount) {
    int *borrowCounts = calloc(bookCount, sizeof(int));
    for (int i = 0; i < loanCount; i++) {
        if (loans[i].status != RETURNED) continue;
        for (int j = 0; j < bookCount; j++) {
            if (books[j].id == loans[i].book_id) {
                borrowCounts[j]++;
                break;
            }
        }
    }

    printf("Najczęściej wypożyczane książki:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Książka ID: %d, Tytuł: %s, Liczba wypożyczeń: %d\n",
               books[i].id, books[i].title, borrowCounts[i]);
    }

    free(borrowCounts);
}
