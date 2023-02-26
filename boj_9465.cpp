#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int dp[100002][2];

int main()
{
    int tc;
    cin>>tc;
    
    for (int idx = 0; idx < tc; idx++)
    {
        int table[100002][2];
        int n;
        cin>>n;
        
        for (int i = 0; i < n; i++)
        {
            cin>>table[i][0];
        }
        for (int i = 0; i < n; i++)
OAOAOA        {
            cin>>table[i][1];
        }
        dp[0][0] = table[0][0];
        dp[0][1] = table[0][1];
        dp[1][0] = dp[0][1] + table[1][0];
        dp[1][1] = dp[0][0] + table[1][1];
        
        for (int i = 2; i < n; i++)
        {
            dp[i][0] = table[i][0] + max(dp[i-1][1], dp[i-2][1]);
            dp[i][1] = table[i][1] + max(dp[i-1][0], dp[i-2][0]);
        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<"\n";
    }
    return 0;
}


