//
// Created by Lenovo 500 on 7/17/2021.
//

#ifndef DATASTRUCTURE_PROJECT_USERMANAGER_H
#define DATASTRUCTURE_PROJECT_USERMANAGER_H

#include <iostream>
#include<fstream>
#include "UserList.h"
#include "User.h"

class UserManager
{
public:
    UserManager();
    void getFileInfo();
    void getFriendInfo();
    UserList* getList();
    User* getUser();
private:
    string myText;
    User* u;
    UserList* users;
};


#endif //DATASTRUCTURE_PROJECT_USERMANAGER_H
