#ifndef FILES_H
#define FILES_H

#include "books.h"
#include "readers.h"
#include "loans.h"

/**
 * @brief Loads books from a file.
 * 
 * @param books Pointer to the array of books.
 * @param bookCount Pointer to the number of books.
 * @param filename Name of the file to load books from.
 */
void loadBooks(Book **books, int *bookCount, const char *filename);

/**
 * @brief Saves books to a file.
 * 
 * @param books Array of books.
 * @param bookCount Number of books.
 * @param filename Name of the file to save books to.
 */
void saveBooks(Book *books, int bookCount, const char *filename);

/**
 * @brief Loads readers from a file.
 * 
 * @param readers Pointer to the array of readers.
 * @param readerCount Pointer to the number of readers.
 * @param filename Name of the file to load readers from.
 */
void loadReaders(Reader **readers, int *readerCount, const char *filename);

/**
 * @brief Saves readers to a file.
 * 
 * @param readers Array of readers.
 * @param readerCount Number of readers.
 * @param filename Name of the file to save readers to.
 */
void saveReaders(Reader *readers, int readerCount, const char *filename);

/**
 * @brief Loads loans from a file.
 * 
 * @param loans Pointer to the array of loans.
 * @param loanCount Pointer to the number of loans.
 * @param filename Name of the file to load loans from.
 */
void loadLoans(Loan **loans, int *loanCount, const char *filename);

/**
 * @brief Saves loans to a file.
 * 
 * @param loans Array of loans.
 * @param loanCount Number of loans.
 * @param filename Name of the file to save loans to.
 */
void saveLoans(Loan *loans, int loanCount, const char *filename);

#endif // FILES_H
