# Library Management System

## Description
The Library Management System is a software application designed to help libraries manage their collections of books, readers, and loans. It provides functionalities for adding, updating, and removing books and readers, as well as managing book loans and generating reports.

## Features
- Manage books: add, update, remove, and search for books.
- Manage readers: add, update, remove, and search for readers.
- Manage loans: loan and return books, view loan history.
- Generate reports: view loan history and most borrowed books.

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/MichalZak17/Biblioteka-C.git
   cd Biblioteka-C
   ```
2. Compile the project using the provided `Makefile`:
   ```sh
   make
   ```

## Usage
1. Run the compiled program:
   ```sh
   ./library
   ```
2. Navigate through the main menu and submenus to manage books, readers, loans, and generate reports.

## Modules

### books.c
This module contains functions for managing books in the library system. It provides functionalities to add, remove, update, search, and list books.

### files.c
This module contains functions for loading and saving data to and from files. It handles the persistence of books, readers, and loans data.

### loans.c
This module contains functions for managing book loans in the library system. It provides functionalities to loan and return books, and list all loans.

### main.c
This module contains the main function to start the library management system. It initializes the system and displays the main menu.

### readers.c
This module contains functions for managing readers in the library system. It provides functionalities to add, remove, search, and list readers.

### reports.c
This module contains functions for generating reports in the library system. It provides functionalities to generate loan history and most borrowed books reports.

### ui.c
This module contains the user interface functions for the library management system. It handles the display of menus and user input for managing books, readers, loans, and generating reports.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact Information
For support or questions, please contact the project maintainer at michal.zak000@gmail.com.
