#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    std::string genre;
    int publicationYear;
    bool isAvailable;

public:
    // Constructors
    Book();
    Book(const std::string& isbn, const std::string& title, const std::string& author, 
         const std::string& genre, int year, bool available = true);

    // Getters
    std::string getISBN() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getGenre() const;
    int getPublicationYear() const;
    bool getAvailability() const;

    // Setters
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setGenre(const std::string& genre);
    void setPublicationYear(int year);
    void setAvailability(bool available);

    // Display methods
    void display() const;
    void displayBrief() const;

    // Comparison operators for sorting
    bool operator<(const Book& other) const;
    bool operator==(const Book& other) const;

    // Friend functions for I/O
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);
};

#endif