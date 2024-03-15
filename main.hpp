#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to write employee information to file
int writeFile(const string& filename) {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    // Open file for writing
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return -1;
    }

    outFile << numEmployees << endl; // Write number of employees to the file

    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, department;
        double salary;

        cout << "Enter details for employee #" << i + 1 << ":\n";
        cout << "Employee ID: ";
        cin >> id;
        cout << "Employee Name: ";
        cin >> name;
        cout << "Department Name: ";
        cin >> department;
        cout << "Salary: ";
        cin >> salary;

        // Write employee details to the file
        outFile << id << " " << name << " " << department << " " << salary << endl;
    }

    outFile.close(); // Close the file
    return numEmployees;
}

// Function to read employee information from file
int readFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file for reading!" << endl;
        return -1;
    }

    int numEmployees;
    inFile >> numEmployees; // Read number of employees from file

    cout << "ID\tName\tDepartment\tSalary\n";
    double totalSalary = 0.0;

    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, department;
        double salary;

        inFile >> id >> name >> department >> salary;
        totalSalary += salary;
        cout << id << "\t" << name << "\t" << department << "\t" << salary << "\n";
    }

    inFile.close();

    double averageSalary = totalSalary / numEmployees;

    cout << "\t\tTotal: " << totalSalary << " Average: " << averageSalary << endl;

    return numEmployees;
}


/***************************************************
 * Code your program here
 ***************************************************/