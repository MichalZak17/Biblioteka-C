#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

void loadBooks(Book **books, int *bookCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Nie można otworzyć pliku %s.\n", filename);
        return;
    }

    *bookCount = 0;
    *books = NULL;

    Book temp;
    while (fscanf(file, "%d;%99[^;];%99[^;];%99[^;];%d;%d;%d\n",
                  &temp.id, temp.title, temp.author, temp.publisher,
                  &temp.year, &temp.available_copies, &temp.total_copies) == 7) {
        (*bookCount)++;
        *books = realloc(*books, (*bookCount) * sizeof(Book));
        (*books)[(*bookCount) - 1] = temp;
    }

    fclose(file);
}

void saveBooks(Book *books, int bookCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Nie można zapisać do pliku %s.\n", filename);
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%d;%s;%s;%s;%d;%d;%d\n",
                books[i].id, books[i].title, books[i].author, books[i].publisher,
                books[i].year, books[i].available_copies, books[i].total_copies);
    }

    fclose(file);
}

void loadReaders(Reader **readers, int *readerCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Nie można otworzyć pliku %s.\n", filename);
        return;
    }

    *readerCount = 0;
    *readers = NULL;

    Reader temp;
    while (fscanf(file, "%d;%99[^;];%99[^;];%149[^;];%14[^\n]\n",
                  &temp.id, temp.name, temp.surname, temp.address, temp.phone) == 5) {
        (*readerCount)++;
        *readers = realloc(*readers, (*readerCount) * sizeof(Reader));
        (*readers)[(*readerCount) - 1] = temp;
    }

    fclose(file);
}

void saveReaders(Reader *readers, int readerCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Nie można zapisać do pliku %s.\n", filename);
        return;
    }

    for (int i = 0; i < readerCount; i++) {
        fprintf(file, "%d;%s;%s;%s;%s\n",
                readers[i].id, readers[i].name, readers[i].surname,
                readers[i].address, readers[i].phone);
    }

    fclose(file);
}

void loadLoans(Loan **loans, int *loanCount, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Nie można otworzyć pliku %s.\n", filename);
        return;
    }

    *loanCount = 0;
    *loans = NULL;

    Loan temp;
    int status;
    while (fscanf(file, "%d;%d;%d;%10[^;];%10[^;];%d\n",
                  &temp.id, &temp.book_id, &temp.reader_id,
                  temp.loan_date, temp.return_date, &status) == 6) {
        temp.status = status;
        (*loanCount)++;
        *loans = realloc(*loans, (*loanCount) * sizeof(Loan));
        (*loans)[(*loanCount) - 1] = temp;
    }

    fclose(file);
}

void saveLoans(Loan *loans, int loanCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Nie można zapisać do pliku %s.\n", filename);
        return;
    }

    for (int i = 0; i < loanCount; i++) {
        fprintf(file, "%d;%d;%d;%s;%s;%d\n",
                loans[i].id, loans[i].book_id, loans[i].reader_id,
                loans[i].loan_date, loans[i].return_date, loans[i].status);
    }

    fclose(file);
}
