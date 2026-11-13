
#include <iostream>
using namespace std;

void balanceCalculation() {
    int people;
    double total, share;
    double paid[100];

    cout << "===== BALANCE CALCULATION =====" << endl;

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
        cout << "Amount paid by person "
             << i + 1 << ": ";
        cin >> paid[i];

        if (paid[i] < 0) {
            cout << "Invalid amount!" << endl;
            return;
        }
    }

    cout << "\n===== BALANCE REPORT =====" << endl;

    for (int i = 0; i < people; i++) {
        double balance = paid[i] - share;

        cout << "Person " << i + 1 << ": ";

        if (balance > 0.01) {
            cout << "Gets back Rs. "
                 << balance << endl;
        }
        else if (balance < -0.01) {
            cout << "Owes Rs. "
                 << -balance << endl;
        }
        else {
            cout << "Settled!" << endl;
        }
    }

    return;
}
