# Inverted Search in C

A menu-driven Inverted Search application developed using C to create, display, update, search, and save an inverted index of words from multiple text files.

## Features

- Create Database - Read input text files and create an index of words with their file names and occurrence counts.
- Display Database - Display indexed words, file names, file counts, and word frequencies.
- Update Database - Load a previously saved database and update the index with additional files.
- Search Word - Search for a word and display the files containing it and its occurrence count.
- Save Database - Save the indexed database to a file for future use.
- Error Handling - Handle invalid arguments, invalid file extensions, duplicate files, and empty file lists.

## Technologies Used

- Programming Language: C
- Compiler: GCC or another compatible C compiler
- Data Structures: Linked Lists
- Concepts: File Handling, String Processing, Command-Line Arguments, Database Creation, Searching, and Input Validation

---

## Installation

### Prerequisites

- A C compiler, such as GCC.
- A code editor or IDE, such as Visual Studio Code.
- Linux or another environment that supports GCC.

### Get the Project

1. Download the project from GitHub as a ZIP file.
2. Extract the downloaded ZIP file.
3. Open the extracted project folder in your preferred C development environment.

---

## How to Compile and Run

### Using GCC

Compile the source files using the following command:

    gcc *.c -o inverted_search

Run the program with input text files:

    ./inverted_search file1.txt file2.txt

Note: Provide valid `.txt` files as command-line arguments. Make sure the compilation command includes the required source files and does not include unrelated C files.

### Using a C IDE

1. Open the project source files.
2. Add all required C source files to the project.
3. Build or compile the project.
4. Run the generated executable with the required text files as arguments.

---

## Project Structure

    Inverted-Search/
    |
    |-- main.c
    |-- Create_database.c
    |-- Display_database.c
    |-- main.h
    |-- file1.txt
    |-- file2.txt
    |-- file3.txt
    |-- file4.txt
    |-- backup.txt
    |-- documentation.txt
    |-- README.md

Note: Update this file list to match your actual project files.

---

## File Responsibilities

- main.c: Contains the main function, command-line argument handling, and menu operations.
- Create_database.c: Implements database creation by reading input files and indexing words.
- Display_database.c: Displays indexed words, file names, file counts, and word frequencies.
- main.h: Contains shared structures, function declarations, and common definitions.
- file1.txt, file2.txt, file3.txt, file4.txt: Sample input files containing text to be indexed.
- backup.txt: Stores the saved database for later loading or updating.
- documentation.txt: Contains project documentation, sample executions, and error-handling examples.
- README.md: Describes the project, features, compilation, and usage.

Note: Add the actual source filenames for search, update, and save operations if they are implemented in separate files.

---

## Menu Options

The program displays the following menu:

    Select your choice among following options:
    1. Create Database
    2. Display Database
    3. Update Database
    4. Search
    5. Save Database
    6. Exit

- Option 1: Creates the database from the input files.
- Option 2: Displays the indexed database.
- Option 3: Updates the database using a previously saved database file.
- Option 4: Searches for a word in the database.
- Option 5: Saves the database to a specified file.
- Option 6: Exits the program.

---

## Sample Input Files

### file1.txt

    Hi hello how are you ? Hi Hello Hi Hi Hi Hi Hello

### file2.txt

    Hi Hello this is inverted search project.

### file3.txt

    i am good hi hello hi you know?

### file4.txt

    Hi you will die as a hero.

---

## Sample Execution

### Create Database

Run the program:

    ./a.out file1.txt file2.txt

Select option `1` to create the database.

    INFO : Creation of database for file file1.txt is Successful
    INFO : Creation of database for file file2.txt is Successful

### Search Word

Select option `4` and enter the word `Hi`.

    Enter word to search : Hi

    Word Hi is present in 2 file/s
    In file: file1.txt 6 time/s
    In file: file2.txt 2 time/s

    INFO : Search Database is Successful

### Save Database

Select option `5` to save the database.

    Enter file name : backup.txt
    INFO : Save Database is Successful

---

## Error Handling

The application handles the following situations:

- Invalid command-line arguments.
- Invalid file extensions.
- Duplicate input files.
- Empty file lists.
- Words that are not present in the database.

### Example: Invalid Arguments

Input:

    ./a.out

Output:

    INFO : Invalid Arguments

### Example: Invalid File Extension

Input:

    ./a.out file1.txt file2.txt main.c file3.txt file4.xt

The program rejects files that do not have the `.txt` extension.

### Example: Duplicate Files

Input:

    ./a.out file1.txt file2.txt main.c file2.txt file1.txt

The program reports duplicate file names and avoids inserting them again.

---

## Data Storage

The application uses a database file, such as `backup.txt`, to save indexed information.

- The database stores words and their associated file details.
- File details include file names and the number of occurrences of each word.
- The saved database can be loaded later using the update option.
- Additional input files can be indexed to update the existing database.

---

## Learning Outcomes

- Improved understanding of C programming.
- Learned how inverted indexing works.
- Practiced linked-list operations.
- Implemented file handling for reading and saving database information.
- Developed word-searching functionality across multiple files.
- Practiced command-line argument validation and error handling.
- Learned how to maintain word frequencies and file associations.

---

## Author

K. Pavan Kumar
