#include <bits/stdc++.h>
using namespace std;
//pivot element is the last one
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int l,int u)//partition returns the correct position of the pivot element in the array
{
    int pivot=a[u];
    int i=l-1;
    int j;
    for(j=l;j<u;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
        
    }
    swap(&a[i+1],&a[u]);
    return i+1;
}
void quick_sort(int a[],int l,int u)
{
    if(l>=u)
    {
        return;
    }
    int pi=partition(a,l,u);
    quick_sort(a,l,pi-1);
    quick_sort(a,pi+1,u);

}
int main()
{
    int n;
    cin>>n;
    int i;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
