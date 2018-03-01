//ROUGH STORAGE NOW




#include<iostream>
using namespace std;

int arrange(int *arr,int l,int r)
{
    int pivot=arr[r];
    int x=l-1;
    for(int i=l;i<r;i++)
    {
        if(arr[i]<=pivot)
        {
            x++;
            int t=arr[i];
            arr[i]=arr[x];
            arr[x]=t;
        }
    }
    int tmp=arr[x+1];
    arr[x+1]=arr[r];
    arr[r]=tmp;
    return x+1;
}

int *qsort(int *ar, int left, int right)
{
    if(left<right)
    {
        int s=arrange(ar, left, right);
        int* ax=qsort(ar,left,s-1);
        int* bx=qsort(ar,s+1,right);
    }
    return ar;
}
void display(int* ars,int s)
{
    for(int a=0;a<s;a++)
    {
        cout<<*(ars+a)<<"\t";
    }
}
int main()
{
    int A[7]={3,5,7,2,0,9,4};
    int *sortarr=qsort(A,0,6);
    display(sortarr,7);
    return 0;
}





//rough




#include <iostream>
using namespace std;
class node
{
 public:
 int data;
 node *next;
};
class linkedList
{
 public:
 int size=0;
 node *head,*tail;
 linkedList()
 {
  head=NULL;
  tail=NULL;
 }
 void addNode(int data)
 {
  node *temp=new node;
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)
  {
   head=temp;
   tail=temp;
  }
  else
  {
   tail->next=temp;
   tail=temp;
  }
  size++;
 }
 void display()
 {
  node *temp=head;
  while(temp!=NULL)
  {
   cout<<temp->data<<" ";
   temp=temp->next;
  }
 }
};

int arrange(node* head,node* tail, int ss)
{
    int pivot=tail->data;
    node *temp, *t1;
    int c=0,times=0;
    t1->data=0;
    t1->next=head;
    temp=head;
    while(++times<ss)
    {
        int t;
        if(temp->data<=pivot)
        {
            c++;
            t1=t1->next;
            t=t1->data;
            t1->data=temp->data;
            temp->data=t;
        }
        temp=temp->next;
    }
    int x=tail->data;
    tail->data=t1->next->data;
    t1->next->data=x;
    return (c+1);
}

void QuickSortLL(linkedList ll, int s)
{
    linkedList l1,l2;
    int s1;
    if(ll.head!=ll.tail)
    {
        node* n=ll.head;
        s1=arrange(ll.head, ll.tail, s);
        l1.head=ll.head;
        l2.tail=ll.tail;
        for(int i=0;i<s1;i++)
        {
            l1.tail=n;
            n=n->next;
        }
        l1.tail->next=NULL;
        l2.head=n->next;
        QuickSortLL(l1,s1-1);
        QuickSortLL(l2,s-s1);
    }

}


int main()
{
 linkedList obj2;
 obj2.addNode(5);
 obj2.addNode(3);
 obj2.addNode(6);
 obj2.addNode(1);
 obj2.addNode(2);
 obj2.addNode(7);
 obj2.addNode(9);
 obj2.addNode(8);
 obj2.addNode(4);
 obj2.display();
 cout<<"\n";
 QuickSortLL(obj2,9);
 obj2.display();
}


