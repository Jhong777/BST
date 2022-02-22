#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H
#include <string>
using namespace std;

// EmployeeInfo class
class EmployeeInfo {
    // priavte members for Employee
private:
    int employee_Number;
    //string empName;
    string employee_Last_Name;
    string employee_First_Name;
    int employee_Years_of_Service;

public:
    // default construtor with no parameters
    EmployeeInfo();
    // constructor with four parameters
    EmployeeInfo(int, string, string, int);

    // getters for id and name
    int getEmpID();
    string getLastName();
    string getFirstName();
    int getYearsOfService();

    // oeperator functions for less than, greater than and equal to comparisions 
    bool operator < (const EmployeeInfo& e) {
        if (employee_Number < e.employee_Number) {
            return true;
        }
        return false;
    }

    bool operator > (const EmployeeInfo& e) {
        if (employee_Number > e.employee_Number) {
            return true;
        }
        return false;
    }

    bool operator == (const EmployeeInfo& e) {
        if (employee_Number == e.employee_Number) {
            return true;
        }
        return false;
    }
};

#endif