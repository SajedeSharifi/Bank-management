TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        account.cpp \
        bank.cpp \
        customer.cpp \
        employee.cpp \
        facility_officer.cpp \
        loan.cpp \
        main.cpp \
        manager.cpp \
        user.cpp

HEADERS += \
    account.h \
    bank.h \
    customer.h \
    employee.h \
    facility_officer.h \
    loan.h \
    manager.h \
    user.h
