#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <vector>
#include <string>
#include <algorithm>

class Library {
private:
    std::vector<Book> books;

    // Helper functions for searching
    std::vector<Book*> searchByTitle(const std::string& title);
    std::vector<Book*> searchByAuthor(const std::string& author);
    std::vector<Book*> searchByGenre(const std::string& genre);
    Book* searchByISBN(const std::string& isbn);
    const Book* searchByISBN(const std::string& isbn) const; // Add this const version

    // Sorting functions
    void sortByTitle();
    void sortByAuthor();
    void sortByPublicationYear();
    void sortByGenre();

public:
    // Core functionalities
    void addBook(const Book& book);
    bool removeBook(const std::string& isbn);
    void displayAllBooks() const;
    void updateBook(const std::string& isbn);

    // Search functionalities
    void searchBooks();

    // Report generation
    void generateReports();
    void generateAvailabilityReport();
    void generateGenreReport();
    void generateAuthorReport();

    // File operations
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);

    // Utility functions
    bool isISBNExists(const std::string& isbn) const;
    int getTotalBooks() const;
    int getAvailableBooks() const;
};

#endif
