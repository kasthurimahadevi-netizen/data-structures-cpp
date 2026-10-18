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
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Added Fix: Dynamic memory cleanup method to prevent memory leaks
void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};

    // Range-based for loop works perfectly in C++11 and higher
    for (int id : ids)
        root = insert(root, id);

    cout << "Employee IDs in BST (Inorder Traversal): ";
    inorder(root);
    cout << endl;

    // Free the heap allocated memory safely before exit
    freeTree(root);

    return 0;
}

