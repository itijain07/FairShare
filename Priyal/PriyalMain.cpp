#include "SearchSort.h"
#include <iostream>
#include "HashTable.h"
#include "BST.h"
#include "AVLTree.h"
using namespace std;

int main() {
    HashTable h;
    BST tree;
    AVLTree avl;
    SearchSort ss;

    h.insert(101, "Iti");
    h.insert(102, "Riddhisha");
    h.insert(103, "Priyal");
    h.insert(104, "Aditi");

    tree.insert(105);
    tree.insert(102);
    tree.insert(108);
    tree.insert(101);
    tree.insert(104);

    avl.insert(30);
    avl.insert(20);
    avl.insert(10);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    int choice, id;

    do {
        cout << "\n===== FAIRSHARE =====\n";
        cout << "1. Search Member (Hash Table)\n";
        cout << "2. Search Expense (BST)\n";
        cout << "3. Display Sorted Expense IDs (BST)\n";
        cout << "4. Search Expense (AVL Tree)\n";
        cout << "5. Display Sorted Expense IDs (AVL)\n";
        cout << "6. Search and Sort Expenses\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            return 1;
        }

        switch (choice) {
            case 1:
                cout << "Enter Member ID: ";
                cin >> id;
                h.search(id);
                break;

            case 2:
                cout << "Enter Expense ID: ";
                cin >> id;
                tree.search(id);
                break;

            case 3:
                cout << "Sorted Expense IDs (BST): ";
                tree.display();
                break;

            case 4:
                cout << "Enter Expense ID: ";
                cin >> id;
                avl.search(id);
                break;

            case 5:
                avl.display();
                break;
            
            case 6: {
                int amounts[] = {500, 200, 800, 100, 400};
                int n = 5;

                cout << "Original Expenses: ";
                ss.display(amounts, n);

                cout << "Linear Search (800): "
                << ss.linearSearch(amounts, n, 800)
                << endl;

                ss.mergeSort(amounts, n);

                cout << "After Merge Sort: ";
                ss.display(amounts, n);

                cout << "Binary Search (400): "
                << ss.binarySearch(amounts, n, 400)
                << endl;

                int amounts2[] = {900, 300, 700, 100, 500};

                ss.quickSort(amounts2, n);

                cout << "After Quick Sort: ";
                ss.display(amounts2, n);

                break;
            }

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
