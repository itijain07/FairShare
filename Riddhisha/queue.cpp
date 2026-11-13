
#include <iostream>
using namespace std;

const int MAX = 100;

struct Request {
    int fromPerson;
    int toPerson;
    double amount;
};

Request requests[MAX];

int front = 0;
int rear = 0;
int requestCount = 0;

// Add a settlement request
void addRequest() {
    if (requestCount == MAX) {
        cout << "Queue is full!" << endl;
        return;
    }

    Request r;

    cout << "Enter payer person number: ";
    cin >> r.fromPerson;

    cout << "Enter receiver person number: ";
    cin >> r.toPerson;

    cout << "Enter amount: ";
    cin >> r.amount;

    if (r.fromPerson <= 0 || r.toPerson <= 0 ||
        r.fromPerson == r.toPerson || r.amount <= 0) {
        cout << "Invalid request!" << endl;
        return;
    }

    requests[rear] = r;
    rear = (rear + 1) % MAX;
    requestCount++;

    cout << "Settlement request added!" << endl;
}

// Process the oldest request
void processRequest() {
    if (requestCount == 0) {
        cout << "No pending requests!" << endl;
        return;
    }

    Request r = requests[front];

    cout << "Processed: Person " << r.fromPerson
         << " pays Person " << r.toPerson
         << " Rs. " << r.amount << endl;

    front = (front + 1) % MAX;
    requestCount--;
}

// Display pending requests
void showRequests() {
    if (requestCount == 0) {
        cout << "No pending requests!" << endl;
        return;
    }

    cout << "\n===== PENDING REQUESTS =====\n";

    for (int i = 0; i < requestCount; i++) {
        int index = (front + i) % MAX;

        cout << "Person " << requests[index].fromPerson
             << " pays Person " << requests[index].toPerson
             << ": Rs. " << requests[index].amount
             << endl;
    }
}

void queueFeature() {
    int choice;

    do {
        cout << "\n===== FAIRSHARE QUEUE MENU =====\n";
        cout << "1. Add Settlement Request\n";
        cout << "2. Process Oldest Request\n";
        cout << "3. Show Pending Requests\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input!" << endl;
            return;
        }

        switch (choice) {
            case 1:
                addRequest();
                break;

            case 2:
                processRequest();
                break;

            case 3:
                showRequests();
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
