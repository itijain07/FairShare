#include "SharedData.h"

#include <iostream>
#include <limits>
#include "Member.h"
#include "Expense.h"
#include "ExpenseList.h"

using namespace std;

void merge(Expense arr[], Expense temp[],
           int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {

        if (arr[i].getAmount() <= arr[j].getAmount()) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(Expense arr[], Expense temp[],
               int left, int right) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

int partition(Expense arr[], int low, int high) {

    double pivot = arr[high].getAmount();

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j].getAmount() <= pivot) {

            i++;

            Expense temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Expense temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(Expense arr[], int low, int high) {

    if (low < high) {

        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int itiModule() {

    sharedMembers.clear();
    sharedExpenses.clear();
    Member members[4];
    int n;

    cout << "===== FAIRSHARE =====" << endl;

    cout << "How many members? (Maximum 4): ";
    cin >> n;

    if (n < 1 || n > 4) {
        cout << "Invalid number of members!";
        return 0;
    }

    int id;
    char name[50];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Member ID: ";
        cin >> id;

        cout << "Enter Member Name: ";
        cin >> name;

        members[i].setMember(id, name);
        sharedMembers.push_back({id, name});
    }

    cout << "\n===== ADD EXPENSE =====\n";

    Expense expenses[100];
    ExpenseList expenseList;
    int expenseCount;

    cout << "How many expenses do you want to add? ";
    cin >> expenseCount;

    if (expenseCount < 0 || expenseCount > 100) {
        cout << "Invalid expense count!";
        return 0;
    }

    for (int i = 0; i < expenseCount; i++) {

        int expenseID, payerID;
        double amount;
        char description[100];
        char category[30];
        char date[20];

        cout << "\nExpense ID: ";
        cin >> expenseID;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Description: ";
        cin.getline(description, 100);

        cout << "Amount: ";
cin >> amount;

while (amount <= 0) {
    cout << "Amount must be positive. Enter again: ";
    cin >> amount;
}

        bool validPayer = false;

while (!validPayer) {

    cout << "Paid by (Member ID): ";
    cin >> payerID;

    for (int j = 0; j < n; j++) {
        if (members[j].getID() == payerID) {
            validPayer = true;
            break;
        }
    }

    if (!validPayer) {
        cout << "Invalid Member ID! Try again.\n";
    }
}

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Category: ";
        cin.getline(category, 30);

        cout << "Date (DD-MM-YYYY): ";
        cin.getline(date, 20);

        expenses[i].setExpense(
            expenseID, description, amount,
            payerID, category, date
        );
        expenseList.addExpense(expenses[i]);
        sharedExpenses.push_back({expenseID, description, amount, payerID, category, date});
    }

    cout << "\n===== ALL EXPENSES =====\n";

    for (int i = 0; i < expenseCount; i++) {
        expenses[i].displayExpense();
        cout << "----------------------\n";
           }

    cout << "\n===== LINKED LIST EXPENSES =====\n";

    expenseList.displayAllExpenses();
    int searchID;

cout << "\nEnter Expense ID to search: ";
cin >> searchID;

expenseList.searchExpense(searchID);
int deleteID;

cout << "\nEnter Expense ID to delete: ";
cin >> deleteID;

expenseList.deleteExpense(deleteID);
for (auto it = sharedExpenses.begin(); it != sharedExpenses.end(); ++it) {
    if (it->id == deleteID) { sharedExpenses.erase(it); break; }
}
int index = -1;

for (int i = 0; i < expenseCount; i++) {
    if (expenses[i].getExpenseID() == deleteID) {
        index = i;
        break;
    }
}

if (index != -1) {
    for (int i = index; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    expenseCount--;
}

cout << "\nUpdated Linked List:\n";
expenseList.displayAllExpenses();
cout << "\n===== EXPENSES SORTED BY QUICK SORT =====\n";

Expense quickSorted[100];

for (int i = 0; i < expenseCount; i++) {
    quickSorted[i] = expenses[i];
}

quickSort(quickSorted, 0, expenseCount - 1);

for (int i = 0; i < expenseCount; i++) {
    quickSorted[i].displayExpense();
    cout << "------------------\n";
}

cout << "\n===== EXPENSES SORTED BY AMOUNT =====\n";

Expense temp[100];

mergeSort(expenses, temp, 0, expenseCount - 1);

for (int i = 0; i < expenseCount; i++) {
    expenses[i].displayExpense();
    cout << "------------------\n";
}


    return 0;
}

