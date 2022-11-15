#include "Student.h"
#include "Book.h"
#include "Teacher.h"

using namespace std;

int main() {
        // Initializing time aspect of program.
        fstream search;
        cout << "\n\n\t\t\t *****Libraray Management System Login Page*****\n\n\n" << endl;
        cout << "Current time is:  ";
        auto givetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
        cout << ctime(&givetime) << endl;
        cout << givetime;

        // Checking to see if both book.txt and student.txt files exist and
        // we get no errors opening them.
        ifstream bookin;
        bookin.open("book.txt");
        if (bookin.fail()) {
                cerr << "Can not open book file";
                exit(1);
        }
        ifstream studentin;
        studentin.open("student.txt");
        if (studentin.fail()) {
                cerr << "Can not open student file";
                exit(1);
        }

        // User authenticationm
        // Asking for user information
        cout << "Are you a student or teacher? (Enter 0 for student, and 1 for teacher)" << endl;
        int n;
        cin >> n;
        cout << "Enter your username and password." << endl;
        string user, pass;
        cin >> user >> pass;
        // Create istream here
        // istream = ?
        if(n) {
                // Testing functions for student and teacher
                Teacher t1 = new Teacher(user, pass);
                // istream >> t1;
                t1.setusername("username12345");
                t1.setpassword("password12345");
                // istream << t1;
        } else {
                Student s1 = new Student(user, pass);
                // istream >> s1;
                s1.setusername("username12345");
                s1.setpassword("password12345");
                // istream << s1;
        }

        return 0;
}
