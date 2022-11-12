#include "Book.h"

using namespace std;

class Teacher
{
private:
string username, password;
static int maxCopies, maxBorrowPeriod;
vector<Book> copies;
public:
Teacher();
Teacher(string u, string p);
string getusername();
string getpassword();
int getmaxcopies();
int getmaxborrowperiod();
vector<Book> getcopies();
void setusername(string a);
void setpassword(string a);
void borrowbooks(int id);
void returnbooks(int id);
void requestcopy(long int isbn, string title, string author, string category);
void deletecopy(int id);
void operator <<(string file_name, Teacher& t1);
Teacher operator >>(string file_name, Teacher& t1);
};
