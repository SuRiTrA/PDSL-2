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

