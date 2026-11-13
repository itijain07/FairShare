
#include <iostream>
#include "ExpenseList.h"

using namespace std;

ExpenseList::ExpenseList() {
    head = NULL;
}

// Add expense at the end of Linked List
void ExpenseList::addExpense(Expense e) {

    ExpenseNode* newNode = new ExpenseNode;

    newNode->data = e;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        ExpenseNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Expense added to Linked List!\n";
}

// Display all expenses
void ExpenseList::displayAllExpenses() {

    if (head == NULL) {
        cout << "No expenses found!\n";
        return;
    }

    ExpenseNode* temp = head;

    while (temp != NULL) {
        temp->data.displayExpense();
        cout << "------------------\n";

        temp = temp->next;
    }
}

void ExpenseList::searchExpense(int id) {

    ExpenseNode* temp = head;

    while (temp != NULL) {

        if (temp->data.getExpenseID() == id) {
            cout << "\nExpense Found!\n";
            temp->data.displayExpense();
            return;
        }

        temp = temp->next;
    }

    cout << "\nExpense Not Found!\n";
}

void ExpenseList::deleteExpense(int id) {

    ExpenseNode* temp = head;
    ExpenseNode* previous = NULL;

    while (temp != NULL && temp->data.getExpenseID() != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Expense Not Found!\n";
        return;
    }

    if (previous == NULL) {
        head = temp->next;
    }
    else {
        previous->next = temp->next;
    }

    delete temp;

    cout << "Expense Deleted Successfully!\n";
}


// Destructor
ExpenseList::~ExpenseList() {

    ExpenseNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
