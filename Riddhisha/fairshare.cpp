
#include <iostream>
using namespace std;

void splitting();
void balanceCalculation();
void settlementCalculation();
void undoFeature();
void queueFeature();

int riddhishaModule() {
    int choice;

    do {
        cout << "\n===== FAIRSHARE MAIN MENU =====\n";
        cout << "1. Expense Splitting\n";
        cout << "2. Balance Calculation\n";
        cout << "3. Settlement Calculation\n";
        cout << "4. Undo Expense (Stack)\n";
        cout << "5. Settlement Requests (Queue)\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input!" << endl;
            return 0;
        }

        switch (choice) {
            case 1: splitting(); break;
            case 2: balanceCalculation(); break;
            case 3: settlementCalculation(); break;
            case 4: undoFeature(); break;
            case 5: queueFeature(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
