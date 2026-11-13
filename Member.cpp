
#include <iostream>
#include <cstring>
#include "Member.h"

using namespace std;

Member::Member() {
    id = 0;
    strcpy(name, "");
}

void Member::setMember(int memberID, const char memberName[]) {
    id = memberID;
    strcpy(name, memberName);
}

void Member::displayMember() {
    cout << "Member ID: " << id << endl;
    cout << "Member Name: " << name << endl;
}

int Member::getID() {
    return id;
}
