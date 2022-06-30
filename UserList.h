//
// Created by Lenovo 500 on 7/17/2021.
//

#ifndef DATASTRUCTURE_PROJECT_USERLIST_H
#define DATASTRUCTURE_PROJECT_USERLIST_H
#include "User.h"

struct Node
{
    User* user;
    Node *next;
    Node()
    {
        next=nullptr;
    }
    Node(User* u)
    {
        (*user)=(*u);
        next=nullptr;
    }
};
class UserList
{
private:
    Node *head;
    Node *tail;
public:
    UserList();
    UserList(User* u);
    void addUser(User* u);
    void printList();
    Node* getHead();
    User* searchUser(string n);
    ~UserList ();


};


#endif //DATASTRUCTURE_PROJECT_USERLIST_H
