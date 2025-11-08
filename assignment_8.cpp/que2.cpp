#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// (a) Search - Recursive
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Search - Non-Recursive
Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// (b) Maximum element
Node* findMax(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// (c) Minimum element
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// (d) In-order Successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != NULL)
        return findMin(node->right);

    Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else
            break;
    }
    return successor;
}

// (e) In-order Predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != NULL)
        return findMax(node->left);

    Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else
            break;
    }
    return predecessor;
}

// In-order Traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {20, 10, 5, 15, 30, 25, 35};
    for (int x : arr)
        root = insert(root, x);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << "\n";

    int key = 15;
    Node* rSearch = searchRecursive(root, key);
    cout << "\nRecursive Search for " << key << ": " 
         << (rSearch ? "Found" : "Not Found");

    Node* nrSearch = searchNonRecursive(root, key);
    cout << "\nNon-Recursive Search for " << key << ": " 
         << (nrSearch ? "Found" : "Not Found");

    cout << "\n\nMinimum element: " << findMin(root)->data;
    cout << "\nMaximum element: " << findMax(root)->data;

    Node* node = searchRecursive(root, 20); // Find successor & predecessor of 20
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    cout << "\n\nIn-order Successor of " << node->data << ": "
         << (succ ? to_string(succ->data) : "None");

    cout << "\nIn-order Predecessor of " << node->data << ": "
         << (pred ? to_string(pred->data) : "None");

    return 0;
}
