
#ifndef MEMBER_H
#define MEMBER_H

class Member {
private:
    int id;
    char name[50];

public:
    Member();

    void setMember(int memberID, const char memberName[]);
    void displayMember();
    int getID();
};

#endif
