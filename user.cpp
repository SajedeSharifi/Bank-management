#include "user.h"

//------------------------------------------------------------------------------
bool is_leap_year(int y) {
    int r = y % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int days_of_month(int m, int y) {
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    return 0;
}

bool is_valid_date(string date) {
    int count = 0;
    for (int i = 0; date[i] != '\0'; i++) {
        if (date[i] == '/')
            count++;
    }

    if (count != 2 || date[0] == '/' || date[date.length()-1] == '/') {
        return false;
    }

    for (unsigned int i = 0; i < date.length() - 1; i++) {
        if (date[i] == '/' && date[i+1] == '/')
            return false;
    }
    if (date.length() == 0) {
        return false;
    }

    for (unsigned int i = 0; i < date.length(); i++) {
        if (date[i] > '9' || date[i] < '0') {
            if (date[i] != '/')
                return false;
        }
    }

    string td, tm, ty;
    unsigned int i = 0;

    for (; date[i] != '/' ; i++) {
        td += date[i];
    }

    i++;

    for (; date[i] != '/' ; i++) {
        tm += date[i];
    }

    i++;

    for (; i < date.length() ; i++) {
        ty += date[i];
    }

    int d = stoi(td);
    int m = stoi(tm);
    int y = stoi(ty);

    if (y < 0 || m < 1 || m > 12 || d < 1 || d > days_of_month(m, y)) {
        return false;
    }
    return true;
}

bool valid_char(string input) {
    for (unsigned int i = 0; i < input.length(); i++) {
        if ((input.at(i) < 64 || input.at(i) > 90) &&
                (input.at(i) < 97 || input.at(i) > 122) &&
                (input.at(i) < 48 || input.at(i) > 57) &&
                (input.at(i) != 43 || input.at(i) != 45 ||
                 input.at(i) != 46 || input.at(i) != 95 || input.at(i) == 32)) {
            return false;
        }
    }
    return true;
}

bool valid_id(string id) {
    for(unsigned int i = 0; i < id.length(); i++) {
        if (id.at(i) < 48 || id.at(i) > 57) {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------

User::User()
{

}

void User::take_F_name_L_name()
{
    string _F_name,_L_name;
    cout << "Tell us your first name : " << endl;
    cin >> _F_name;
    cout << "Tell us your last name : " << endl;
    cin >>_L_name;
    try {
        if (_F_name.length()< 3 || _L_name.length() < 3)
            throw Error("Invalid First Name or Last Name hase been entered!!!");

        F_name = _F_name;
        L_name = _L_name;
    }
    catch (Error er) {
        cout << "Please Try again" << endl << endl;
        take_F_name_L_name();
    }
}

void User::take_username()
{
    //در صورت وجود تراي كچ گذاشته ميشود
    string _username;
    cout << "Enter your username : ";
    cin >> _username;
    cout << endl << endl;
    Username = _username;
}
void User::take_password()
{
    //در صورت وجود تراي كچ گذاشته ميشود
    string _password;
    cout << "Enter your password : ";
    cin >> _password;
    cout << endl << endl;
    password = _password;
}
void User::take_Birth_date(string d) {

    bool not_valid = true;
    while (not_valid) {
        try {

            if (!is_valid_date(d)) {
                throw Error ("Error : Invalid type of date!");
            }
            Birth_date = d;
            not_valid = false;
        }
        catch (Error ex) {
            cout << "Try Again!" << endl << endl;
        }
    }
}
