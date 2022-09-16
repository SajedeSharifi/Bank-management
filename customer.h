#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "user.h"
#include "account.h"
#include "loan.h"
#include "bank.h"

class Account;
class Bank;

class Customer : public User
{
public:
    Customer(string fn, string ln, string un, string pw, string bd, string nc);
    void increase_account_balance();
    void withdraw_from_account();
    void loan_request();
    void print_personal_info();
    void print_accounts_info();
    void print_loans_info();
    string get_id() {return National_Code;}
    friend class Employee;
    friend class Manager;
    friend class Facility_Officer;

private:
    string National_Code;
    vector<Account *> accounts;
    vector<Loan *> loans;
    Bank *b;

};

#endif // CUSTOMER_H
