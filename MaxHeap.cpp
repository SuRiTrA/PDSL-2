#include<iostream>
using namespace std;



class MaxHeap
{
  public:
  int maxheap[100];
  int size;
  MaxHeap()
  { 
    size=0;
  }




  void insert(int key)
  {
  int i=size++;
  maxheap[i]=key;
  while(i!=0)
  {
    int p=(i-1)/2;
    if(maxheap[p]>=key)
      break;
    else
    {
       int temp=maxheap[p];
       maxheap[p]=maxheap[i];
       maxheap[i]=temp;
    }
    i=p;
   }
  }




  void display()
  {
   cout<<"\nTHE MAX-HEAP ELEMENTS ARE:";
   for(int i=0;i<size;i++)
   {
     cout<<"\t"<<maxheap[i];
   }
  }



  void remove()   //remove maximum element (i.e., root element)
  {
  if(size==0)
  {
     cout<<"\nTHE HEAP IS EMPTY !!! \n \n";
  }
  else if(size==1)
  {
    size--;
  }
  else
  {
    int i=0;
    maxheap[i]=maxheap[size-1];
    size--;
    while((2*i+1)+1<=size)
    {
      if((2*i+2)+1<=size)
      {
        int lc=maxheap[2*i+1];
        int rc=maxheap[2*i+2];
        int maxind=(lc>=rc)?(2*i+1):(2*i+2);
        if(maxheap[i]<maxheap[maxind])
        {
          int temp=maxheap[i];
          maxheap[i]=maxheap[maxind];
          maxheap[maxind]=temp;
          i=maxind;
        }
        
      }
      else
      {
        if(maxheap[i]<maxheap[2*i+1])
        {
          int temp=maxheap[i];
          maxheap[i]=maxheap[2*i+1];
          maxheap[2*i+1]=temp;
          i=2*i+1;
        }
        else
          break;
      }
    }
  }
 }
};



int main()
{
  MaxHeap MH;
  cout<<"\n \nEnter the number of elements you want to enter: ";
  int n;
  cin>>n;
  cout<<"\nEnter the datas:\n";
  for(int x=0;x<n;x++)
  { 
    int num;
    cout<<"\nDATA"<<(x+1)<<": ";
    cin>>num;
    MH.insert(num);
  }
  MH.display();
  MH.remove();
  MH.display();
  return 0;
}
