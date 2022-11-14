#include "Book.h"

using namespace std;

// Default constructor
Book::Book() {
        isbn = 0;
        id = 0;
        startdate = 0;
        expdate = 0;
        title = "N/A";
        category = "N/A";
        author = "N/A";
        reader = "N/A";
}

Book::Book(long int a, int b, int c, int d, string e, string f, string g, string h) {
        isbn = a;
        id = b;
        startdate = c;
        expdate = d;
        title = e;
        category = f;
        author = g;
        reader = h;
}

// Accessors
long int Book::getISBN() {
        return isbn;
}
int Book::getID() {
        return id;
}
int Book::getstartdate() {
        return startdate;
}
int Book::getenddate() {
        return expdate;
}
string Book::gettitle() {
        return title;
}
string Book::getcategory() {
        return category;
}
string Book::getauthor() {
        return author;
}
string Book::getreader() {
        return reader;
}

void Book::setID(int a) {
        id = a;
}
