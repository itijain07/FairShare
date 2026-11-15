#include <iostream>
#include <limits>
using namespace std;
int itiModule();
int riddhishaModule();
int priyalModule();
int graphModule();
int heapModule();
int monthlyModule();

int main() {
    int choice;
    while (true) {
        cout << "\n========== FAIRSHARE | INTEGRATED MENU ==========\n"
             << "1. Enter/replace shared Members and Expenses (Iti)\n"
             << "2. Split, Balance, Settlement, Stack and Queue (Riddhisha)\n"
             << "3. Hash Table, BST, AVL and Searching (Priyal)\n"
             << "4. Debt Graph, BFS and DFS (Aditi)\n"
             << "5. Max Heap (Aditi)\n"
             << "6. Monthly Expense Tracker (Aditi)\n"
             << "0. Exit\nChoose: ";
        if (!(cin >> choice)) {
            if (cin.eof()) return 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number.\n";
            continue;
        }
        switch (choice) {
            case 1: itiModule(); break;
            case 2: riddhishaModule(); break;
            case 3: priyalModule(); break;
            case 4: graphModule(); break;
            case 5: heapModule(); break;
            case 6: monthlyModule(); break;
            case 0: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
