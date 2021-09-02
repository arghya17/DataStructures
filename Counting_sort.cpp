#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter value of K that is range of counting sort\n";
    int k;
    cin>>k;
    cout<<"Enter number of elements\n";
    int n;
    cin>>n;
    int a[n];
    int b[k];
    int c[n];
    cout<<"Enter numbers in the array in the range 0 to k-1\n";
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<k;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(i=1;i<k;i++)
    {
        b[i]=b[i]+b[i-1];//calculating last index of number i
    }
    for(i=n-1;i>=0;i--)//starting from last as only last index is stored in b array
    {
        c[b[a[i]]-1]=a[i];//stable sort retains the order of repeated numbers in sorted array
        b[a[i]]--;
    }
    cout<<"The sorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<c[i]<<"  ";
    }
    cout<<endl;
}