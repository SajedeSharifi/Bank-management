#ifndef MANAGER_H
#define MANAGER_H
//#include "user.h"
#include "employee.h"
#include "bank.h"
class Manager : public Employee
{
public:
    Manager(string fn, string ln, string un, string pw, string bd, string id);
    void hire_new_Employee();
    void fire_Employee();
    void print_employee_info(string id);
};

#endif // MANAGER_H
