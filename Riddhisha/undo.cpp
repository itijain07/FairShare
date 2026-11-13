
#include <iostream>
using namespace std;

const int MAX = 100;

double expenseStack[MAX];
int top = -1;

// Add expense to stack
void addExpense(double amount) {
    if (top == MAX - 1) {
        cout << "Stack is full!" << endl;
        return;
    }

    top++;
    expenseStack[top] = amount;

    cout << "Expense added: Rs. "
         << amount << endl;
}

// Undo last expense
void undoExpense() {
    if (top == -1) {
        cout << "No expense to undo!" << endl;
        return;
    }

    cout << "Undone expense: Rs. "
         << expenseStack[top] << endl;

    top--;
}

// Show all expenses
void showExpenses() {
    if (top == -1) {
        cout << "No expenses available!" << endl;
        return;
    }

    cout << "\nCurrent expenses:\n";

    for (int i = 0; i <= top; i++) {
        cout << "Rs. " << expenseStack[i] << endl;
    }
}

void undoFeature() {
    int choice;
    double amount;

    do {
        cout << "\n===== FAIRSHARE UNDO MENU =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Undo Last Expense\n";
        cout << "3. Show Expenses\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;

                if (amount > 0) {
                    addExpense(amount);
                } else {
                    cout << "Invalid amount!" << endl;
                }
                break;

            case 2:
                undoExpense();
                break;

            case 3:
                showExpenses();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return;
}
