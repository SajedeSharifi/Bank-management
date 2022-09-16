#include "employee.h"
#include "user.h"
#include <time.h>
#include "account.h"
class Account;

Employee::Employee(string fn, string ln, string un, string pw, string bd, string id) : User()
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

    if (id.length() != 3) {
        throw Error ("Error : Personal Id Number must have 3 digits");
    }
    if (!valid_id(id)) {
        throw Error ("Error : Personal Id Number must contain only digits");
    }
    Personal_ID_No = id;

    Vacation_Hours = 15;
    salary = 1000000;
    Overtime_Hours = 12;

}

void Employee::Request_leave() {
    int vh = 0;         //vacation hour
    long long int sal = 0;          //salary
    cout << "How many hours do you need : ";
    cin >> vh;
    if (vh < 0) {
        cerr << "Error : Hours can not be negative!" << endl << endl;
    }
    else if (vh == 0) {
        cout << "Then why are you here exactly? -_-" << endl << endl;
    }
    else if (Vacation_Hours - vh < 0)
    {
        int choice = 0;
        sal = salary;
        for (int i = 0; i < vh - Vacation_Hours; i++) {
            sal -= 100000;
        }
        cout << "Your salary would be : " << sal << endl << endl;
        cout << "Do you still want to take vacation? "
                "(if yes press 1 if not press 0) : ";
        cin >> choice;
        cout << endl << endl;
        if (choice == 0) {
            cout << "See you tomorrow!" << endl << endl;
        }
        else if (choice == 1) {
            salary = sal;
            cout << "Ok your salary would be : " << salary << endl << endl;
            cout << "Have a nice vacation!" << endl << endl;
        }
        else {
            cerr << "wrong number!" << endl << endl;
        }
    }
    else {
        Vacation_Hours -= vh;
        cout << "You have " << Vacation_Hours << " hours left" << endl << endl;
        cout << "Have a nice vacation!" << endl << endl;
    }
}

void Employee::Request_for_overtime(){
    int oh = 0;         //overtime hour
    cout << "How many hours do you request : ";
    cin >> oh;
    cout << endl;
    if (oh < 0) {
        cerr << "Error : Hours can not be negative!" << endl << endl;
    }
    else if (oh == 0) {
        cout << "It's Ok you still have your basic salary" << endl << endl;
    }
    if (Overtime_Hours - oh < 0) {
        cout << "Sorry you can not overwork in this month any more!" << endl << endl;
    }
    else {
        Overtime_Hours -= oh;
        for (int i = 0; i < oh; i++) {
            salary += 120000;
        }
        cout << "Your salary would be : " << salary << endl << endl;
        cout << "Have a nice day!" << endl << endl;
    }
}

void Employee::Display_personal_information()
{
    cout<<"Display of personal information of the employee is : "<<endl;
    cout<<"name is :"<<F_name<<endl;
    cout<<"last name is :"<<L_name<<endl;
    cout<<"birth_day is :"<<Birth_date<<endl;
    cout<<"username is "<<Username<<endl;
    cout<<"password is "<<password<<endl;
    cout<<"national code is "<<Personal_ID_No<<endl;
    cout<<"----------------------------------------"<<endl;
}

void Employee::Display_customer_information()
{
    string customer_national_code=0;
    int index=0;
    bool flag=1;
    cout<<"Enter the customer national code : "<<endl;
    cin>>customer_national_code;
    for(unsigned int i=0 ; i < b->customers.size() && flag; i++)
    {
        if(customer_national_code == b->customers[i]->National_Code)
        {
            index=i;
            flag=0;
        }
    }
    cout<<"Customer information is as follows : "<<endl;
    cout<<"name is :"<<b->customers[index]->F_name<<endl;
    cout<<"last name is :"<<b->customers[index]->L_name<<endl;
    cout<<"birth_day is :"<<b->customers[index]->Birth_date<<endl;
    cout<<"username is "<<b->customers[index]->Username<<endl;
    cout<<"password is "<<b->customers[index]->password<<endl;
    cout<<"national code is "<<b->customers[index]->National_Code<<endl;
    cout<<"----------------------------------------"<<endl;
}

void Employee::Add_new_Account()
{
    string temp_national_code;
    int index_customer;
    bool flag=true;
    cout<<"Enter your national code : "<<endl;
    cin>>temp_national_code;
    for(unsigned int i=0 ; i<b->customers.size() && flag ; i++)
    {
        if(b->customers[i]->National_Code==temp_national_code)
        {
            index_customer=i;
            flag=false;
        }
    }

    if(flag==false)//يعني مشتري قبلا كد ملي ش در دسيستم ثبت شده و الان بايد يه حساب جديد برايش باز كرد.
    {
        give_information_account(index_customer);

    }
    else//مشتري در سيستم نبوده قبلا پس بايد در سيستم مشخصاتش ثبت شود
    {
        give_new_information_Customer();
    }

}

