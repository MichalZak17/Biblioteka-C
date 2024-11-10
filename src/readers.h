#ifndef READERS_H
#define READERS_H

typedef struct {
    int id;
    char name[100];
    char surname[100];
    char address[150];
    char phone[15];
} Reader;

void addReader(Reader **readers, int *readerCount);
void removeReader(Reader **readers, int *readerCount, int readerId);
void searchReaders(Reader *readers, int readerCount, char *keyword);
void listReaders(Reader *readers, int readerCount);

#endif // READERS_H
