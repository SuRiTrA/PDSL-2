/*
This program implements Singly Linked List using C++ which includes the following functions: 
insert(int data)  
insertAt(int pos, int data)  
delete()
deleteAt(int pos)
countItems()
display()
*/

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node* next;
    Node()
    {
        data=0;
        next=NULL;
    }
};
class CLL
{
    Node* head;
    Node* tail;
    int size;
    public:
    CLL()
    {
        size=0;
        head=NULL;
        tail=NULL;
    }
   void insert(int n);
   void insertAt(int data, int position);
   void deleten();
   void deleteAt(int pos);
   int countItems();
   void display();
};


//inserts a node at the end of the circle
void CLL::insert(int n)
{
    Node temp=new Node;
    temp->data=n;
    temp->NULL;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
        tail=temp;
        tail->next=head;
    }
    else
    {
        tail->next=temp;
        tail=temp;
        tail->next=head;
    }
    size++
}



/*
   It includes the position at which the insertion happens. Positioning starts with 1.  
   Example: insertAt(1, 3)inserts 3 at the first position. 
	    It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.
*/ 
void CLL::insertAt(int position, int num)
{
    if(position>size)
    {
        cout<<"\nNot many elements in the list present !";
    }
    else if(position==0)
    {
        Node tmp;
        tmp->data=num;
        tmp->next=head;
        head=tmp;
        size++;
    }
    else if(position==size)
    {
        Node *tmp=new Node;
        tmp->data=num;
        tmp->next=head;
        if(head==NULL)                           // Steps to perform when the list is empty.
        {
            head=tmp;
        }
        else
        {
            tail->next=tmp;
        }
        tail=tmp;
        size++;
    }
    else
    {
        Node* n=new Node;
	    n->data=num;
	    Node* traverse=head;
        int count=0;
        while(count<position-1)
        {
          traverse=traverse->next;
          count++;
        }
        n->next=traverse->next;
        traverse->next=n;
        size++;
    }
}
    
    
//Deletes the element at the end of the list 

    

    
