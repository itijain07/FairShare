
#ifndef EXPENSE_H
#define EXPENSE_H

class Expense {
private:
    int expenseID;
    char description[100];
    double amount;
    int payerID;
    char category[30];
    char date[20];

public:
    Expense();

    void setExpense(int id, const char desc[],
                    double amt, int payer,
                    const char cat[], const char expDate[]);

    void displayExpense();
    double getAmount();
    int getExpenseID();
};

#endif
