#ifndef READERS_H
#define READERS_H

/**
 * @brief Structure representing a reader in the library.
 */
typedef struct {
    int id; /**< ID of the reader */
    char name[100]; /**< Name of the reader */
    char surname[100]; /**< Surname of the reader */
    char address[150]; /**< Address of the reader */
    char phone[15]; /**< Phone number of the reader */
} Reader;

/**
 * @brief Adds a new reader to the library.
 * 
 * @param readers Pointer to the array of readers.
 * @param readerCount Pointer to the number of readers.
 */
void addReader(Reader **readers, int *readerCount);

/**
 * @brief Removes a reader from the library.
 * 
 * @param readers Pointer to the array of readers.
 * @param readerCount Pointer to the number of readers.
 * @param readerId ID of the reader to be removed.
 */
void removeReader(Reader **readers, int *readerCount, int readerId);

/**
 * @brief Searches for readers in the library based on a keyword.
 * 
 * @param readers Array of readers.
 * @param readerCount Number of readers.
 * @param keyword Keyword to search for.
 */
void searchReaders(Reader *readers, int readerCount, char *keyword);

/**
 * @brief Lists all readers in the library.
 * 
 * @param readers Array of readers.
 * @param readerCount Number of readers.
 */
void listReaders(Reader *readers, int readerCount);

#endif // READERS_H
