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
        // cout << givetime;

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
        string perms;
        if(n) { // Testing functions for student and teacher

                perms = "Teacher";
                Teacher t1(user, pass);
                // istream >> t1;
                // t1.setusername("username12345");
                // t1.setpassword("password12345");
                // istream << t1;
        } else {
                perms = "Student";
                Student s1(user, pass);
                // istream >> s1;
                // s1.setusername("username12345");
                // s1.setpassword("password12345");
                // istream << s1;
        }

        cout << "Welcome back, " << perms << endl;

        int inp;
        while(1) {
                cout << "What would you like to do?" << endl;
                cout << "1 -- Search Book" << endl;
                cout << "2 -- Borrow Book" << endl;
                cout << "3 -- Return Book" << endl;
                cout << "4 -- Request Copy (Teachers only)" << endl;
                cout << "5 -- Delete copy (Teachers only)" << endl;
                cout << "0 -- Log out" << endl;
                cin >> inp;
                switch(inp) {
                case 0:
                        cout << "Logging out...";
                        exit(1);
                case 1:
                        //
                        break;
                case 2:
                        //
                        break;
                case 3:
                        //
                        break;
                case 4:
                        //
                        break;
                case 5:
                        //
                        break;
                default:
                        cout << "Option not found. Exiting program.";
                        exit(1);
                }
        }

        return 0;
}
