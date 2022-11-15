#include "Teacher.h"

using namespace std;

int binarySearch(vector<Book> copies, int l, int r, int x);

// Default
Teacher::Teacher() {
        username = "N/A";
        password = "N/A";
        maxCopies = 10;
        maxBorrowPeriod = 50;
        vector<Book> copies;
        vector<Book> borrows;
}

Teacher::Teacher(string u, string p) {
        username = u;
        password = p;
        maxCopies = 10;
        maxBorrowPeriod = 50;
        vector<Book> copies;
        vector<Book> borrows;
}

// Accessors
string Teacher::getusername() {
        return username;
}
string Teacher::getpassword() {
        return password;
}
int Teacher::getmaxcopies() {
        return maxCopies;
}
int Teacher::getmaxborrowperiod() {
        return maxBorrowPeriod;
}
vector<Book> Teacher::getcopies() {
        return copies;
}
vector<Book> Teacher::getborrows() {
        return borrows;
}

// Mutators
void Teacher::setusername(string a) {
        username = a;
}
void Teacher::setpassword(string a) {
        password = a;
}

void Teacher::borrowbooks(int id) {
        for (int i = 0; i < int(borrows.size()); i++) {
                if (borrows[i].getenddate()) {
                        cout << "You are unable to check out a new book."
                             << "A book is currently overdue." << endl;
                }
        }
        if (int(borrows.size()) > maxCopies) {
                cout << "You are unable to check out a new book."
                     << "You are at max number of copies." << endl;
        }
        Book b1;
        b1.setID(id);
        borrows.push_back(b1);
}
void Teacher::returnbooks(int id) {
        int pos = binarySearch(borrows, 0, int(borrows.size()) - 1, id);
        borrows.erase(borrows.begin() + pos);
}

// Other
void Teacher::requestcopy(long int isbn, string title, string author, string category) {
        int id = int(copies.size()) + 1; // Generating ID for new copy.
        copies.push_back(Book(isbn, id, 0, 0, title, category, author, "N/A"));
}
void Teacher::deletecopy(int id) {
        int pos = binarySearch(copies, 0, int(copies.size()) - 1, id);
        copies.erase(copies.begin() + pos);
}

// Overloading operators
ostream& operator <<(ostream& output, Teacher& t) {
        cout << "Information about the teacher read in..." << endl;
        cout << "1\t" << t.getusername() << "\t" << t.getpassword() << endl;
        return output;
}

istream& operator >>(istream& input, Teacher &t) {
        int n;
        string username, password;
        cout << "Reading all Teachers from input:" << endl;
        input >> n >> username >> password;
        while (!fin.eof()) {
                if (n && t.getusername() == username && t.getpassword() == password) {
                        cout << "Teacher has been found in the input file!" << endl;
                        return input;
                }
                input >> n >> username >> password;
        }
        cout << "Teacher has not been found in the input file!" << endl;
        return input;
}

// Binary Search (copies vector is sorted?)
int binarySearch(vector<Book> copies, int l, int r, int x) {
        if (r >= l) {
                int mid = l + (r - l) / 2;
                if (copies[mid].getID() == x) {
                        return mid;
                }
                if (copies[mid].getID() > x)
                        return binarySearch(copies, l, mid - 1, x);
                return binarySearch(copies, mid + 1, r, x);
        }
        return -1; // Element does not exist.
}
