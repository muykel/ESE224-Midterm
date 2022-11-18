#include "Book.h"

using namespace std;

bool fileHandle(string file_name, string input, int indicator);

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

// Setters
void Book::setID(int a) {
        id = a;
}
void Book::setTitle(string a) {
        title = a;
}
void Book::setAuthor(string a) {
        author = a;
}
void Book::setISBN(long int a) {
        isbn = a;
}

// Search functions
bool Book::searchTitle(string file_name, string input) { // 1
        return fileHandle(file_name, input, 1);
}
bool Book::searchAuthor(string file_name, string input) { // 2
        return fileHandle(file_name, input, 2);
}
bool Book::searchISBN(string file_name, long int input) { // 3
        return fileHandle(file_name, to_string(input), 3);
}
bool Book::searchID(string file_name, int input) { // 3
        return fileHandle(file_name, to_string(input), 4);
}

bool fileHandle(string file_name, string input, int indicator) {
        ifstream fin(file_name);
        long int a;
        string b, c, d;
        int e;
        fin >> a >> b >> c >> d >> e;
        while(!fin.eof()) {
                switch(indicator) {
                case 1:
                        if(b == input) {
                                cout << "The book was found!" << endl;
                                fin.close();
                                return true;
                        }
                        break;
                case 2:
                        if(c == input) {
                                cout << "The book was found!" << endl;
                                fin.close();
                                return true;
                        }
                case 3:
                        if(a == stol(input)) {
                                cout << "The book was found!" << endl;
                                fin.close();
                                return true;
                        }
                case 4:
                        if(a == stoi(input)) {
                                cout << "The book was found!" << endl;
                                fin.close();
                                return true;
                        }
                }
                fin >> a >> b >> c >> d >> e;
        }
        fin.close();
        cout << "The book was not found! :(" << endl;
        return false;
}
