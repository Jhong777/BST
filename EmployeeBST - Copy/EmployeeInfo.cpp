#include "EmployeeInfo.h"
// intializes EmployeeInfo with default values
EmployeeInfo::EmployeeInfo() {
    employee_Number = 0;
    employee_Last_Name = "";
    employee_First_Name = "";
    employee_Years_of_Service = 0;

}

// Intitializaion of EmployeeInfo
EmployeeInfo::EmployeeInfo(int ID, string fname, string lname, int yrsOfService) {
    employee_Number = ID;
    employee_Last_Name = lname;
    employee_First_Name = fname;
    employee_Years_of_Service = yrsOfService;
}
//getter method
int EmployeeInfo::getEmpID() {
    return employee_Number;
}

//getter method
string EmployeeInfo::getLastName() {
    return employee_Last_Name;
}

//getter method
string EmployeeInfo::getFirstName() {
    return employee_First_Name;
}

//getter method
int EmployeeInfo::getYearsOfService() {
    return employee_Years_of_Service;
}