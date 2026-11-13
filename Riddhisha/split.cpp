
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAX_PEOPLE = 100;

// Calculate balances and show who pays whom
void showSettlement(double paid[], double share[], int people) {
    double balance[MAX_PEOPLE];

    cout << "\n===== BALANCE REPORT =====\n";

    for (int i = 0; i < people; i++) {
        balance[i] = paid[i] - share[i];

        cout << "Person " << i + 1 << ": ";

        if (balance[i] > 0.01) {
            cout << "Gets back Rs. " << balance[i] << endl;
        }
        else if (balance[i] < -0.01) {
            cout << "Owes Rs. " << -balance[i] << endl;
        }
        else {
            cout << "Settled!" << endl;
        }
    }

    cout << "\n===== SETTLEMENT REPORT =====\n";

    bool settlementNeeded = false;

    for (int i = 0; i < people; i++) {
        if (balance[i] < -0.01) {
            for (int j = 0; j < people; j++) {
                if (balance[j] > 0.01) {

                    double amount = -balance[i];

                    if (balance[j] < amount) {
                        amount = balance[j];
                    }

                    if (amount <= 0.01) {
                        continue;
                    }

                    cout << "Person " << i + 1
                         << " pays Person " << j + 1
                         << ": Rs. " << amount << endl;

                    settlementNeeded = true;

                    balance[i] += amount;
                    balance[j] -= amount;

                    if (balance[i] >= -0.01) {
                        break;
                    }
                }
            }
        }
    }

    if (!settlementNeeded) {
        cout << "Everyone is settled!" << endl;
    }
}

// Equal, Fixed and Percentage splitting
void splitting() {
    int choice, people;
    double total;

    double share[MAX_PEOPLE] = {0};
    double paid[MAX_PEOPLE] = {0};

    cout << "\n===== FAIRSHARE SPLITTING =====\n";
    cout << "1. Equal Split\n";
    cout << "2. Fixed Split\n";
    cout << "3. Percentage Split\n";

    cout << "Enter your choice: ";
    if (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "Invalid choice!" << endl;
        return;
    }

    cout << "Enter total expense: ";
    cout << fixed << setprecision(2);

    if (!(cin >> total) || total <= 0) {
        cout << "Invalid total expense!" << endl;
        return;
    }

    cout << "Enter number of people: ";
    if (!(cin >> people) || people <= 0 ||
        people > MAX_PEOPLE) {
        cout << "Invalid number of people!" << endl;
        return;
    }

    if (choice == 1) {
        for (int i = 0; i < people; i++) {
            share[i] = total / people;
        }

        cout << "\nEqual split successful!" << endl;
    }

    else if (choice == 2) {
        double sum = 0;

        for (int i = 0; i < people; i++) {
            cout << "Enter share for person "
                 << i + 1 << ": ";

            if (!(cin >> share[i]) || share[i] < 0) {
                cout << "Invalid amount!" << endl;
                return;
            }

            sum += share[i];
        }

        if (fabs(sum - total) > 0.01) {
            cout << "Error! Shares must add up to Rs. "
                 << total << endl;
            return;
        }

        cout << "\nFixed split successful!" << endl;
    }

    else if (choice == 3) {
        double percentage, sum = 0;

        for (int i = 0; i < people; i++) {
            cout << "Enter percentage for person "
                 << i + 1 << ": ";

            if (!(cin >> percentage) ||
                percentage < 0 || percentage > 100) {
                cout << "Invalid percentage!" << endl;
                return;
            }

            sum += percentage;
            share[i] = total * percentage / 100;
        }

        if (fabs(sum - 100) > 0.000001) {
            cout << "Error! Percentages must total 100."
                 << endl;
            return;
        }

        cout << "\nPercentage split successful!" << endl;
    }

    cout << "\n===== SHARE REPORT =====\n";

    for (int i = 0; i < people; i++) {
        cout << "Person " << i + 1
             << " share: Rs. " << share[i] << endl;
    }

    cout << "\n===== PAYMENT DETAILS =====\n";
    cout << "Enter how much each person actually paid."
         << endl;

    double totalPaid = 0;

    for (int i = 0; i < people; i++) {
        cout << "Amount paid by person "
             << i + 1 << ": ";

        if (!(cin >> paid[i]) || paid[i] < 0) {
            cout << "Invalid payment!" << endl;
            return;
        }

        totalPaid += paid[i];
    }

    if (fabs(totalPaid - total) > 0.01) {
        cout << "Error! Total payments must equal Rs. "
             << total << endl;
        return;
    }

    showSettlement(paid, share, people);
}
