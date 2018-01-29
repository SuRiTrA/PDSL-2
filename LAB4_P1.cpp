#include <iostream>
using namespace std;


/* Node class to store the nodes */
class Node
{
  public:
  int data;
  Node* next;
  Node()
  {
    data=0;
    next=NULL;
  }
};


/*   Stack via Linked list   */
class StackLL
{
  public:
  Node* head;
  StackLL()
  {
    head=NULL;
  }
  void push(int num);
  void pop();
  void display();
};


/*  Queue via linked list  */
class QueueLL
{
  public:
  Node* head;
  Node* tail;
  QueueLL()
  {
    head=NULL;
    tail=NULL;
  }
  void enqueue(int num);
  void dequeue();
  void display();
};


/*  pushing in a stack node  */
void StackLL::push(int num)
{
  Node* temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    return;
  }
  temp->next=head;
  head=temp;
}


/*  popping in a stack node  */
void StackLL::pop()
{
  Node* temp;
  if(head==NULL)
  { 
   cout<<"\n \nUNDERFLOW !!! The stack is empty";
   return;
  }
  temp=head;
  head=head->next;
  temp->next=NULL;
  cout<<"\n \n"<<temp->data<<" is being deleted from the stack";
  delete temp;
}


/*  displaying a stack  */
void StackLL::display()
{
  Node *curr = head;
  cout<<"\n \n";
  while (curr!=NULL)
  {
    cout << curr->data << "->" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
}


/*  enqueuing in a queue  */
void QueueLL::enqueue(int num)
{
  Node *temp=new Node;
  temp->data=num;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp; 
  }
  else
  {
    tail->next=temp;
  }
  tail=temp;
}


/*  dequeuing a queue   */
void QueueLL::dequeue()
{
  Node* temp;
  if(head==NULL)
  {
   cout<<"\n \nQueue is empty !!!! UNDERFLOW";
   return;
  }
  temp=head;
  head=head->next;
  cout<<"\n \n"<<temp->data<<" is being deleted";
  temp->next=NULL;
  delete temp;
}


/*  displaying the queue   */
void QueueLL::display()
{
 {
  Node *curr = head;
  cout<<"\n \n";
  while (curr!=NULL)
  {
    cout << curr->data << "->" ;
    curr = curr->next;
  }
  cout << "NULL" <<endl;
 }
}

/* main function to test the codes */
int main()
{
  StackLL SLL;
  QueueLL QLL;
  cout<<"\n \n****IMPLEMENTING STACK AND QUEUE USING ARRAY AND LINKED LIST****";
  
  /*Checking for stack and queue by linked list*/
  SLL.push(12);
  SLL.push(23);
  SLL.push(34);
  SLL.display();
  SLL.pop();
  SLL.display();
  QLL.enqueue(12);
  QLL.enqueue(23);
  QLL.enqueue(34);
  QLL.display();
  QLL.dequeue();
  QLL.display();
  return 0;
}
