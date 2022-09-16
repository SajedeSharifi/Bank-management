#ifndef FACILITY_OFFICER_H
#define FACILITY_OFFICER_H
//#include "user.h"
#include "employee.h"
#include "loan.h"
#include "bank.h"

class Facility_Officer : public Employee
{
public:
    Facility_Officer(string fn, string ln, string un, string pw, string bd, string id);
    void Block_Accounts(string id);
    void Print_loan_requests();
    bool check_loan_application();
    void print_loan_states(string sn);          //sn : serial number
};

#endif // FACILITY_OFFICER_H
