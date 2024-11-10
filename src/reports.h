#ifndef REPORTS_H
#define REPORTS_H

#include "books.h"
#include "readers.h"
#include "loans.h"

void generateLoanHistory(Loan *loans, int loanCount);
void mostBorrowedBooks(Loan *loans, int loanCount, Book *books, int bookCount);

#endif // REPORTS_H
