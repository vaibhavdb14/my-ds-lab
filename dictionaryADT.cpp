#include <iostream>
#include <map>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10; 
    map<int, string> table[TABLE_SIZE]; 

    int hashFunction(int key) {
        return key % TABLE_SIZE; 
    }

public:
    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index][key] = value; 
    }

    string find(int key) {
        int index = hashFunction(key);
        if (table[index].find(key) != table[index].end()) {
            return table[index][key];
        }
        return "Key not found";
    }

    void remove(int key) {
        int index = hashFunction(key);
        if (table[index].erase(key) == 0) {
            cout << "Key not found\n";
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            for (auto &pair : table[i]) {
                cout << "( " << pair.first << ", " << pair.second << " ) ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable dict;
    int choice, key;
    string value;
    
    do {
        cout << "\nMenu:\n1. Insert\n2. Find\n3. Delete\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter key and value: ";
                cin >> key >> value;
                dict.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                cout << "Value: " << dict.find(key) << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dict.remove(key);
                break;
            case 4:
                cout << "Dictionary contents:\n";
                dict.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
