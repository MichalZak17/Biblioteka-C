#ifndef BOOKS_H
#define BOOKS_H

/**
 * @brief Structure representing a book in the library.
 */
typedef struct {
    int id; /**< ID of the book */
    char title[100]; /**< Title of the book */
    char author[100]; /**< Author of the book */
    char publisher[100]; /**< Publisher of the book */
    int year; /**< Year of publication */
    int available_copies; /**< Number of available copies */
    int total_copies; /**< Total number of copies */
} Book;

/**
 * @brief Adds a new book to the library.
 * 
 * @param books Pointer to the array of books.
 * @param bookCount Pointer to the number of books.
 */
void addBook(Book **books, int *bookCount);

/**
 * @brief Removes a book from the library.
 * 
 * @param books Pointer to the array of books.
 * @param bookCount Pointer to the number of books.
 * @param bookId ID of the book to be removed.
 */
void removeBook(Book **books, int *bookCount, int bookId);

/**
 * @brief Updates the details of a book in the library.
 * 
 * @param books Array of books.
 * @param bookCount Number of books.
 * @param bookId ID of the book to be updated.
 */
void updateBook(Book *books, int bookCount, int bookId);

/**
 * @brief Searches for books in the library based on a keyword.
 * 
 * @param books Array of books.
 * @param bookCount Number of books.
 * @param keyword Keyword to search for.
 */
void searchBooks(Book *books, int bookCount, char *keyword);

/**
 * @brief Lists all books in the library.
 * 
 * @param books Array of books.
 * @param bookCount Number of books.
 */
void listBooks(Book *books, int bookCount);

#endif // BOOKS_H
