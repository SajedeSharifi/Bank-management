#include <iostream>
#include <time.h>
#include "user.h"
#include "employee.h"
using namespace std;


void print_menu() {
    cout << "Please choose one of the options : " << endl << endl;
    cout << "1 : Employee" << endl << endl;
    cout << "2 : Customer" << endl << endl;
    cout << "3 : Exit" << endl << endl;
}
int main()
{
//    Employee e;
//    e.Request_for_overtime();
//    vector <int> my;
//    my.push_back(1);
//    cout<<my.size()<<endl;

    string a;
    srand(time(0));
    for(int i=0 ; i<9 ;i++)
    {
        a+=to_string(rand() %10);
    }

    cout<<a<<endl;

    return 0;
}

