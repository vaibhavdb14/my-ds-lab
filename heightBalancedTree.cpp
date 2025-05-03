#include <iostream>
#include <string>
using namespace std;

struct Node {
    string keyword;
    string value;
    Node* left;
    Node* right;
    int height;

    Node(string key, string val) {
        keyword = key;
        value = val;
        left = right = nullptr;
        height = 1; // New node is initially at height 1
    }
};

// Function to get height of a node
int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Function to calculate balance factor
int getBalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right Rotation (LL Case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left Rotation (RR Case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert a keyword into AVL tree
Node* insert(Node* root, string keyword, string value) {
    if (root == nullptr)
        return new Node(keyword, value);

    if (keyword < root->keyword)
        root->left = insert(root->left, keyword, value);
    else if (keyword > root->keyword)
        root->right = insert(root->right, keyword, value);
    else {
        cout << "Keyword already exists! Updating value.\n";
        root->value = value;
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && keyword < root->left->keyword) 
        return rightRotate(root);

    if (balance < -1 && keyword > root->right->keyword) 
        return leftRotate(root);

    if (balance > 1 && keyword > root->left->keyword) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && keyword < root->right->keyword) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for a keyword and count comparisons
int search(Node* root, string keyword, int& comparisons) {
    if (root == nullptr) {
        cout << "Keyword not found.\n";
        return comparisons;
    }

    comparisons++;

    if (keyword == root->keyword) {
        cout << "Keyword found! Value: " << root->value << "\n";
        return comparisons;
    }

    if (keyword < root->keyword)
        return search(root->left, keyword, comparisons);
    else
        return search(root->right, keyword, comparisons);
}

// Function to find the node with the smallest value (for deletion)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete a keyword from the AVL tree
Node* deleteNode(Node* root, string keyword) {
    if (root == nullptr)
        return root;

    if (keyword < root->keyword)
        root->left = deleteNode(root->left, keyword);
    else if (keyword > root->keyword)
        root->right = deleteNode(root->right, keyword);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->keyword = temp->keyword;
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->keyword);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Display dictionary in ascending order (in-order traversal)
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->keyword << " : " << root->value << endl;
        inOrder(root->right);
    }
}

// Display dictionary in descending order (reverse in-order traversal)
void reverseInOrder(Node* root) {
    if (root) {
        reverseInOrder(root->right);
        cout << root->keyword << " : " << root->value << endl;
        reverseInOrder(root->left);
    }
}

// Menu-driven program
int main() {
    Node* root = nullptr;
    int choice;
    string keyword, value;
    int comparisons = 0;

    do {

        cout << "\n1. Insert Keyword\n2. Delete Keyword\n3. Search Keyword\n4. Display Ascending\n5. Display Descending\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword and value: ";
                cin >> keyword >> value;
                root = insert(root, keyword, value);
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                root = deleteNode(root, keyword);
                break;
            case 3:
                
                cout << "Enter keyword to search: ";
                cin >> keyword;
                cout << "Comparisons: " << search(root, keyword, comparisons) << endl;
                break;
            case 4:
                cout << "Dictionary in Ascending Order:\n";
                inOrder(root);
                break;
            case 5:
                cout << "Dictionary in Descending Order:\n";
                reverseInOrder(root);
                break;
        }
    } while (choice != 6);

    return 0;
}
