
#ifndef EXPENSELIST_H
#define EXPENSELIST_H

#include "Expense.h"

struct ExpenseNode {
    Expense data;
    ExpenseNode* next;
};

class ExpenseList {
private:
    ExpenseNode* head;

public:
    ExpenseList();
    void searchExpense(int id);
    void deleteExpense(int id);

    void addExpense(Expense e);
    void displayAllExpenses();
    ~ExpenseList();
};

#endif
