# FairShare — Integrated C++ DSA Project

This version brings all four classmates' modules into **one executable and menu**.

## Build (Windows, MinGW g++)
Open a terminal in this folder and run:

```bash
g++ -std=c++17 -Wall -Wextra FairShare.cpp main.cpp Member.cpp Expense.cpp ExpenseList.cpp Riddhisha/balance.cpp Riddhisha/fairshare.cpp Riddhisha/queue.cpp Riddhisha/settlement.cpp Riddhisha/split.cpp Riddhisha/undo.cpp Priyal/PriyalMain.cpp Aditi/Graph.cpp Aditi/Heap.cpp Aditi/MonthlyTracker.cpp -o FairShare.exe
```

Run: `./FairShare.exe` (PowerShell: `.\FairShare.exe`).

## Notes
- The single program entry point is `FairShare.cpp`. Previous `main()` functions were renamed as module functions; original module algorithms remain.
- **Important limitation:** These are six menu-accessible **independent demonstrations**, NOT one shared database. Data entered into one module is not automatically available in another. Some modules contain hard-coded demonstration data. Do not claim end-to-end shared balance/settlement integration in a report or viva.
- Priyal's extensionless files are precompiled binaries; they are not required. Priyal's `.cpp` files duplicate implementations in her `.h` files; the build command intentionally uses `PriyalMain.cpp` and its headers only.
- Do not compile all `.cpp` files with a wildcard; use the build command above.
- Individual module input validation and design limitations remain; use valid numeric inputs for the demonstration.
