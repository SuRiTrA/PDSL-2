// Example program
#include <iostream>

using namespace std;

class Heap
{
    public:
    int heap[100];
    int size;
    Heap()
    {
        size=0;
    }
    void insert()
    {
        cout<<"\n \nEnter the new value to be entered: ";
        cin>>heap[size++];
    }
    void heapify(int i)
    {
        int l=2*i+1;
        int r=2*i+2;
        int max=heap[l]>=heap[r]?l:r;
        if(l<size)
        {
            if(r<size)
            {
                if(heap[i]>heap[max])
                {
                    return;
                }
                else
                {
                    int temp=heap[max];
                    heap[max]=heap[i];
                    heap[i]=temp;
                    heapify(max);
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
                    heapify(l);
                }
            }
        }             
    }
    void heapsort(int n)
    {
        //creating a heap from the array
        for(int i=(n-1)/2;i>=0;i--)
        {
            heapify(i);
        }
        
        //heapsorting
        for(int i=n-1;i>=0;i--)
        {
            int temp=heap[0];
            heap[0]=heap[i];
            heap[i]=temp;
            heapify(0);
        }
        
    }
    
    void display()
    {
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
    hp.heapsort(hp.size);
    hp.display();
    return 0;
}
        
