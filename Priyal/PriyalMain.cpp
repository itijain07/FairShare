#include "../SharedData.h"
#include "SearchSort.h"
#include <iostream>
#include "HashTable.h"
#include "BST.h"
#include "AVLTree.h"
using namespace std;

int priyalModule() {
    HashTable h;
    BST tree;
    AVLTree avl;
    SearchSort ss;

    if (sharedMembers.empty()) {
        cout << "No shared members yet. Run option 1 (Iti) first.\n";
    }
    for (const auto& m : sharedMembers) h.insert(m.id, m.name.c_str());
    for (const auto& e : sharedExpenses) { tree.insert(e.id); avl.insert(e.id); }
    if (sharedExpenses.empty()) cout << "No shared expenses yet. Run option 1 first.\n";

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
                if (sharedExpenses.empty()) { cout << "No expenses to search/sort.\n"; break; }
                int n = static_cast<int>(sharedExpenses.size());
                int* amounts = new int[n];
                for (int i=0;i<n;++i) amounts[i] = static_cast<int>(sharedExpenses[i].amount);

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

                int* amounts2 = new int[n];
                for (int i=0;i<n;++i) amounts2[i] = static_cast<int>(sharedExpenses[i].amount);

                ss.quickSort(amounts2, n);

                cout << "After Quick Sort: ";
                ss.display(amounts2, n);

                delete[] amounts;
                delete[] amounts2;
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
