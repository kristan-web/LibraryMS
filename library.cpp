#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <sstream>

// Core functionalities
void Library::addBook(const Book& book) {
    if (isISBNExists(book.getISBN())) {
        std::cout << "Error: Book with ISBN " << book.getISBN() << " already exists!\n";
        return;
    }
    books.push_back(book);
    std::cout << "Book added successfully!\n";
}

bool Library::removeBook(const std::string& isbn) {
    auto it = std::find_if(books.begin(), books.end(),
        [&isbn](const Book& book) { return book.getISBN() == isbn; });

    if (it != books.end()) {
        books.erase(it);
        std::cout << "Book removed successfully!\n";
        return true;
    }
    std::cout << "Error: Book with ISBN " << isbn << " not found!\n";
    return false;
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }

    std::cout << "\n" << std::string(100, '=') << "\n";
    std::cout << std::left << std::setw(15) << "ISBN"
              << std::setw(25) << "Title"
              << std::setw(20) << "Author"
              << std::setw(15) << "Genre"
              << std::setw(10) << "Year"
              << std::setw(12) << "Status"
              << std::endl;
    std::cout << std::string(100, '=') << "\n";

    for (const auto& book : books) {
        book.display();
    }
    std::cout << std::string(100, '-') << "\n";
    std::cout << "Total books: " << books.size() << std::endl;
}

void Library::updateBook(const std::string& isbn) {
    Book* book = searchByISBN(isbn);
    if (!book) {
        std::cout << "Book not found!\n";
        return;
    }

    std::cout << "Current book details:\n";
    book->displayBrief();

    int choice;
    std::string input;
    int year;

    do {
        std::cout << "\nWhat would you like to update?\n";
        std::cout << "1. Title\n2. Author\n3. Genre\n4. Publication Year\n5. Availability\n6. Finish Update\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter new title: ";
                std::getline(std::cin, input);
                book->setTitle(input);
                break;
            case 2:
                std::cout << "Enter new author: ";
                std::getline(std::cin, input);
                book->setAuthor(input);
                break;
            case 3:
                std::cout << "Enter new genre: ";
                std::getline(std::cin, input);
                book->setGenre(input);
                break;
            case 4:
                std::cout << "Enter new publication year: ";
                std::cin >> year;
                book->setPublicationYear(year);
                break;
            case 5:
                std::cout << "Set availability (1 for Available, 0 for Checked Out): ";
                std::cin >> year;
                book->setAvailability(year == 1);
                break;
            case 6:
                std::cout << "Update completed!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

// Search functionalities
std::vector<Book*> Library::searchByTitle(const std::string& title) {
    std::vector<Book*> results;
    for (auto& book : books) {
        if (book.getTitle().find(title) != std::string::npos) {
            results.push_back(&book);
        }
    }
    return results;
}

std::vector<Book*> Library::searchByAuthor(const std::string& author) {
    std::vector<Book*> results;
    for (auto& book : books) {
        if (book.getAuthor().find(author) != std::string::npos) {
            results.push_back(&book);
        }
    }
    return results;
}

std::vector<Book*> Library::searchByGenre(const std::string& genre) {
    std::vector<Book*> results;
    for (auto& book : books) {
        if (book.getGenre().find(genre) != std::string::npos) {
            results.push_back(&book);
        }
    }
    return results;
}

Book* Library::searchByISBN(const std::string& isbn) {
    for (auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

// Const version of searchByISBN for use in const functions
const Book* Library::searchByISBN(const std::string& isbn) const {
    for (const auto& book : books) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

void Library::searchBooks() {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }

    int choice;
    std::string query;

    std::cout << "\nSearch by:\n";
    std::cout << "1. ISBN\n2. Title\n3. Author\n4. Genre\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();

    std::cout << "Enter search term: ";
    std::getline(std::cin, query);

    std::vector<Book*> results;

    switch (choice) {
        case 1:
            {
                Book* book = searchByISBN(query);
                if (book) results.push_back(book);
            }
            break;
        case 2:
            results = searchByTitle(query);
            break;
        case 3:
            results = searchByAuthor(query);
            break;
        case 4:
            results = searchByGenre(query);
            break;
        default:
            std::cout << "Invalid choice!\n";
            return;
    }

    if (results.empty()) {
        std::cout << "No books found matching your search.\n";
        return;
    }

    std::cout << "\nFound " << results.size() << " book(s):\n";
    std::cout << std::string(80, '-') << "\n";
    for (const auto& book : results) {
        book->displayBrief();
    }
}

// Sorting functions
void Library::sortByTitle() {
    std::sort(books.begin(), books.end());
}

void Library::sortByAuthor() {
    std::sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) { return a.getAuthor() < b.getAuthor(); });
}

void Library::sortByPublicationYear() {
    std::sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) { return a.getPublicationYear() < b.getPublicationYear(); });
}

