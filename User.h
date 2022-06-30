//
// Created by Lenovo 500 on 7/17/2021.
//

#ifndef DATASTRUCTURE_PROJECT_USER_H
#define DATASTRUCTURE_PROJECT_USER_H


#include <iostream>
#include <ctime>
#include <random>
#include<fstream>
//#include "UserManager.h"
using namespace std;

struct friendNode;

class User
{

private:
    string name;
    string userName;
    string email;
public:
    friendNode *node;
    User();
    User(string n, string u, string e);
    void setName(string n);
    void setUserName(string u);
    void setEmail(string e);

    string getName();
    string getUserName();
    string getemail();

    void print();

    friendNode *rightRotate(friendNode *current);
    friendNode *leftRotate(friendNode *node);
    friendNode *Add(friendNode *node, string data, User* user);
    friendNode *deletion(friendNode* root, string data);

    User* Find (friendNode* root, string key);
    void inorder(friendNode *root);
    void getFriendInfo();


};
struct friendNode
{
    string data;
    int priority;
    User* user;
    friendNode *left;
    friendNode *right;
};


#endif //DATASTRUCTURE_PROJECT_USER_H
