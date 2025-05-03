// A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords,
// updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. 
// Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation.

#include <iostream>
#include <string>
using namespace std;

struct BSTNode {
    string keyword;
    string meaning;
    BSTNode *left, *right;

    BSTNode(string key, string mean) {
        keyword = key;
        meaning = mean;
        left = right = nullptr;
    }
};

class DictionaryBST {
private:
    BSTNode* root;

    BSTNode* insertRec(BSTNode* root, string key, string mean) {
        if (!root) return new BSTNode(key, mean);

        if (key < root->keyword)
            root->left = insertRec(root->left, key, mean);
        else if (key > root->keyword)
            root->right = insertRec(root->right, key, mean);
        else
            root->meaning = mean;  // Update meaning if keyword exists

        return root;
    }

    BSTNode* searchRec(BSTNode* root, string key, int& comparisons) {
        if (!root) return nullptr;

        comparisons++;
        if (key == root->keyword) return root;
        else if (key < root->keyword) return searchRec(root->left, key, comparisons);
        else return searchRec(root->right, key, comparisons);
    }

    BSTNode* findMin(BSTNode* root) {
        while (root->left) root = root->left;
        return root;
    }

    BSTNode* deleteRec(BSTNode* root, string key) {
        if (!root) return nullptr;

        if (key < root->keyword)
            root->left = deleteRec(root->left, key);
        else if (key > root->keyword)
            root->right = deleteRec(root->right, key);
        else {
            // Node with one or no child
            if (!root->left) {
                BSTNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                BSTNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get inorder successor
            BSTNode* temp = findMin(root->right);
            root->keyword = temp->keyword;
            root->meaning = temp->meaning;
            root->right = deleteRec(root->right, temp->keyword);
        }
        return root;
    }

    void preorder(BSTNode* root) {
        if (root) {
            cout << root->keyword << " -> " << root->meaning << endl;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(BSTNode* root) {
        if (root) {
            inorder(root->left);
            cout << root->keyword << " -> " << root->meaning << endl;
            inorder(root->right);
        }
    }

    void postorder(BSTNode* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->keyword << " -> " << root->meaning << endl;
        }
    }

public:
    DictionaryBST() { root = nullptr; }

    void insert(string key, string mean) {
        root = insertRec(root, key, mean);
    }

    void search(string key) {
        int comparisons = 0;
        BSTNode* result = searchRec(root, key, comparisons);
        if (result)
            cout << "Keyword found: " << result->keyword << " -> " << result->meaning << " (Comparisons: " << comparisons << ")\n";
        else
            cout << "Keyword not found! (Comparisons: " << comparisons << ")\n";
    }

    void deleteKeyword(string key) {
        root = deleteRec(root, key);
        cout << "Keyword deleted successfully.\n";
    }

    void displayAllTraversals() {
        cout << "Preorder Traversal:\n";
        preorder(root);
        cout << "\nInorder Traversal:\n";
        inorder(root);
        cout << "\nPostorder Traversal:\n";
        postorder(root);
    }
};

int main() {
    DictionaryBST dict;
    int choice;
    string key, meaning;

    while (true) {
        cout << "\nDictionary Operations:\n";
        cout << "1. Insert a keyword\n";
        cout << "2. Search for a keyword\n";
        cout << "3. Delete a keyword\n";
        cout << "4. Display all traversals\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                getline(cin, key);
                cout << "Enter meaning: ";
                getline(cin, meaning);
                dict.insert(key, meaning);
                cout << "Keyword added successfully.\n";
                break;

            case 2:
                cout << "Enter keyword to search: ";
                getline(cin, key);
                dict.search(key);
                break;

            case 3:
                cout << "Enter keyword to delete: ";
                getline(cin, key);
                dict.deleteKeyword(key);
                break;

            case 4:
                dict.displayAllTraversals();
                break;

            case 5:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }
}
