#!/bin/bash

# Tworzenie folderu src
mkdir -p src

# Przejście do folderu src
cd src

# Tworzenie plików głównych
touch main.c Makefile

# Tworzenie folderów i plików modułów
for module in books readers loans reports files ui; do
  touch "${module}.c" "${module}.h"
done

# Tworzenie plików danych
touch books.txt readers.txt loans.txt

echo "Wszystkie pliki zostały pomyślnie utworzone w folderze src."
