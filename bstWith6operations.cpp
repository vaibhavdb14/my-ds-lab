//Beginning with an empty search, construct BST by inserting values in order to perform follwing operations 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    
    return root;
}

int findHeight(Node* root) {
    if (root == NULL)
        return 0;
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

Node* mirror(Node* root) {
    if (root == NULL)
        return NULL;
    
    Node* temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    
    return root;
}

bool search(Node* root, int value) {
    if (root == NULL) {
        cout << "Tree is empty or value not found!" << endl;
        return false;
    }

    if (root->data == value) {
        cout << value << " found in BST." << endl;
        return true;
    }

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void inOrder(Node* root) {
    if (root == NULL)
        return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = NULL;
    int choice, value;
    
    do {
        cout << "\n1. Insert new node";
        cout << "\n2. Find height of tree";
        cout << "\n3. Find minimum value in tree";
        cout << "\n4. Mirror the tree (swap left & right)";
        cout << "\n5. Search for a value";
        cout << "\n6. Display In-order";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
                
            case 2:
                cout << "Height of tree (largest path): " << findHeight(root) << endl;
                break;
                
            case 3:
                cout << "Minimum value in BST: " << findMin(root) << endl;
                break;
                
            case 4:
                root = mirror(root);
                cout << "Tree mirrored successfully!" << endl;
                break;
                
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                search(root, value);
                break;
                
            case 6:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << endl;
                break;
                
            case 7:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
    
    return 0;
}

