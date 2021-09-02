#include <bits/stdc++.h>
using namespace std;
int peak(int a[],int l,int u)
{
    int c;
    c=(l+u)/2;
    if(a[c]<a[c-1])
    {
        return peak(a,l,c-1);
    }
    else if(a[c]<a[c+1])
    {
        return peak(a,c+1,u);
    }
    else
    {
        return a[c];
    }
}
int main()
{
    int n;
    cin>>n;
    int i;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"Peak is "<<peak(a,0,n-1)<<endl;
}