#include <iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;
};

class SLL
{
   public:
   Node* head;
   int size;
   SLL()
   {
     size=0;
     head=NULL;
   }
   void insert(int n);
   Node* getNode(Node* h, int pos);
   void reverseNode(Node* h);
   void display(Node* h);
   void reverseOn(Node* h);
};

void SLL::insert(int n)
{
   Node* node=new Node();
   node->data=n;
   node->next=NULL;
   if(head==NULL)
   {
      head=node;
   }
   else
   {
      node->next=head;
      head=node;
   }
   size++;
}

Node* SLL::getNode(Node* h, int pos)
{
   Node* tmp=h;			
   for (int j=1; j<pos; ++j) 
   {	
		tmp = tmp->next;
   }
   return tmp;
}

void SLL::reverseNode(Node* h)
{
   int a=1,b=size;
   for(;a<=size/2;a++,b--)
   {
      Node* n1;
      Node* n2;
      n1=getNode(h,a);
      n2=getNode(h,b);
      int t=n1->data;
      n1->data=n2->data;
      n2->data=t;   
   }   
}

void SLL::display(Node* h)
{
   Node* tmp=h;
   cout<<"\n";
   while(tmp!=NULL)
   {
      cout<<tmp->data<<"\t->\t";
      tmp=tmp->next;
   }
   cout<<"NULL \n"<<endl;
}

void SLL::reverseOn(Node* head)
{
   Node* prev=head;
   Node* cur=head->next;                  ;
   Node* t;
   if(size>1)
   {
   while(cur->next!=NULL)
   {
     t=cur->next;
     cur->next=prev;
     prev=cur;
     cur=t;
   }
   cur->next=prev;
   head->next=NULL;
   head=cur;
   display(head);
   } 
}
     
int main()
{
   SLL sll;
   sll.insert(1);
   sll.insert(2);
   sll.insert(3);
   sll.insert(4);
   sll.insert(5);
   sll.display(sll.head);
   //sll.reverseNode(sll.head);
   //sll.display();
   sll.reverseOn(sll.head);
   return 0;
}
     
  
