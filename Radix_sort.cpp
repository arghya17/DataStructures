#include <bits/stdc++.h>
using namespace std;
void counting_sort(int c[],int n,int p)
{
    int k;
    k=10;
    int a[n];
    int b[k];
    p=(int)(round(pow(10,p)));
    int p1=p/10;
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=c[i];
    }
    for(i=0;i<k;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        b[(a[i]%p)/p1]++;
    }
    for(i=1;i<k;i++)
    {
        b[i]=b[i]+b[i-1];//calculating last index of number i
    }
    for(i=n-1;i>=0;i--)//starting from last as only last index of repeated elements are stored in b array
    {
        c[b[(a[i]%p)/p1]-1]=a[i];//stable sort retains the order of repeated numbers in sorted array
        b[(a[i]%p)/p1]--;
    }
}
int main()
{
    cout<<"Enter number of elements\n";
    int n;
    cin>>n;
    cout<<"Enter elements\n";
    int i;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p;
    cout<<"Enter maximum length of number's entered\n";
    int max;
    cin>>max;
    for(i=1;i<=max;i++)
    {
        counting_sort(a,n,i);//counting sort from least significant digit and moving to most significant
    }
    cout<<"The sorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}