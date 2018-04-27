// Example program
#include <iostream>
#include <string>

using namespace std;

class node
{
    public:
    int data;
    node* next;
    node()
    {
        data=0;
        next=NULL;
    }
};

class linkedlist
{
    public:
    node* head;
    linkedlist()
    {
        head=NULL;
    }
    void insert(int key)
    {
        node* newnode=new node;
        newnode->data=key;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    void displayll(node* n)
    {
        if(n!=NULL)
        {
            cout<<n->data<<"\t";
            displayll(n->next);
        }
        else
        {
            return;
        }
    }
    void displayllrev(node* n)
    {
        if(n->next!=NULL)
        {
            displayllrev(n->next);
            cout<<n->data<<"\t";
        }
        else
        {
            cout<<n->data<<"\t";
            return;
        }
    }
};

int main()
{
    linkedlist ll;
    ll.insert(89);
    ll.insert(65);
    ll.insert(94);
    ll.insert(19);
    ll.insert(34);
    ll.insert(2);
    ll.displayll(ll.head);
    cout<<endl<<endl;
    ll.displayllrev(ll.head);
    return 0;
}
