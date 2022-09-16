#ifndef BANK_H
#define BANK_H
#include "customer.h"
#include "loan.h"
#include <vector>
#include "manager.h"
#include "user.h"
#include "facility_officer.h"
class Account;
class Manager;
class Customer;
class Loan;
class Employee;
struct Loan_Form
{
    string accunt_number;
    int interest;
};

class Facility_Officer;

class Bank
{
public:
    Bank();
    ~Bank();
    friend class Employee;
    friend class Manager;
    friend class Facility_Officer;
    friend class Account;

    int get_count_day(){return count_day;};


private:
    int count_day;

    Manager *manager;
    Facility_Officer * facility;
    vector<Account *> accounts;
    vector <Employee *> employees;
    vector <Loan_Form> loan_Forms;
    vector <Loan *> loans;
    vector <Customer *> customers;
    vector <string> reports;
};

#endif // BANK_H
