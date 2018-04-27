// Example program
#include <iostream>

using namespace std;

class Heap
{
    public:
    int heap[100];
    int size,tsize;
    Heap()
    {
        size=0;
        tsize=0;
    }
    void insert()
    {
        cout<<"\n \nEnter the new value to be entered: ";
        cin>>heap[size++];
        tsize++;
    }
    void heapify(int n, int i)
    {
        int l=2*i+1;
        int r=2*i+2;
        if(l<n)
        {
            if(r<n)
            {
                int max=heap[l]>=heap[r]?l:r;
                if(heap[i]>heap[max])
                {
                    return;
                }
                else
                {
                    int temp=heap[max];
                    heap[max]=heap[i];
                    heap[i]=temp;
                    heapify(n, max);
                }
            }
            else
            {
                if(heap[i]>heap[l])
                {
                    return;
                }
                else
                {
                    int temp=heap[l];
                    heap[l]=heap[i];
                    heap[i]=temp;
                    heapify(n, l);
                }
            }
        }
        else
        {
        	return;
        }
    }
    void heapsort(int *arr, int n)
    {
        //creating a heap from the array
        for(int i=(n-1)/2;i>=0;i--)
        {
            heapify(size, i);
        }
        
        display();
        //heapsorting
        for(int i=n-1;i>=0;i--)
        {
            int temp=*arr;
            *arr=*(arr+i);
            *(arr+i)=temp;
            heapify(i, 0);
        }
        
    }
    
    void display()
    {
        cout<<"\n \n";
        for(int a=0;a<size;a++)
        {
          cout<<heap[a]<<"\t";
        }
        cout<<"\n \n";
    }
};

int main()
{
    Heap hp;
    hp.insert();
    hp.insert();
    hp.insert();
    hp.insert();
    hp.insert();
    hp.insert();
    hp.insert();
    hp.heapsort(hp.heap, hp.size);
    hp.display();
    return 0;
}
  
