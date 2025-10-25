#include <iostream>
#include <limits>
#include "library.h"
#include "book.h"

void displayMenu() {
    std::cout << "\n=== LIBRARY MANAGEMENT SYSTEM ===\n";
    std::cout << "1. Add New Book\n";
    std::cout << "2. Remove Book\n";
    std::cout << "3. Search Books\n";
    std::cout << "4. Display All Books\n";
    std::cout << "5. Update Book Information\n";
    std::cout << "6. Generate Reports\n";
    std::cout << "7. Save and Exit\n";
    std::cout << "8. Exit Without Saving\n";
    std::cout << "Enter your choice (1-8): ";
}

Book getBookInput() {
    std::string isbn, title, author, genre;
    int year;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);

    std::cout << "Enter Title: ";
    std::getline(std::cin, title);

    std::cout << "Enter Author: ";
    std::getline(std::cin, author);

    std::cout << "Enter Genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter Publication Year: ";
    std::cin >> year;

    return Book(isbn, title, author, genre, year);
}

int main() {
    Library library;
    const std::string filename = "library_data.txt";

    // Load existing data
    library.loadFromFile(filename);

    int choice;
    bool running = true;
    bool saveData = true;

    while (running) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Book newBook = getBookInput();
                library.addBook(newBook);
                break;
            }
            case 2: {
                std::string isbn;
                std::cout << "Enter ISBN of book to remove: ";
                std::cin >> isbn;
                library.removeBook(isbn);
                break;
            }
            case 3:
                library.searchBooks();
                break;
            case 4:
                library.displayAllBooks();
                break;
            case 5: {
                std::string isbn;
                std::cout << "Enter ISBN of book to update: ";
                std::cin >> isbn;
                library.updateBook(isbn);
                break;
            }
            case 6:
                library.generateReports();
                break;
            case 7:
                library.saveToFile(filename);
                running = false;
                break;
            case 8:
                std::cout << "Are you sure you want to exit without saving? (y/n): ";
                char confirm;
                std::cin >> confirm;
                if (confirm == 'y' || confirm == 'Y') {
                    saveData = false;
                    running = false;
                }
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if (saveData) {
        library.saveToFile(filename);
    }

    std::cout << "Thank you for using Library Management System!\n";
    return 0;
}
