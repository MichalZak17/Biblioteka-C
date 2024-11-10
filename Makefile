CC = gcc
CFLAGS = -Wall -std=c99

SRCDIR = src
OBJS = $(SRCDIR)/main.o $(SRCDIR)/ui.o $(SRCDIR)/books.o $(SRCDIR)/readers.o $(SRCDIR)/loans.o $(SRCDIR)/reports.o $(SRCDIR)/files.o

all: library

library: $(OBJS)
	$(CC) $(CFLAGS) -o library $(OBJS)
	@$(MAKE) clean

$(SRCDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/ui.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.c -o $(SRCDIR)/main.o

$(SRCDIR)/ui.o: $(SRCDIR)/ui.c $(SRCDIR)/ui.h $(SRCDIR)/books.h $(SRCDIR)/readers.h $(SRCDIR)/loans.h $(SRCDIR)/reports.h $(SRCDIR)/files.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/ui.c -o $(SRCDIR)/ui.o

$(SRCDIR)/books.o: $(SRCDIR)/books.c $(SRCDIR)/books.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/books.c -o $(SRCDIR)/books.o

$(SRCDIR)/readers.o: $(SRCDIR)/readers.c $(SRCDIR)/readers.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/readers.c -o $(SRCDIR)/readers.o

$(SRCDIR)/loans.o: $(SRCDIR)/loans.c $(SRCDIR)/loans.h $(SRCDIR)/books.h $(SRCDIR)/readers.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/loans.c -o $(SRCDIR)/loans.o

$(SRCDIR)/reports.o: $(SRCDIR)/reports.c $(SRCDIR)/reports.h $(SRCDIR)/books.h $(SRCDIR)/loans.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/reports.c -o $(SRCDIR)/reports.o

$(SRCDIR)/files.o: $(SRCDIR)/files.c $(SRCDIR)/files.h $(SRCDIR)/books.h $(SRCDIR)/readers.h $(SRCDIR)/loans.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/files.c -o $(SRCDIR)/files.o

clean:
	rm -f $(OBJS)
