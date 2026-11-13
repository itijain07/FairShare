#pragma once
#include <iostream>
using namespace std;

class AVLTree {
private:
    struct Node {
        int expenseID;
        int height;
        Node* left;
        Node* right;

        Node(int id) {
            expenseID = id;
            height = 1;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    int height(Node* node) {
        return node == NULL ? 0 : node->height;
    }

    int maxHeight(int a, int b) {
        return a > b ? a : b;
    }

    int balanceFactor(Node* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = 1 + maxHeight(
            height(y->left), height(y->right));

        x->height = 1 + maxHeight(
            height(x->left), height(x->right));

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = 1 + maxHeight(
            height(x->left), height(x->right));

        y->height = 1 + maxHeight(
            height(y->left), height(y->right));

        return y;
    }

    Node* insertNode(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->expenseID)
            node->left = insertNode(node->left, id);
        else if (id > node->expenseID)
            node->right = insertNode(node->right, id);
        else
            return node;

        node->height = 1 + maxHeight(
            height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // Left Left
        if (balance > 1 &&
            id < node->left->expenseID)
            return rotateRight(node);

        // Right Right
        if (balance < -1 &&
            id > node->right->expenseID)
            return rotateLeft(node);

        // Left Right
        if (balance > 1 &&
            id > node->left->expenseID) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left
        if (balance < -1 &&
            id < node->right->expenseID) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool searchNode(Node* node, int id) {
        if (node == NULL) return false;
        if (node->expenseID == id) return true;

        if (id < node->expenseID)
            return searchNode(node->left, id);

        return searchNode(node->right, id);
    }

    void inorder(Node* node) {
        if (node == NULL) return;

        inorder(node->left);
        cout << node->expenseID << " ";
        inorder(node->right);
    }

    void clear(Node* node) {
        if (node == NULL) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    AVLTree() {
        root = NULL;
    }

    ~AVLTree() {
        clear(root);
    }

    void insert(int id) {
        root = insertNode(root, id);
    }

    void search(int id) {
        if (searchNode(root, id))
            cout << "Expense Found!\n";
        else
            cout << "Expense Not Found!\n";
    }

    void display() {
        cout << "Sorted Expense IDs: ";
        inorder(root);
        cout << endl;
    }
};

