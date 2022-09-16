#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include <string>

using namespace std;

class Loan
{
public:
    Loan(long long int amount, int interest, long long int installment, int NOinstallment, string serialNo);
    long long int get_loan_amount(){return loan_amount;}
    int get_loan_interest(){return loan_interest;}
    long long int get_amount_per_installment(){return amount_per_installment;}
    int get_number_of_installments(){return num_of_overdue_installments;}
    int get_number_of_paid_installments(){return number_of_paid_installments;}
    int get_num_of_overdue_installments(){return num_of_overdue_installments;}
    string get_serial_number(){return serial_number;}
private:

    long long int loan_amount;
    int loan_interest;
    long long int amount_per_installment;
    int number_of_installments;
    int number_of_paid_installments;
    int num_of_overdue_installments;
    string serial_number;               //8 digits
//    string date;


};

#endif // LOAN_H
