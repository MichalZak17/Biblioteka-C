#ifndef FILES_H
#define FILES_H

#include "books.h"
#include "readers.h"
#include "loans.h"

void loadBooks(Book **books, int *bookCount, const char *filename);
void saveBooks(Book *books, int bookCount, const char *filename);
void loadReaders(Reader **readers, int *readerCount, const char *filename);
void saveReaders(Reader *readers, int readerCount, const char *filename);
void loadLoans(Loan **loans, int *loanCount, const char *filename);
void saveLoans(Loan *loans, int loanCount, const char *filename);

#endif // FILES_H
