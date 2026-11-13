
#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    int ids[SIZE];
    char names[SIZE][50];
    bool occupied[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            occupied[i] = false;
        }
    }

    void insert(int id, const char name[]) {
        int index = id % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;

            if (!occupied[pos] || ids[pos] == id) {
                ids[pos] = id;
                strcpy(names[pos], name);
                occupied[pos] = true;
                cout << "Member added!\n";
                return;
            }
        }
        cout << "Hash Table is full!\n";
    }

    void search(int id) {
        int index = id % SIZE;

        for (int i = 0; i < SIZE; i++) {
            int pos = (index + i) % SIZE;

            if (!occupied[pos]) {
                break;
            }

            if (ids[pos] == id) {
                cout << "Member Found!\n";
                cout << "ID: " << ids[pos] << endl;
                cout << "Name: " << names[pos] << endl;
                return;
            }
        }
        cout << "Member not found!\n";
    }
};

int main() {
    HashTable h;

    h.insert(101, "Iti");
    h.insert(102, "Riddhisha");
    h.insert(103, "Priyal");
    h.insert(104, "Aditi");

    int id;
    cout << "Enter Member ID: ";
    cin >> id;

    h.search(id);

    return 0;
}
