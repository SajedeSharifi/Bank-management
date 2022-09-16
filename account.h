#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"user.h"
#include "bank.h"

struct Loan_Form;
class Bank;

class Account
{
public:
    Account(string _Account_Number , string _Opening_Date , long long int _Account_Balance , bool _Active , int _Count_number_days);
    string get_Account_Number(){return Account_Number;}
    void submit_loan_request(Loan_Form _temp);
    void set_account_state(bool state) {Active = state;}
    friend class Customer;
private:
    string Account_Number;
    string Opening_Date;
    int Count_number_days;
    long long int Account_Balance;
    bool Active;
    Bank *b;
};

#endif // ACCOUNT_H
