//Student or employee information management 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Employee {
    string ID;
    string name;
    string designation;
    string salary;
public:
    void initData(string i, string n, string d, string a) {
        ID = i;
        name = n;
        designation = d;
        salary = a;
    }

    void writeData() {
        fstream out;
        out.open("employeeinfo.txt", ios::app);
        string entry = ID + " " + name + " " + designation + " " + salary + "\n";
        out << entry;
        out.close();
    }

    void readData() {
        fstream in;
        in.open("employeeinfo.txt", ios::in);
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }
    
    void deleteData(int idToDelete) {
        fstream in, out;
        in.open("employeeinfo.txt", ios::in);
        out.open("temp.txt", ios::out);
        string line;
        while (getline(in, line)) {
            int pos = line.find(' ');
            string idFromLine = line.substr(0, pos);
            int idFromFile = stoi(idFromLine);

            if (idFromFile != idToDelete) {
                out << line << endl;
            }
        }
        
        in.close();
        out.close();
        remove("employeeinfo.txt");
        rename("temp.txt", "employeeinfo.txt");
        }
};

int main() {
    Employee e;
    int choice, id;
    string name, desig, sal;
    do {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Delete Employee by id\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Id: ";
                cin >> id;
                cin.ignore(); 
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Designation: ";
                getline(cin, desig);
                cout << "Enter Salary: ";
                getline(cin, sal);
                e.initData(to_string(id), name, desig, sal);
                e.writeData();
                cout << "Employee added successfully!\n";
            break;
            case 2:
                cout << "All Employees Records:\n";
                e.readData();
            break;
            case 3:
                cout << "Enter Id to delete: ";
                cin >> id;
                e.deleteData(id);
                cout << "Employee deleted successfully!\n";
            break;
            case 4: 
                cout << "Exiting the system.\n";
            break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);
    return 0;
}


