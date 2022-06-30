#include "UserManager.h"
#include <string>
/**
 * Empty constructor
 */
UserManager::UserManager(){}
/**
 * Function Reads all users from data and store them in linked list then call another method to store each user's friend
 */
void UserManager:: getFileInfo()
{
    users = new UserList;
    ifstream MyReadFile("C:\\Users\\Lenovo 500\\CLionProjects\\DataStructure_Project\\all-users.in");
    while (!MyReadFile.eof())
    {
        u=new User();
        getline(MyReadFile,myText);

        int found=myText.find(',');
        string userName= myText.substr(0,found);
        myText=myText.substr(found+2);

        int found2= myText.find(',');
        string name=myText.substr(0,found2);
        string email=myText.substr(found2+2);

        u->setUserName(userName);
        u->setName(name);
        u->setEmail(email);

        users->addUser(u);

    }
    getFriendInfo();
    MyReadFile.close();
}
/**
 * get the address of linkedlist
 * @return users
 */
UserList* UserManager::getList()
{
    return users;
}
/**
 *
 * @return U
 */
User* UserManager::getUser()
{
    return u;
}
/**
 * Function read from file the relations of each user and store them in treap
 */
void UserManager::getFriendInfo()
{
    string user_name1,user_name2;
    Node* current=users->getHead();
    while(current!=nullptr)
    {
        ifstream file_("C:\\Users\\Lenovo 500\\CLionProjects\\DataStructure_Project\\all-users-relations.in");
        if(file_.is_open())
        {
            while(file_>>user_name1>>user_name2)
            {

                user_name1.assign(user_name1.begin(),user_name1.end()-1);

                if(current->user->getUserName()==user_name1)
                {
                    current->user->node=current->user->Add(current->user->node,user_name2,users->searchUser(user_name2));
                }

                else if(current->user->getUserName()==user_name2)
                {
                    current->user->node=current->user->Add(current->user->node,user_name1,users->searchUser(user_name1));
                }
            }

        }

        else
        {
            cout << "file not opened";

        }
        file_.close();
        current->user->inorder(current->user->node);
        current=current->next;

    }

}
