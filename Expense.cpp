
#include <iostream>
#include <cstring>
#include "Expense.h"

using namespace std;

Expense::Expense() {
    expenseID = 0;
    strcpy(description, "");
    amount = 0;
    payerID = 0;
    strcpy(category, "");
    strcpy(date, "");
}

void Expense::setExpense(int id, const char desc[],
                         double amt, int payer,
                         const char cat[], const char expDate[]) {

    expenseID = id;
    strcpy(description, desc);
    amount = amt;
    payerID = payer;
    strcpy(category, cat);
    strcpy(date, expDate);
}

void Expense::displayExpense() {

    cout << "\nExpense ID: " << expenseID;
    cout << "\nDescription: " << description;
    cout << "\nAmount: Rs. " << amount;
    cout << "\nPaid By (Member ID): " << payerID;
    cout << "\nCategory: " << category;
    cout << "\nDate: " << date << endl;
}
int Expense::getExpenseID() {
    return expenseID;
}
double Expense::getAmount() {
    return amount;
}