#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "user.h"
#include "bank.h"
class Bank;

class Employee : public User
{
public:
    Employee(string fn, string ln, string un, string pw, string bd, string id);
    void Request_leave();
    void Request_for_overtime();
    void Display_personal_information();
    void Display_customer_information();
    void Add_new_Account();
    void give_information_account(int index_customer);
    void give_new_information_Customer();
    void Delete_Account();
    void Delete_Customer();
    string get_personal_id_no() {return Personal_ID_No;}
protected:
    string Personal_ID_No;                  //3 digits
//    long long int Basic_salary_received;
    long long int salary;
    int Vacation_Hours;
    int Overtime_Hours;
    Bank *b;
};

#endif // EMPLOYEE_H
