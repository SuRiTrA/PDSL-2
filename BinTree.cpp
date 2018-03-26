#include<iostream>
using namespace std;

class node
{
   public:
   int data;
   node *parent,*left,*right;
   node()
   {
      parent=NULL;
      left=NULL;
      right=NULL;
      data=0;
   }
};

class bTree
{
   public:
   node* root=NULL;
   void insert(node* v, int data)
{ 
   node* temp=new node;
   temp->data=data;
   if(root==NULL)
   {
     root=temp;
   }
   else
   {
   if(v->data>=data)
   {
     if(v->left!=NULL)
     {
       insert(v->left,data);
     }
     else
     {
        v->left=temp;
     }
   }  
   else
   {
     if(v->right!=NULL)
     { 
       insert(v->right, data);
     }
     else
     {
       v->right=temp;
     } 
   }
 }
}
void display(node* v)
  {  
   if(v==NULL)
   {
     return;
   }
   display(v->left);
   cout<<v->data<<"\t";
   display(v->right);
 }


void deletenode()
{

}

void searchnode()
{

}


};

int main()
{
   bTree BT;
   int n;
   cout<<"\n \nEnter the number of entries you want to enter: ";
   cin>>n;
   for(int i=0;i<n;i++)
   { cout<<"\nDATA "<<(i+1)<<": ";
     int num=0;
     cin>>num;
     BT.insert(BT.root,num);
   }
   BT.display(BT.root);
   return 0;
}
