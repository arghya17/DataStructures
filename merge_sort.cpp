#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int u)
{
    int mid=(l+u)/2;
    int n1=mid-l+1;
    int n2=u-mid;
    int b[n1];
    int c[n2];
    int i=0;
    int p=0,q=0;
    for(i=l;i<=mid;i++)
    {
        b[p]=a[i];
        p++;
    }
    for(i=mid+1;i<=u;i++)
    {
        c[q]=a[i];
        q++;
    }
    p=0;q=0;i=l;
    while(p<n1&& q<n2)
    {
        if(b[p]<c[q])
        {
            a[i]=b[p];
            i++;
            p++;
        }
        else
        {
            a[i]=c[q];
            i++;
            q++;
        }
    }
    while(p<n1)
    {
        a[i]=b[p];
        i++;
        p++;
    }
    while(q<n2)
    {
        a[i]=c[q];
        i++;
        q++;
    }
}
void merge_sort(int a[],int l,int u)
{
    if(l>=u)
    {
        return;
    }
    int mid=(l+u)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,u);
    merge(a,l,u);
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
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}