void Employee::give_information_account(int index_customer)
{
    long long int _accunt_balance;
    cout<<"Deposit at least 50,000 Tomans to open an account : "<<endl;
    cin>>_accunt_balance;
    if(_accunt_balance<50000)
        throw Error ("Error : The amount entered must be more than 50,000 Tomans !");


    //ايجاد شماره حساب نه رقمي رندوم
    string accunt_number;
    srand(time(0));
    for(int i=0 ; i<9 ;i++)
    {
        accunt_number+=to_string(rand() %10);
    }

    //چك كردن تكراري بودن شماره حساب
    for(unsigned int i=0 ; i<b->customers.size() ; i++)
    {
        for(unsigned int j=0 ; j < b->customers[i]->accounts.size() ; j++)
        {
            if(b->customers[i]->accounts[j]->get_Account_Number()==accunt_number)
            {
                throw Error ("Error : This account number already exists !");
            }
        }
    }

    //تاريخ باز شدن حساب
    string open_dete=to_string(b->count_day);

    //براي پوش بك
    Account *temp=new Account(accunt_number,open_dete,_accunt_balance,true,0);

    b->customers[index_customer]->accounts.push_back(temp);
    b->accounts.push_back(temp);

}

void Employee::give_new_information_Customer()
{
    string _f_name,_l_name,_code_national,_date,_username,_password;
    bool cheak_code_national=true;
    cout<<"enter your name :"<<endl;
    cin>>_f_name;
    cout<<"enter your last name : "<<endl;
    cin>>_l_name;
    cout<<"enter your code national : "<<endl;
    cin>>_code_national;
    //چك كردن تكراري بودن كد ملي وارد شده از سوي كاربر
    for(unsigned int i=0 ; i < b->customers.size() && cheak_code_national ;i++)
    {
        if(b->customers[i]->National_Code==_code_national)
        {
            cheak_code_national=false;
        }
    }

    if(cheak_code_national==false)
        throw Error("Error : The national code already exists !!");

    //گرفتن تاريخ تولد از كاربر
    cout<<"Enter your date of birth : "<<endl;
    cin>>_date;
    //ميتونه نباشه چون در تابع سازنده معتبر بودن تاريخ تولد چك ميشود
    if(! is_valid_date(_date))
        throw Error ("Error : The date entered is incorrect !!!");

    //پسورد و يوزرنيم در تابع سازنده چك ميشوند
    cout<<"enter your password :"<<endl;
    cin>>_password;
    cout<<"enter your username : "<<endl;
    cin>>_username;

    //موقعيت براي پوش بك كردن مشتري جديد در حساب هايي كه در بانك وجود دارد
    int index_new_customer;
    index_new_customer=b->customers.size()-1;

    give_information_account(index_new_customer);
}

void Employee::Delete_Account()
{
    string _account_number;
    int index_account_number , index_customer;
    bool cheak_account_number=true;
    cout<<"   part delete account   "<<endl<<endl;
    cout<<"enter your account number : "<<endl;
    cin>>_account_number;
    if (b->accounts.size() == 0) {
        throw Error("Error : This bank doesn't have any account!");
    }
    for(unsigned int i=0 ; i<b->customers.size() && cheak_account_number ; i++)
    {
        for(unsigned int j=0 ; b->customers[i]->accounts.size() && cheak_account_number ; j++)
        {
            if(_account_number==b->customers[i]->accounts[j]->get_Account_Number())
            {
                cheak_account_number=false;
                index_account_number=j;
                index_customer=i;
            }
        }
    }

    if(cheak_account_number==true)
        throw Error("Error : There is no such account at all !!");

    delete  b->accounts[index_account_number];

    b->accounts.erase(b->accounts.begin()+index_account_number);
    b->customers[index_customer]->accounts.erase(b->customers[index_customer]->accounts.begin()+index_account_number);

    //براي اينكه ببينه آخرين  حساب كاربر نباشه    delete customer
    if(b->customers[index_customer]->accounts.size()==0)
    {
        delete b->customers[index_customer];

        b->customers.erase(b->customers.begin()+index_customer);
    }
}

void Employee::Delete_Customer()
{

}
