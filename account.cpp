#include "account.h"
#include "bank.h"

Account::Account(string _Account_Number , string _Opening_Date , long long int _Account_Balance , bool _Active , int _Count_number_days)
{
    Account_Number=_Account_Number;
    Opening_Date=_Opening_Date=
    Account_Balance=_Account_Balance;
    Active=_Active;
    Count_number_days=_Count_number_days;
}

void Account::submit_loan_request(Loan_Form _temp)
{
   b->loan_Forms.push_back(_temp);
}

