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

// borrowBooks();
// returnBooks();

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
void operator <<(string file_name, Teacher& t1) { // file_name << t1
    ofstream fout(file_name, ios::app);
    fout << "1\t" << t1.getusername() << "\t" << t1.getpassword() << endl;
    fout.close();
}
Teacher operator >>(string file_name, Teacher& t1) { // file_name >> t1
    ifstream fin(file_name);
    int n;
    string username, password;
    fin >> n >> username >> password;
    cout << "Reading a teacher from: " << file_name << endl;

    fin >> n >> username >> password;
    while (!fin.eof()) {
        if (n) { // Only return if the person is a teacher.
            t1.setusername(username);
            t1.setpassword(password);
            return t1;
        }
        fin >> n >> username >> password;
    }

    fin.close();
    return t1;
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
