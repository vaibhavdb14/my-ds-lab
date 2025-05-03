// A Telephone book 

#include <iostream>
#include <string>
using namespace std;

class Telephone {
    int hash;
    long long int key;  
    int m;            
    long long int mobile[10];   
    string name[10];  

public:
    Telephone() {
        for (int i = 0; i < 10; ++i) {
            mobile[i] = -1;  
            name[i] = "null"; 
        }
    }

    void linearProbing() {
        cout << "Enter the number of Clients: ";
        cin >> m;

        if (m > 10) {
            cout << "Maximum number of clients allowed is 10." << endl;
            return;
        }

        for (int j = 0; j < m; j++) {
            cout << "Enter telephone number: ";
            cin >> key;
            cin.ignore();  

            int i = 0;  
            bool placed = false;

            while (!placed) {
                hash = (key % 10 + i) % 10;
                if (mobile[hash] == -1) {  
                    mobile[hash] = key;
                    cout << "Enter name of Client: ";
                    getline(cin, name[hash]);
                    placed = true;
                } else {
                    ++i; 
                    if (i == 10) {  
                        cout << "Hash table is full, cannot insert." << endl;
                        return;
                    }
                }
            }
        }
    }

    void quadraticProbing() {
        cout << "Enter the number of Clients: ";
        cin >> m;

        if (m > 10) {
            cout << "Maximum number of clients allowed is 10." << endl;
            return;
        }

        for (int j = 0; j < m; j++) {
            cout << "Enter telephone number: ";
            cin >> key;
            cin.ignore();  

            int i = 0;  
            bool placed = false;

            while (!placed) {
                hash = (key % 10 + i * i) % 10;  
                if (mobile[hash] == -1) {  
                    mobile[hash] = key;
                    cout << "Enter name of Client: ";
                    getline(cin, name[hash]);  
                    placed = true;
                } else {
                    ++i; 
                    if (i == 10) {  
                        cout << "Hash table is full, cannot insert." << endl;
                        return;
                    }
                }
            }
        }
    }

    void display() {
        cout << "Telephone Directory:" << endl;
        for (int i = 0; i < 10; i++) {
            cout << i << " - [" << mobile[i] << ", " << name[i] << "]" << endl;
        }
    }
};

int main() {
    Telephone t;
    int choice;

    cout << "Choose Probing Method:" << endl;
    cout << "1. Linear Probing" << endl;
    cout << "2. Quadratic Probing" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        t.linearProbing();
    } else if (choice == 2) {
        t.quadraticProbing();
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    t.display();
    return 0;
}

