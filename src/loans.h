#ifndef LOANS_H
#define LOANS_H

#include "books.h"
#include "readers.h"

/**
 * @brief Enum representing the status of a loan.
 */
typedef enum { ACTIVE, RETURNED, LATE } LoanStatus;

/**
 * @brief Structure representing a loan in the library.
 */
typedef struct {
    int id; /**< ID of the loan */
    int book_id; /**< ID of the book being loaned */
    int reader_id; /**< ID of the reader borrowing the book */
    char loan_date[11]; /**< Date of loan in format YYYY-MM-DD */
    char return_date[11]; /**< Date of return in format YYYY-MM-DD */
    LoanStatus status; /**< Status of the loan */
} Loan;

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
void loanBook(Loan **loans, int *loanCount, Book *books, int bookCount, Reader *readers, int readerCount);

/**
 * @brief Returns a book that was loaned.
 * 
 * @param loans Array of loans.
 * @param loanCount Number of loans.
 * @param books Array of books.
 * @param bookCount Number of books.
 * @param loanId ID of the loan to be returned.
 */
void returnBook(Loan *loans, int loanCount, Book *books, int bookCount, int loanId);

/**
 * @brief Lists all loans in the library.
 * 
 * @param loans Array of loans.
 * @param loanCount Number of loans.
 */
void listLoans(Loan *loans, int loanCount);

#endif // LOANS_H
