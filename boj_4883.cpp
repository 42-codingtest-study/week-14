#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>

using namespace std;


int main()
{
    int n;
    int n1,n2,n3;
    int k = 0;
    
    while(1)
    {
        long  table[100002][3];
        long  dp[100002][3];

        cin>>n;
        if (n == 0)
            break;
        k++;
        for (int i = 0; i < n; i++)
        {
            cin>>n1>>n2>>n3;
            table[i][0] = n1;
            table[i][1] = n2;
            table[i][2] = n3;
        }   //그래프 입력
        
        dp[0][0] = 999999999;
        dp[0][1] = table[0][1];
        dp[0][2] = dp[0][1] + table[0][2];
        
        for (int i = 1; i<n; i++)
        {
            vector<int> v1;
            
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + table[i][0];
            dp[i][1] = min(dp[i-1][0], min(min(dp[i-1][1],dp[i-1][2]), dp[i][0])) + table[i][1];
            dp[i][2] = min(min(dp[i-1][1], dp[i-1][2]), dp[i][1]) + table[i][2];
            
        }
        cout<<k << ". " << dp[n-1][1]<<"\n";
    }
    return 0;
}

