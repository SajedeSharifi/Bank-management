#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;

class Error{
public :
    Error(string ex) {
        cout << ex << endl << endl;
    }
};

bool is_leap_year(int y);
int days_of_month(int m, int y);
bool is_valid_date(string date);
bool valid_char(string input);
bool valid_id(string id);

class User
{
public:
    User();
    void take_F_name_L_name();
    void take_username();
    void take_password();
    void take_Birth_date(string d);
    void print_personal_info(string id);
//    friend class Employee;

protected:
    string F_name;
    string L_name;
    string Username;
    string password;
    string Birth_date;
};

#endif // USER_H
