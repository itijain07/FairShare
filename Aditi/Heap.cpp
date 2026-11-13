
#include <iostream>
using namespace std;

class MaxHeap {
private:
    int amounts[100];
    int members[100];
    int size;

    void swapItems(int a, int b) {
        int temp = amounts[a];
        amounts[a] = amounts[b];
        amounts[b] = temp;

        temp = members[a];
        members[a] = members[b];
        members[b] = temp;
    }

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int member, int amount) {
        if (size >= 100 || amount <= 0) {
            cout << "Invalid amount or heap full!\n";
            return;
        }

        int i = size;
        amounts[i] = amount;
        members[i] = member;
        size++;

        while (i > 0 && amounts[(i - 1) / 2] < amounts[i]) {
            int parent = (i - 1) / 2;
            swapItems(i, parent);
            i = parent;
        }

        cout << "Payment added to heap!\n";
    }

    void showHighest() {
        if (size == 0) {
            cout << "No pending payments!\n";
            return;
        }

        cout << "\nHighest Pending Payment:\n";
        cout << "Member " << members[0]
             << " owes Rs. " << amounts[0] << endl;
    }

    void displayHeap() {
        cout << "\n===== MAX HEAP =====\n";

        for (int i = 0; i < size; i++) {
            cout << "Member " << members[i]
                 << " owes Rs. " << amounts[i] << endl;
        }
    }
};

int main() {
    MaxHeap heap;

    // 0 = Aditi
    // 1 = Iti
    // 2 = Priyal
    // 3 = Riddhisha

    heap.insert(1, 500);
    heap.insert(2, 200);
    heap.insert(3, 800);

    heap.showHighest();
    heap.displayHeap();

    return 0;
}