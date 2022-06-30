#include "User.h"
/**
 * Empty constructor to add initial values
 */
User::User()
{
    name="";
    userName="";
    email="";
    node=nullptr;
}
/**
 * Parameterized constructor
 * @param n: equal the name to that variable n
 * @param u: equal the username to that variable u
 * @param e: equal the email to that variable e
 */
User::User(string n, string u, string e)
{
    name=n;
    userName=u;
    email=e;

}
/**
 * Function to set the name of the user
 * @param n: equal the name to that variable n
 */
void User:: setName(string n)
{
    name=n;
}
/**
 * Function to set the username of the user
 * @param u: equal the username to that variable u
 */
void User:: setUserName(string u)
{
    userName=u;
}
/**
 * Function to set the email of the user
 * @param e: equal the email to that variable
 */
void User::setEmail(string e)
{
    email=e;
}
/**
 *Function to get the name of the user
 * @return name
 */
string User::getName()
{
    return this->name;
}
/**
 *Function to get the username of the user
 * @return username
 */
string User::getUserName()
{
    return this->userName;
}
/**
 *Function to get the e-mail of the user
 * @return email
 */
string User::getemail()
{
    return this->email;
}
/**
 *Function to print information of the user
 */
void User::print()
{
    cout<<userName<<", "<<name<<", "<<email<<endl;
}
//Treap related functions:
/**
  * T1, T2 and T3 are subtrees of the tree rooted with y
  (on left side) or x (on right side)
                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3
  * A utility function to right rotate subtree rooted with y
 * @param current
 * @return
 */
friendNode *User::rightRotate(friendNode *current)
{
    friendNode *leftnode = current->left;
    friendNode *T2 = leftnode->right;
    //perform rotation
    leftnode->right = current;
    current->left = T2;

    // Return new root
    return leftnode;
}
/**
 * A utility function to left rotate subtree rooted with x
 * T1, T2 and T3 are subtrees of the tree rooted with y
  (on left side) or x (on right side)
                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3
 * @param node
 * @return
 */
friendNode *User::leftRotate(friendNode *node)
{
    friendNode *y = node->right;
    friendNode *T2 = y->left;

    // Perform rotation
    y->left = node;
    node->right = T2;

    // Return new root
    return y;
}
/**
 * Recursive implementation of insertion in Treap
 * @param node: take a root node
 * @param data: username
 * @param user: pointer points to a user
 * @return
 */
friendNode* User::Add(friendNode *node, string data,User* user) //(tl3at node , emad , pointer le user emad)
{

    // if friendNode not equal NULL they are already friends
    if(Find(node, data)!=nullptr)
    {
        return nullptr;
    }
    // If friendNode is NULL, create a new friendNode and return it
    else
    {
        if (node==NULL)
        {
            friendNode* temp = new friendNode;
            temp->data = data;
            temp->priority = rand()%100;
            temp->user=user;
            temp->left = temp->right = NULL;
            return temp;
        }
        else if (data < node->data)
        {
            node->left = Add(node->left, data,user);
            if (node->left->priority > node->priority)
                node = rightRotate(node);
        }
        else
        {
            node->right = Add(node->right, data,user);
            if (node->right->priority > node->priority)
                node = leftRotate(node);
        }
        return node;
    }
}
/**
 * Recursive implementation of find in Treap to find a specific user and returns its address
 * @param root: passing the root of the friend tree
 * @param key: passing the value of the username
 * @return the address of the found friendNode
 */
User* User::Find (friendNode* root, string key)
{
    if(root==NULL)
    {
        return nullptr;
    }
    else if(root->data==key)
    {
        return root->user;
    }
    else if(root->data>key)
    {
        return Find(root->left, key);
    }
    else
        return Find(root->right, key);

}
/**
 * print friends of a user
 * @param root
 */
void User::inorder(friendNode *root)
{
    if(root==NULL)
        return;
    if(root != NULL)
    {

        inorder(root->left);
        cout <<"UserName:" << root->data << ", Name: "<< root->user->getName() <<endl;

        inorder(root->right);
    }

}
/**
 * Recursive implementation of Delete()
 * @param root: the root of the friend tree
 * @param data: the userName of the friend i want to delete
 * @return
 */
friendNode* User::deletion(friendNode* root, string data)
{
    //
    if(root==nullptr)
        return root;
    else if(root->data>data)
    {
        root->left=deletion(root->left,data);
    }
    else if(root->data<data)
    {
        root->right=deletion(root->right,data);
    }

    else if(root->right==nullptr)
    {
        friendNode * del=root->left;
        delete(root);
        root=del;
    }
    else if(root->left==nullptr)
    {
        friendNode * del=root->right;
        delete(root);
        root=del;
    }
    else if(root->left->priority>root->right->priority)
    {
        root=rightRotate(root);
        root->right=deletion(root->right,data);

    }
    else
    {
        root=leftRotate(root);
        root->left=deletion(root->left,data);
    }
    return root;

}
