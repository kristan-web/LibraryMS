#include "book.h"
#include <iomanip>

// Constructor implementations
Book::Book() : isbn(""), title(""), author(""), genre(""), publicationYear(0), isAvailable(true) {}

Book::Book(const std::string& isbn, const std::string& title, const std::string& author, 
           const std::string& genre, int year, bool available)
    : isbn(isbn), title(title), author(author), genre(genre), 
      publicationYear(year), isAvailable(available) {}

// Getter implementations
std::string Book::getISBN() const { return isbn; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getGenre() const { return genre; }
int Book::getPublicationYear() const { return publicationYear; }
bool Book::getAvailability() const { return isAvailable; }

// Setter implementations
void Book::setTitle(const std::string& title) { this->title = title; }
void Book::setAuthor(const std::string& author) { this->author = author; }
void Book::setGenre(const std::string& genre) { this->genre = genre; }
void Book::setPublicationYear(int year) { this->publicationYear = year; }
void Book::setAvailability(bool available) { this->isAvailable = available; }

// Display methods
void Book::display() const {
    std::cout << std::left << std::setw(15) << isbn
              << std::setw(25) << title
              << std::setw(20) << author
              << std::setw(15) << genre
              << std::setw(10) << publicationYear
              << std::setw(12) << (isAvailable ? "Available" : "Checked Out") 
              << std::endl;
}

void Book::displayBrief() const {
    std::cout << "ISBN: " << isbn << " | Title: " << title << " | Author: " << author 
              << " | Status: " << (isAvailable ? "Available" : "Checked Out") << std::endl;
}

// Comparison operators
bool Book::operator<(const Book& other) const {
    return title < other.title;
}

bool Book::operator==(const Book& other) const {
    return isbn == other.isbn;
}

// I/O operators
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.isbn << "," << book.title << "," << book.author << ","
       << book.genre << "," << book.publicationYear << "," << book.isAvailable;
    return os;
}

std::istream& operator>>(std::istream& is, Book& book) {
    std::string availability;
    std::getline(is, book.isbn, ',');
    std::getline(is, book.title, ',');
    std::getline(is, book.author, ',');
    std::getline(is, book.genre, ',');
    is >> book.publicationYear;
    is.ignore(); // ignore comma
    is >> availability;
    book.isAvailable = (availability == "1" || availability == "true");
    return is;
}