#include "EmployeeInfo.h"
#include "EmployeeTree.h"
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

int main() {
    // creating employee tree 
    EmployeeTree tree;

    //create object of EmployeeInfo 
    EmployeeInfo emp;
    
    //append nodes to tree
    string line;
    ifstream fin;

    //reading the data from text Employee.txt
    fin.open("Employee.txt");
    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            stringstream sStream(line);
            int emp_number, emp_year_of_service;
            string first_name, last_name;
            sStream >> emp_number;
            sStream >> last_name;
            sStream >> first_name;
            sStream >> emp_year_of_service;
            tree.insertNode(EmployeeInfo(emp_number, last_name, first_name, emp_year_of_service));

        }
    }
    
//command functionality
    string command;
    cout << "Please enter desired functionality" << endl;
    cout << "1. Allows the user to Add an employee to the list, Enter ADD" << endl;
    cout << "2. Allows the user to Remove an employee from the list, Enter REMOVE" << endl;
    cout << "3. Returns the number of employees in the list, Enter COUNT" << endl;
    cout << "4. Prints the employee information in the list to the console, Enter PRINT" << endl;
    cout << "5. Stops processing, Enter QUIT" << endl;
    cin >> command;
    cout << "<------------------------------------------------------------------------------------->" << endl;
    while (command != "QUIT")
    {

        //print functionality
        if (command == "PRINT")
            // displaying the inorder traversal for the tree
            tree.displayInOrder();

        //add functionality
        if (command == "ADD")
        {
            int emp_number, emp_year_of_service;
            string first_name, last_name;
            cout << "Enter Employee Number: ";
            cin >> emp_number;
            cout << "Enter Last Name: ";
            cin >> last_name;
            cout << "Enter First Name: ";
            cin >> first_name;
            cout << "Enter Year of Service: ";
            cin >> emp_year_of_service;
            tree.insertNode(EmployeeInfo(emp_number, last_name, first_name, emp_year_of_service));
        }

        //remove functionality
        if (command == "REMOVE")
        {
            int emp_number, emp_year_of_service;
            string first_name, last_name;
            cout << "Enter Employee Number: ";
            cin >> emp_number;
            cout << "Enter Last Name: ";
            cin >> last_name;
            cout << "Enter First Name: ";
            cin >> first_name;
            cout << "Enter Year of Service: ";
            cin >> emp_year_of_service;
            tree.remove(EmployeeInfo(emp_number, last_name, first_name, emp_year_of_service));
    
        }

        //count functionality
        if (command == "COUNT") cout << "\nThe Number of employees in the BST is: " << tree.size() << "\n";

        //enter command again
        cout << "\nEnter desired command -> ADD, REMOVE, COUNT, PRINT, QUIT: ";
        cin >> command;
        cout << "<-------------------------------------------------------------------------------------> " << endl;
    }
    // displaying the inorder traversal for the tree
    tree.displayInOrder();

    

    return 0;
}