#pragma once
#include <string>
#include <vector>
struct SharedMember { int id; std::string name; };
struct SharedExpense { int id; std::string description; double amount; int payerID; std::string category; std::string date; };
extern std::vector<SharedMember> sharedMembers;
extern std::vector<SharedExpense> sharedExpenses;
