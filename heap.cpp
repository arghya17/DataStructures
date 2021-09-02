#include <bits/stdc++.h>
using namespace std;//heap is from 0 to n-1
int heap_size;
void print(int a[]);
void max_heapify(int a[],int i);
void build_max_heap(int a[]);
void heap_sort(int a[])
{
    int i=0;
    while(heap_size >0)
    { 
        int t=a[0];
        a[0]=a[heap_size-1];
        a[heap_size-1]=t;
        heap_size--;
        max_heapify(a,0);
    }
}
void max_heapify(int a[],int i)
{
    int max=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<heap_size && a[left]>a[max])
    {
        max=left;
    }
    if(right<heap_size && a[right]>a[max])
    {
        max=right;
    }
    if(max!=i)
    {
        int t=a[max];
        a[max]=a[i];
        a[i]=t;
        return max_heapify(a,max);
    }
    else
    {
        return;
    }
}
void build_max_heap(int a[])
{
    int i;
    for(i=heap_size/2 +1;i>=0;i--)
    {
        max_heapify(a,i);
    }
}
void print(int a[])//tree like printing
{
    int i=0;
    int k=1;
    while(true)
    {
        for(int j=1;j<=k;j++)
        {
            cout<<a[i++]<<" ";
            if(i>=heap_size)
            {
                break;
            }
        }
        k=k*2;
        cout<<endl;
         if(i>=heap_size)
        {
            break;
        }
    }

}
int main()
{
    int n;
    cin>>n;
    int i;
    heap_size=n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build_max_heap(a);
    print(a);
    heap_sort(a);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}