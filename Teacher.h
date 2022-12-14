#include "Book.h"

class Teacher {
private:
string username, password;
int maxCopies, maxBorrowPeriod;
vector<Book> copies, borrows;
public:
Teacher();
Teacher(string u, string p);
string getusername();
string getpassword();
int getmaxcopies();
int getmaxborrowperiod();
vector<Book> getcopies();
vector<Book> getborrows();
void setusername(string a);
void setpassword(string a);
void borrowbooks(int id);
void returnbooks(int id);
void requestcopy(long int isbn, string title, string author, string category);
void deletecopy(int id);
};
