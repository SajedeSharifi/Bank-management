#include "bank.h"

Bank::Bank()
{

}
Bank::~Bank() {
    for (unsigned int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }
    for (unsigned int i = 0; i < customers.size(); i++) {
        delete customers[i];
    }
    for (unsigned int i = 0; i < accounts.size(); i++) {
        delete accounts[i];
    }
    for (unsigned int i = 0; i < loans.size(); i++) {
        delete loans[i];
    }
}
