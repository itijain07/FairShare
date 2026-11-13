
#include <iostream>
using namespace std;

class Node {
public:
    int expenseID;
    Node* left;
    Node* right;

    Node(int id) {
        expenseID = id;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->expenseID)
            node->left = insertNode(node->left, id);
        else if (id > node->expenseID)
            node->right = insertNode(node->right, id);

        return node;
    }

    bool searchNode(Node* node, int id) {
        if (node == NULL)
            return false;

        if (node->expenseID == id)
            return true;

        if (id < node->expenseID)
            return searchNode(node->left, id);

        return searchNode(node->right, id);
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->expenseID << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = NULL;
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
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    tree.insert(105);
    tree.insert(102);
    tree.insert(108);
    tree.insert(101);
    tree.insert(104);

    cout << "Sorted Expense IDs: ";
    tree.display();

    int id;
    cout << "Enter Expense ID to search: ";
    cin >> id;

    tree.search(id);

    return 0;
}
