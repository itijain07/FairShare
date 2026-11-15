# FairShare shared-data checkpoint

This version connects **Iti's entered members and expenses** to **Priyal's Hash Table, BST, AVL, and search/sort menu**. It is an intermediate integration checkpoint, NOT a fully shared-data app.

## Demo sequence
1. Run main menu option 1; enter members and expenses. Choose an expense ID to search. For the deletion prompt, enter a non-existent ID (e.g., 999) to keep your demo expense.
2. Return to the main menu and choose option 3. Search the member ID in Hash Table; search the expense ID in BST and AVL; display sorted IDs.
3. Riddhisha's splitting, Aditi's graph/heap/monthly tracker remain standalone demos and do not yet read shared data.

## Mac build
From the directory containing `FairShare.cpp`:

```sh
g++ -std=c++17 FairShare.cpp SharedData.cpp main.cpp Member.cpp Expense.cpp ExpenseList.cpp Riddhisha/*.cpp Priyal/PriyalMain.cpp Aditi/*.cpp -o FairShare
./FairShare
```

The data is stored in memory for the current run; exiting the app clears it. Option 1 replaces the in-memory members and expenses. The original `main.cpp` still asks to search and delete an expense; deleting an existing expense removes it from shared data. No GUI is included.
