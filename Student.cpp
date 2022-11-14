#include "Student.h"
#include "Teacher.h"

using namespace std;

int binarySearch(vector<Book> copies, int l, int r, int x);

Student::Student() {
        username = "N/A";
        password = "N/A";
        maxCopies = 5;
        maxBorrowPeriod = 30;
        vector<Book> copies;
        vector<Book> borrows;
}

Student::Student(string u, string p) {
        username = u;
        password = p;
        maxCopies = 5;
        maxBorrowPeriod = 30;
        vector<Book> copies;
        vector<Book> borrows;
}

// Accessors
string Student::getusername() {
        return username;
}
string Student::getpassword() {
        return password;
}
int Student::getmaxcopies() {
        return maxCopies;
}
int Student::getmaxborrowperiod() {
        return maxBorrowPeriod;
}
vector<Book> Student::getcopies() {
        return copies;
}
vector<Book> Teacher::getborrows() {
        return borrows;
}

// Mutators
void Student::setusername(string a) {
        username = a;
}
void Student::setpassword(string a) {
        password = a;
}

void Student::borrowbooks(int id) {
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
void Student::returnbooks(int id) {
        int pos = binarySearch(borrows, 0, int(borrows.size()) - 1, id);
        borrows.erase(borrows.begin() + pos);
}

// Overloading operators
void operator <<(Student&s) { // file_name << t1
        ofstream fout(file_name, ios::app);
        fout << "1\t" << s.getusername() << "\t" << s.getpassword() << endl;
        fout.close();
}
Student operator >>(Student &s) { // file_name >> t1
        ifstream fin(file_name);
        int n;
        string username, password;
        fin >> n >> username >> password;
        cout << "Reading a Student from: " << file_name << endl;

        fin >> n >> username >> password;
        while (!fin.eof()) {
                if (!n) { // Only return if the person is a student.
                        s.setusername(username);
                        s.setpassword(password);
                        return s;
                }
                fin >> n >> username >> password;
        }

        fin.close();
        return s;
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
