#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[INT16_MAX];
    int fib(int n) 
    {
        if(n<=1)
        {
            return n;
        }
        if(dp[n]!=-1)
            return dp[n];
        else
        {
            if(dp[n-1]==-1)
            {
                dp[n-1]=fib(n-1);
            }
            if(dp[n-2]==-1)
            {
                dp[n-2]=fib(n-2);
            }
            dp[n]=dp[n-1]+dp[n-2];
            return dp[n];
        }
    }
};
int main()
{
    Solution obj;
    int len;
    cin>>len;
    int i;
    for(i=0;i<INT16_MAX;i++)
    {
        obj.dp[i]=-1;
    }
    cout<<obj.fib(len);
     return 0;
}