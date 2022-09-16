#include "loan.h"

Loan::Loan(long long int amount, int interest, long long int installment, int NOinstallment, string serialNo)
{
    loan_amount = amount;
    loan_interest = interest;
    number_of_installments = NOinstallment;
    amount_per_installment = installment;
    serial_number = serialNo;
}
