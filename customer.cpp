#include "customer.h"

class Money_negative{};

Customer::Customer(string fn, string ln, string un, string pw, string bd, string nc) : User()
{
    if (fn.length() < 3 || ln.length() < 3) {
        throw Error("Error : Invalid First Name or Last Name!");
    }
    F_name = fn;
    L_name = ln;

    if (un.length() < 6 || un.length() > 50) {
        throw Error ("Error : Invalid size for username!");
    }
    if (!valid_char(un)) {
        throw Error ("Error : Invalid character!");
    }

    Username = un;

    if (pw.length() < 8 || pw.length() > 32) {
        throw Error ("Error : Invalid size for password!");
    }
    if (!valid_char(pw)) {
        throw Error ("Error : Invalid character!");
    }
    password = pw;

    if (!is_valid_date(bd)) {
        throw Error ("Error : Invalid Date!");
    }
    Birth_date = bd;

    if(nc.length()!=10)
        throw Error ("Error : Invalid size for national code!");
    National_Code=nc;

}

void Customer::increase_account_balance()
{
    string temp_Account_Number=0;
    int index = 0;
    bool flag=1;
    int amount_money=0;
    cout<<"Enter your account number : "<<endl;
    cin>>temp_Account_Number;
    for(unsigned int i=0 ; i<accounts.size() && flag; i++)
    {
        if(temp_Account_Number == accounts[i]->get_Account_Number())
        {
            index=i;
            flag=0;
        }
    }
    if (flag == 1) {
        cerr << "Error : This account is not availabe!" << endl << endl;
    }

    cout<<"How much do you want to deposit into your account ? "<<endl;
    cin>>amount_money;
    if(amount_money <=0 )
    {
        cout<<"The amount of money can not be negative !!!"<<endl;
    }
    else
    {
        accounts[index]->Account_Balance+=amount_money;

    }
}

void Customer::withdraw_from_account()
{
    string  temp_Account_Number=0;
    int index=-1;
    bool flag=1;
    int amount_money=0;
    cout<<"Enter your account number : "<<endl;
    cin>>temp_Account_Number;
    for(unsigned int i=0 ; i<accounts.size() && flag; i++)
    {
        if(temp_Account_Number == accounts[i]->get_Account_Number())
        {
            index=i;
            flag=0;
        }
    }
    if (flag == 1) {
        cerr << "Error : This account is not availabe!" << endl << endl;
    }

    cout<<"How much do you wnat to withdraw from your account?  "<<endl;
    cin>>amount_money;
    if(amount_money<=0)
    {
        cout<<"The amount of money can not be negative !!!"<<endl;
    }
    else if(amount_money>0)
    {
        if(accounts[index]->Active == false)
        {
            cout<<"This account is blocked !!!"<<endl;
        }
        else if(accounts[index]->Account_Balance<amount_money)
        {
            cout<<"Account balance is not enough ! "<<endl;
        }
        else
            accounts[index]->Account_Balance-=amount_money;
    }

}

void Customer::print_personal_info()
{
    cout<<"Display personal information  : "<<endl;
    cout<<"name is :"<<F_name<<endl;
    cout<<"last name is :"<<L_name<<endl;
    cout<<"birth_day is :"<<Birth_date<<endl;
    cout<<"username is "<<Username<<endl;
    cout<<"password is "<<password<<endl;
    cout<<"national code is "<<National_Code<<endl;
    cout<<"----------------------------------------"<<endl;
}

void Customer::print_accounts_info()
{
    string temp_Account_Number=0;
    int index=-1;
    bool flag=1;
    cout<<"Enter your account number : "<<endl;
    cin>>temp_Account_Number;
    for(unsigned int i=0 ; i<accounts.size() && flag; i++)
    {
        if(temp_Account_Number == accounts[i]->get_Account_Number())
        {
            index=i;
            flag=0;
        }
    }

    cout<<"Your inventory is : "<<accounts[index]->Account_Balance<<endl;
    cout<<"accunt number is : "<<accounts[index]->Account_Number<<endl;
    cout<<"Account reopening date is :"<<accounts[index]->Opening_Date<<endl;

}

void Customer::print_loans_info()
{
        string loan_serial_number=0;
        int index=-1;
        bool flag=1;
        cout<<"Enter the loan serial number : "<<endl;
        cin>>loan_serial_number;
        for(unsigned int i=0 ; i<loans.size() && flag; i++)
        {
            if(loan_serial_number == loans[i]->get_serial_number())
            {
                index=i;
                flag=0;
            }
        }

        cout<<"serial number is : "<<loans[index]->get_serial_number()<<endl;
        cout<<"loan amount is : "<<loans[index]->get_loan_amount()<<endl;
        cout<<"loan interest is : "<<loans[index]->get_loan_interest()<<endl;
        cout<<"number of installments is : "<<loans[index]->get_number_of_installments()<<endl;
        cout<<"amount per installment is : "<<loans[index]->get_amount_per_installment()<<endl;
        cout<<"number of paid installments is : "<<loans[index]->get_number_of_paid_installments()<<endl;
        cout<<"number of overdue installments is : "<<loans[index]->get_num_of_overdue_installments()<<endl;
}

void Customer::loan_request()
{
    string temp_Account_Number=0;
    int index;
    bool flag=1;
    cout<<"Enter your account number : "<<endl;
    cin>>temp_Account_Number;
    for(unsigned int i=0 ; i<accounts.size() && flag; i++)
    {
        if(temp_Account_Number == accounts[i]->get_Account_Number())
        {
            index=i;
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<"is not  account number !!!"<<endl;
    }
    else
    {
        int interest;
        cout<<"enter interest :" <<endl;
        cin>>interest;
        if(interest == 4 || interest==12 || interest==8 )
        {
            Loan_Form temp;
            temp.accunt_number=temp_Account_Number;
            temp.interest=interest;
            accounts[index]->submit_loan_request(temp);

        }
        else
            cout<<"is not valid !!!"<<endl;
    }

}





