#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readers.h"

void addReader(Reader **readers, int *readerCount) {
    (*readerCount)++;
    *readers = realloc(*readers, (*readerCount) * sizeof(Reader));
    Reader *newReader = &(*readers)[(*readerCount) - 1];

    newReader->id = *readerCount;
    printf("Podaj imię: ");
    scanf(" %[^\n]", newReader->name);
    printf("Podaj nazwisko: ");
    scanf(" %[^\n]", newReader->surname);
    printf("Podaj adres: ");
    scanf(" %[^\n]", newReader->address);
    printf("Podaj numer telefonu: ");
    scanf(" %[^\n]", newReader->phone);

    printf("Czytelnik został dodany.\n");
}

void removeReader(Reader **readers, int *readerCount, int readerId) {
    int found = 0;
    for (int i = 0; i < *readerCount; i++) {
        if ((*readers)[i].id == readerId) {
            for (int j = i; j < (*readerCount) - 1; j++) {
                (*readers)[j] = (*readers)[j + 1];
            }
            (*readerCount)--;
            *readers = realloc(*readers, (*readerCount) * sizeof(Reader));
            found = 1;
            printf("Czytelnik został usunięty.\n");
            break;
        }
    }
    if (!found) {
        printf("Nie znaleziono czytelnika o podanym ID.\n");
    }
}

void searchReaders(Reader *readers, int readerCount, char *keyword) {
    printf("Wyniki wyszukiwania dla \"%s\":\n", keyword);
    int found = 0;
    for (int i = 0; i < readerCount; i++) {
        if (strstr(readers[i].name, keyword) || strstr(readers[i].surname, keyword)) {
            printf("ID: %d, Imię: %s, Nazwisko: %s\n", readers[i].id, readers[i].name, readers[i].surname);
            found = 1;
        }
    }
    if (!found) {
        printf("Brak wyników.\n");
    }
}

void listReaders(Reader *readers, int readerCount) {
    printf("Lista czytelników:\n");
    for (int i = 0; i < readerCount; i++) {
        printf("ID: %d, Imię: %s, Nazwisko: %s\n",
               readers[i].id, readers[i].name, readers[i].surname);
    }
}
