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

        string file_name = "book.txt";

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

        // if(n) {
        //         perms = "Teacher";
        //         Teacher loggedUser(user, pass);
        // } else {
        //         perms = "Student";
        //         Student loggedUser(user, pass);
        // }

        Teacher t1(user, pass);
        Student s1(user, pass);

        cout << "Welcome back!" << endl;

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
                case 0: { // Log out
                        cout << "Logging out...";
                        exit(1);
                }
                case 1: { // Search book
                        int inp2;
                        cout << "How would you like to search for a book?" << endl;
                        cout << "1 - via title" << endl;
                        cout << "2 - via author" << endl;
                        cout << "3 - via ISBN" << endl;
                        cout << "4 - via ID" << endl;
                        cin >> inp2;
                        Book b1;
                        switch(inp2) {
                        case 1: {
                                string ti;
                                cout << "Enter a title." << endl;
                                cin >> ti;
                                b1.searchTitle(file_name, ti);
                                break;
                        }
                        case 2: {
                                string au;
                                cout << "Enter an author." << endl;
                                cin >> au;
                                b1.searchAuthor(file_name, au);
                                break;
                        }
                        case 3: {
                                long int isbn2;
                                cout << "Enter an ISBN." << endl;
                                cin >> isbn2;
                                b1.searchISBN(file_name, isbn2);
                                break;
                        }
                        case 4: {
                                int id2;
                                cout << "Enter an ID." << endl;
                                cin >> id2;
                                b1.searchID(file_name, id2);
                                break;
                        }
                        }
                        break;
                }
                case 2: { // Borrow book
                        int inp3;
                        cout << "Enter the ID of the book to borrow" << endl;
                        cin >> inp3;
                        if(n) {
                                t1.borrowbooks(inp3);
                        } else {
                                s1.borrowbooks(inp3);
                        }
                        break;
                }
                case 3: { // Return book
                        int inp4;
                        cout << "Enter the ID of the book to return" << endl;
                        cin >> inp4;
                        if(n) {
                                t1.returnbooks(inp4);
                        } else {
                                s1.returnbooks(inp4);
                        }
                        break;
                }
                case 4: { // Request copy
                        if(n) {
                                cout << "Enter the information..." << endl;

                                long int isbn1;
                                cout << "Enter ISBN." << endl;
                                cin >> isbn1;

                                string title1;
                                cout << "Enter title." << endl;
                                cin >> title1;

                                string author1;
                                cout << "Enter author." << endl;
                                cin >> author1;

                                string category1;
                                cout << "Enter category." << endl;
                                cin >> category1;

                                t1.requestcopy(isbn1, title1, author1, category1);
                        } else {
                                cout << "No permission." << endl;
                        }
                        break;
                }
                case 5: { // Delete copy
                        if(n) {
                                int inp5;
                                cout << "Enter the ID of the copy to delete." << endl;
                                cin >> inp5;
                                t1.deletecopy(inp5);
                        } else {
                                cout << "No permission." << endl;
                        }
                        break;
                }
                }
        }
        return 0;
}