void Library::sortByGenre() {
    std::sort(books.begin(), books.end(),
        [](const Book& a, const Book& b) { return a.getGenre() < b.getGenre(); });
}

// Report generation
void Library::generateReports() {
    int choice;
    do {
        std::cout << "\n=== REPORT GENERATION ===\n";
        std::cout << "1. Availability Report\n";
        std::cout << "2. Genre-wise Report\n";
        std::cout << "3. Author-wise Report\n";
        std::cout << "4. Sorted Display (by Title)\n";
        std::cout << "5. Sorted Display (by Author)\n";
        std::cout << "6. Sorted Display (by Year)\n";
        std::cout << "7. Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: generateAvailabilityReport(); break;
            case 2: generateGenreReport(); break;
            case 3: generateAuthorReport(); break;
            case 4: sortByTitle(); displayAllBooks(); break;
            case 5: sortByAuthor(); displayAllBooks(); break;
            case 6: sortByPublicationYear(); displayAllBooks(); break;
            case 7: break;
            default: std::cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}

void Library::generateAvailabilityReport() {
    int available = 0, checkedOut = 0;

    for (const auto& book : books) {
        if (book.getAvailability()) available++;
        else checkedOut++;
    }

    std::cout << "\n=== AVAILABILITY REPORT ===\n";
    std::cout << "Total Books: " << books.size() << "\n";
    std::cout << "Available: " << available << " (" << (books.size() ? (available * 100 / books.size()) : 0) << "%)\n";
    std::cout << "Checked Out: " << checkedOut << " (" << (books.size() ? (checkedOut * 100 / books.size()) : 0) << "%)\n";

    std::cout << "\nChecked Out Books:\n";
    for (const auto& book : books) {
        if (!book.getAvailability()) {
            book.displayBrief();
        }
    }
}

void Library::generateGenreReport() {
    std::map<std::string, int> genreCount;

    for (const auto& book : books) {
        genreCount[book.getGenre()]++;
    }

    std::cout << "\n=== GENRE-WISE REPORT ===\n";
    for (const auto& [genre, count] : genreCount) {
        std::cout << genre << ": " << count << " books ("
                  << (books.size() ? (count * 100 / books.size()) : 0) << "%)\n";
    }
}

void Library::generateAuthorReport() {
    std::map<std::string, int> authorCount;

    for (const auto& book : books) {
        authorCount[book.getAuthor()]++;
    }

    std::cout << "\n=== AUTHOR-WISE REPORT ===\n";
    for (const auto& [author, count] : authorCount) {
        std::cout << author << ": " << count << " books\n";
    }
}

// File operations
void Library::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "No existing data file found. Starting with empty library.\n";
        return;
    }

    books.clear();
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string isbn, title, author, genre, yearStr, availableStr;

        if (std::getline(ss, isbn, ',') &&
            std::getline(ss, title, ',') &&
            std::getline(ss, author, ',') &&
            std::getline(ss, genre, ',') &&
            std::getline(ss, yearStr, ',') &&
            std::getline(ss, availableStr)) {

            try {
                int year = std::stoi(yearStr);
                bool available = (availableStr == "1" || availableStr == "true");
                Book newBook(isbn, title, author, genre, year, available);
                books.push_back(newBook);
            } catch (const std::exception& e) {
                std::cout << "Error parsing line: " << line << std::endl;
            }
        }
    }

    std::cout << "Loaded " << books.size() << " books from file.\n";
    file.close();
}

void Library::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Error saving to file!\n";
        return;
    }

    for (const auto& book : books) {
        file << book.getISBN() << "," << book.getTitle() << "," << book.getAuthor() << ","
             << book.getGenre() << "," << book.getPublicationYear() << ","
             << (book.getAvailability() ? "1" : "0") << "\n";
    }

    file.close();
    std::cout << "Saved " << books.size() << " books to file.\n";
}

// Utility functions
bool Library::isISBNExists(const std::string& isbn) const {
    return searchByISBN(isbn) != nullptr;
}

int Library::getTotalBooks() const {
    return books.size();
}

int Library::getAvailableBooks() const {
    int count = 0;
    for (const auto& book : books) {
        if (book.getAvailability()) count++;
    }
    return count;
}
