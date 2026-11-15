
#include <iostream>
#include <iomanip>
using namespace std;

class MonthlyTracker {
private:
    int expenses[100];
    int categories[100];
    int months[100];
    int years[100];
    int count;

public:
    MonthlyTracker() {
        count = 0;
    }

    void addExpense() {
        if (count >= 100) {
            cout << "Storage full!\n";
            return;
        }

        int amount, category, month, year;

        cout << "Enter amount: ";
        cin >> amount;

        cout << "\n1. Food";
        cout << "\n2. Travel";
        cout << "\n3. Shopping";
        cout << "\n4. Education";
        cout << "\nChoose category: ";
        cin >> category;

        cout << "Enter month (1-12): ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;

        if (!cin || amount <= 0 ||
            category < 1 || category > 4 ||
            month < 1 || month > 12 ||
            year < 2000 || year > 2100) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        expenses[count] = amount;
        categories[count] = category;
        months[count] = month;
        years[count] = year;
        count++;

        cout << "Expense added successfully!\n";
    }

    void showSummary() {
        int month, year;

        cout << "Enter month (1-12): ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;

        if (!cin || month < 1 || month > 12 ||
            year < 2000 || year > 2100) {
            cout << "Invalid month or year!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }

        int total = 0;
        int transactions = 0;
        int highest = 0;
        int categoryTotal[4] = {0, 0, 0, 0};

        for (int i = 0; i < count; i++) {
            if (months[i] == month &&
                years[i] == year) {

                total += expenses[i];
                transactions++;

                if (expenses[i] > highest) {
                    highest = expenses[i];
                }

                categoryTotal[categories[i] - 1]
                    += expenses[i];
            }
        }

        if (transactions == 0) {
            cout << "No expenses for this month!\n";
            return;
        }

        cout << "\n===== MONTHLY SUMMARY =====\n";
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << "Total: Rs. " << total << endl;
        cout << "Transactions: " << transactions << endl;

        cout << fixed << setprecision(2);
        cout << "Average: Rs. "
             << (double)total / transactions << endl;

        cout << "Highest: Rs. " << highest << endl;

        cout << "\nCATEGORY-WISE EXPENSES\n";
        cout << "Food: Rs. " << categoryTotal[0] << endl;
        cout << "Travel: Rs. " << categoryTotal[1] << endl;
        cout << "Shopping: Rs. " << categoryTotal[2] << endl;
        cout << "Education: Rs. " << categoryTotal[3] << endl;
    }
};

int monthlyModule() {
    MonthlyTracker tracker;
    int choice = -1;

    do {
        cout << "\n===== FAIRSHARE =====\n";
        cout << "1. Add Expense\n";
        cout << "2. Monthly Summary\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice!\n";
            break;
        }

        switch (choice) {
            case 1:
                tracker.addExpense();
                break;

            case 2:
                tracker.showSummary();
                break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
