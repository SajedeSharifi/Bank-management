#include "facility_officer.h"

Facility_Officer::Facility_Officer(string fn, string ln, string un, string pw, string bd, string id) : Employee(fn,ln,un,pw,bd,id)
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

void Facility_Officer::Block_Accounts(string id) {
    bool state = true;
    bool flag = true;
    int index = 0;
    for (unsigned int i = 0; i < b->customers.size() && flag; i++) {
        if (id == b->customers[i]->National_Code) {
            index = i;
            flag = false;
        }
    }
    for (unsigned int j = 0; j < b->customers[index]->accounts.size(); j++) {
        state = false;
        b->customers[index]->accounts[j]->set_account_state(state);
    }
}
void Facility_Officer::print_loan_states(string sn) {
    int index = 0;
    bool flag = true;
    for (unsigned int i = 0; i < b->loans.size() && flag; i++) {
        if (sn == b->loans[i]->get_serial_number()) {
            index = i;
            flag = false;
        }
    }
    if (flag == false) {
        cout << "serial number : " << b->loans[index]->get_serial_number() << endl << endl;
        cout << "loan amount : " << b->loans[index]->get_loan_amount() << endl << endl;
        cout << "number of installment : " << b->loans[index]->get_number_of_installments() << endl << endl;
        cout << "amount of interest : " << b->loans[index]->get_loan_interest() << endl << endl;
        cout << "amount per installment : " << b->loans[index]->get_amount_per_installment() << endl << endl;
        cout << "number of paid installments : " << b->loans[index]->get_number_of_paid_installments() << endl << endl;
        cout << "number of overdue installments : " << b->loans[index]->get_num_of_overdue_installments() << endl << endl;
    }
}
//bool Facility_Officer::check_loan_application() {
//    for (unsigned int i = 0; i < b->loan_Forms.size(); i++) {

//    }
//}

void Facility_Officer::Print_loan_requests(){
    for (unsigned int i = 0; i < b->loan_Forms.size(); i++) {
        cout << "Account Number : " << b->loan_Forms[i].accunt_number << endl << endl;
        cout << "Loan interest : " << b->loan_Forms[i].interest << endl << endl;
    }
}
