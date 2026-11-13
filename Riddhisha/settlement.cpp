
#include <iostream>
using namespace std;

void settlementCalculation() {
    int people;
    double total, share;
    double paid[100], balance[100];
    double totalPaid = 0;

    cout << "===== FAIRSHARE SETTLEMENT =====" << endl;

    cout << "Enter total expense: ";
    cin >> total;

    cout << "Enter number of people: ";
    cin >> people;

    if (total <= 0 || people <= 0 || people > 100) {
        cout << "Invalid input!" << endl;
        return;
    }

    share = total / people;

    for (int i = 0; i < people; i++) {
        cout << "Amount paid by person " << i + 1 << ": ";
        cin >> paid[i];

        if (paid[i] < 0) {
            cout << "Invalid amount!" << endl;
            return;
        }

        totalPaid += paid[i];
        balance[i] = paid[i] - share;
    }

    if (totalPaid < total - 0.01 ||
        totalPaid > total + 0.01) {
        cout << "Error! Total paid must equal expense."
             << endl;
        return;
    }

    cout << "\n===== SETTLEMENT REPORT =====" << endl;

    for (int i = 0; i < people; i++) {
        if (balance[i] < -0.01) {

            for (int j = 0; j < people; j++) {
                if (balance[j] > 0.01) {

                    double amount = -balance[i];

                    if (balance[j] < amount) {
                        amount = balance[j];
                    }

                    cout << "Person " << i + 1
                         << " pays Person " << j + 1
                         << ": Rs. " << amount << endl;

                    balance[i] += amount;
                    balance[j] -= amount;

                    if (balance[i] >= -0.01) {
                        break;
                    }
                }
            }
        }
    }

    return;
}
