#ifndef LOANS_H
#define LOANS_H

#include "books.h"
#include "readers.h"

typedef enum { ACTIVE, RETURNED, LATE } LoanStatus;

typedef struct {
    int id;
    int book_id;
    int reader_id;
    char loan_date[11];   // format: YYYY-MM-DD
    char return_date[11]; // format: YYYY-MM-DD
    LoanStatus status;
} Loan;

void loanBook(Loan **loans, int *loanCount, Book *books, int bookCount, Reader *readers, int readerCount);
void returnBook(Loan *loans, int loanCount, Book *books, int bookCount, int loanId);
void listLoans(Loan *loans, int loanCount);

#endif // LOANS_H
