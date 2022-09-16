#include "manager.h"

Manager::Manager(string fn, string ln, string un, string pw, string bd, string id) : Employee(fn,ln,un,pw,bd,id)
{

}
void Manager::print_employee_info(string id) {
    int index = 0;
    bool flag = true;
    for (unsigned int i = 0; i < b->employees.size() && flag; i++) {
        if (id == b->employees[i]->get_personal_id_no()) {
            index = i;
            flag = false;
        }
    }
    cout<<"name :"<<b->employees[index]->F_name<<endl;
    cout<<"last name :"<<L_name<<endl;
    cout<<"birth_day is :"<<Birth_date<<endl;
    cout<<"username is "<<Username<<endl;
    cout<<"password is "<<password<<endl;
    cout<<"national code is "<<Personal_ID_No<<endl;
    cout<<"----------------------------------------"<<endl;
}
