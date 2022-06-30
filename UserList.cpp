#include "UserList.h"
#include "User.h"
/**
 * Empty constructor make the head and tail of the linkedlist points to nullptr
 */
UserList::UserList()
{
    head=nullptr;
    tail=nullptr;
}
/**
 * Parameterized constructor take a pointer points to a suer
 * @param u: equal the User to U
 */
UserList::UserList(User* u)
{
    head->user=u;
    tail=head;
    head->next=nullptr;
    tail->next=nullptr;
}
/**
 * Function to add a new user in linkedlist
 * @param u a new user will be added in linkedlist
 */
void UserList::addUser(User* u)
{
    Node *temp=new Node();
    temp->user=u;
    temp->next=nullptr;
    if (head==nullptr)
    {
        tail=head=temp;
    }
    else
    {
        tail->next=temp;
        tail = tail->next;
    }
}
/**
 * print whole information oof each user in linkedlist
 */
void UserList::printList()
{
    Node* current= head;
    while(current!=nullptr)
    {
        current->user->print();
        current=current->next;
    }

}

/**
 *
 * @param userName: the userName of a specific user in linkedlist
 * @return address oof this user
 */
User* UserList::searchUser(string userName)
{
    Node* current= head;
    while(current!=nullptr)
    {

        if(current->user->getUserName()==userName)
        {
            return current->user;
        }
        current=current->next;
    }
    return nullptr;
}
/**
 * to get the address of the head of linkedlist
 * @return head
 */
Node* UserList::getHead()
{
    return head;
}
/**
 * destroy elements
 */
UserList::~UserList ()
{
    Node * curr =head;
    while(curr!=NULL)
    {
        head=head->next;
        delete curr;
        curr=head;
    }
}
