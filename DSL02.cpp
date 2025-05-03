/*A book consist of chapter, chapter consist of sections , sections consist of sub-sections construct tree and print nodes  */

#include<iostream>

using namespace std;

struct Node {
    string label;
    int count;
    Node* child[10];
    
    Node() {
        for (int i = 0; i < 10; ++i) {
            child[i] = NULL;
        }
    }
} *root;

class Record {
public:
    Record() {
        root = new Node();
    }

    void create() {
        cout << "Enter the book name: ";
        cin.ignore();
        getline(cin, root->label);

        cout << "Enter number of chapters: ";
        cin >> root->count;
        cin.ignore();

        for (int i = 0; i < root->count; ++i) {
            root->child[i] = new Node();
            cout << "Enter name of Chapter " << i + 1 << ": ";
            cin.ignore();
            getline(cin, root->child[i]->label);

            cout << "Enter number of sections: ";
            cin >> root->child[i]->count;
            cin.ignore();

            for (int j = 0; j < root->child[i]->count; ++j) {
                root->child[i]->child[j] = new Node();
                cout << "Enter name of Section " << j + 1 << ": ";
                getline(cin, root->child[i]->child[j]->label);

                cout << "Enter number of sub-sections: ";
                cin >> root->child[i]->child[j]->count;
                cin.ignore();

                for (int k = 0; k < root->child[i]->child[j]->count; ++k) {
                    root->child[i]->child[j]->child[k] = new Node();
                    cout << "Enter name of Sub-section " << k + 1 << ": ";
                    getline(cin, root->child[i]->child[j]->child[k]->label);
                }
            }
        }
    }

    void display(Node* root) {
    	cout <<"-------------------------------------"<<endl;
        cout << "Book name: " << root->label << endl;
        	cout <<"-------------------------------------"<<endl;

        for (int i = 0; i < root->count; ++i) {
            cout << "Chapter " << i + 1 << ": " << root->child[i]->label << endl;

            for (int j = 0; j < root->child[i]->count; ++j) {
                cout << "Section " << j + 1 << ": " << root->child[i]->child[j]->label << endl;

                for (int k = 0; k < root->child[i]->child[j]->count; ++k) {
                    cout << "Sub-section " << k + 1 << ": " << root->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    }
};

int main() {
    Record r;
    r.create();
    r.display(root);

    return 0;
}

