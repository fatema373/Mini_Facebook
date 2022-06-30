#include <iostream>
#include<string>
#include <ctime>
#include <random>
#include "User.h"
#include "UserList.h"
#include "UserManager.h"
using namespace std;
int main()
{
    User* user = new User;
    UserManager use;
    use.getFileInfo();
    int select;

    while (true){
        menu:
        cout<<"Main Menu: \n"
            <<"1- Login\n"
            <<"2- Exit\n";

        cin>>select;
        switch (select) {

            case 1:
            {
                cout << "Please type your userName: " << endl;
                string username;
                cin>>username;
                if(use.getList()->searchUser(username) != nullptr){

                    user = use.getList()->searchUser(username);
                    while (true) {
                        Loggedin:
                        cout <<"----------------------\n"
                             << "1- List all friends\n"
                             << "2- Search by username\n"
                             << "3- Add friend\n"
                             << "4- Remove friend\n"
                             << "5- People you may know\n"
                             << "6- logout\n";

                        cin >> select;

                        switch (select) {
                            case 1: {

                                if(user->node==nullptr)
                                {
                                    cout<<endl;
                                    cout<<"You have no friends"<<endl;
                                    cout<<endl;
                                }
                                else
                                {
                                    cout<<endl;
                                    cout<<"Your friends: "<<endl;
                                    user->inorder(user->node);
                                    cout<<endl;
                                }
                                break;
                            }
                            case 2: {
                                cout<<endl;
                                cout << "Please enter your Friend's userName: " << endl;
                                cin>>username;
                                if(user->Find(user->node, username)!=nullptr)
                                {
                                    user->Find(user->node, username)->print();
                                } else
                                    cout<<"Not found\n";

                                break;
                            }
                            case 3: {
                                cout<<endl;
                                cout << "Please enter userName to add: " << endl;
                                cin>>username;
                                if(use.getList()->searchUser(username)==nullptr)
                                {
                                    cout<<"User not found"<<endl;
                                    goto Loggedin;
                                }
                                else
                                {
                                    if(user->Find(user->node, username)==nullptr)
                                    {
                                        user->node = user->Add(user->node,username,use.getList()->searchUser(username));
                                        use.getList()->searchUser(username)->node =  use.getList()->searchUser(username)->Add(use.getList()->searchUser(username)->node, user->getUserName(), user);

                                        cout<<"You are now friends"<<endl;
                                    }
                                    else cout<<"You are already friends"<<endl;
                                }
                                break;
                                case 4:
                                {
                                    cout << "Please enter friend's userName to delete: " << endl;
                                    cin>>username;
                                    if(use.getList()->searchUser(username)==nullptr)
                                    {
                                        cout<<"User not found"<<endl;
                                        goto Loggedin;
                                    }

                                    else if(user->Find(user->node,username)!=nullptr)
                                    {
                                        user->node =user->deletion(user->node,username);
                                        use.getList()->searchUser(username)->node =use.getList()->searchUser(username)-> deletion(use.getList()->searchUser(username)->node, user->getUserName());

                                        cout<<"\nDone"<<endl;
                                    }

                                    break;
                                }
                                case 5: {
                                    int counter=0;
                                    Node* current=use.getList()->getHead();
                                    cout<<"\nRecommendations: \n"<<endl;
                                    while(current!=nullptr&&counter<5)
                                    {
                                        if(user->Find(user->node,current->user->getUserName())==nullptr&&user->getUserName()!=current->user->getUserName())
                                        {
                                            cout<<(counter+1)<<") "<<current->user->getUserName()<<", "<<current->user->getName()<<endl;

                                            counter++;
                                        }
                                        current=current->next;
                                    }
                                    cout<<endl;
                                    break;
                                }
                                case 6:
                                {
                                    cout<<"Are you sure you want to logout?"<< "\nType 'logout or Logout' to confirm: "<<endl;
                                    string choice;
                                    cin>>choice;
                                    if(choice=="logout"||choice=="Logout")
                                    {
                                        goto menu;
                                    }
                                    else
                                    {
                                        cout<<"Wrong input"<<endl;
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {
                    cout<<"Wrong UserName\n";
                    goto menu;
                }
                break;
            }

            case 2:{
                cout<<"Are you sure you want to exit?"<< "\nType 'Exit or exit' to confirm: "<<endl;
                string choice;
                cin>>choice;
                if(choice=="exit"||choice=="Exit")
                {
                    exit(0);
                }
                else
                {
                    cout<<"Wrong input"<<endl;
                }
                break;
            }
        }
        return 0;
    }



}

