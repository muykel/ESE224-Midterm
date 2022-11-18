#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <chrono>
#include <math.h>
// #pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Book {
private:
long int isbn;
int id, startdate, expdate;
string title, category, author, reader;
public:
Book();
Book(long int a, int b, int c, int d, string e, string f, string g, string h);
long int getISBN();
int getID();
int getstartdate();
int getenddate();
string gettitle();
string getcategory();
string getauthor();
string getreader();
void setID(int a);
void setTitle(string a);
void setAuthor(string a);
void setISBN(long int a);
bool searchTitle(string file_name, string input);
bool searchAuthor(string file_name, string input);
bool searchISBN(string file_name, long int input);
bool searchID(string file_name, int input);
};
