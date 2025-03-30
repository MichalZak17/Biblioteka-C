#ifndef REPORTS_H
#define REPORTS_H

#include "books.h"
#include "readers.h"
#include "loans.h"

/**
 * @brief Generates the loan history report.
 * 
 * @param loans Array of loans.
 * @param loanCount Number of loans.
 */
void generateLoanHistory(Loan *loans, int loanCount);

/**
 * @brief Generates the most borrowed books report.
 * 
 * @param loans Array of loans.
 * @param loanCount Number of loans.
 * @param books Array of books.
 * @param bookCount Number of books.
 */
void mostBorrowedBooks(Loan *loans, int loanCount, Book *books, int bookCount);

#endif // REPORTS_H
