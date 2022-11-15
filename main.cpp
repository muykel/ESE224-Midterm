#include "Student.h"
#include "Book.h"
#include "Teacher.h"

using namespace std;

int main() {
        fstream search;
        cout << "\n\n\t\t\t *****Libraray Management System Login Page*****\n\n\n" << endl;
        cout << "Current time is:  ";
        auto givetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        cout << ctime(&givetime) << endl;
        cout << givetime;

        ifstream bookin;
        bookin.open("book.txt");
        if (bookin.fail())
        {
                cerr << "Can not open book file";
                exit(1);
        }
        ifstream studentin;
        studentin.open("student.txt");
        if (studentin.fail())
        {
                cerr << "Can not open student file";
                exit(1);
        }
        // User authentication
        // string user, pass;
        // cout << "Enter your username and password:" << endl;
        // cin >> user >> pass;

}
