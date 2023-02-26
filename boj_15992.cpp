#include <iostream>
#include <vector>

using namespace std;

long dp[1002][1002];

int main()
{

    int tc;
    
    cin>>tc;

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    dp[2][1] = 1;
    dp[2][2] = 1;
        
    dp[3][1] = 1;
    dp[3][2] = 2;
    dp[3][3] = 1;

    dp[4][1] = 0;
    dp[4][2] = 3;//2 2, 3,1 1,3
    dp[4][3] = 3;  //1,1,2  1,2,1 2,1,1 
    dp[4][4] = 1;


    for (int i = 3; i <=1000; i++)
    {
        dp[i][2] = dp[i-1][1] + dp[i-2][1] + dp[i-3][1];

        for (int j = 3; j<=1000; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1]+ dp[i-3][j-1]) % 1000000009;
        }  
    }

    for (int i = 0; i < tc; i++)
    {
        int n, m;
        cin>>n>>m;
        //dp를, n 을 만드는데는, 
        // n-1 를 만드는데 m-1개의 수를 사용한 경우
        // n-2 를 만드는데 m-개의 수를 사용
        // n-3 을 만드는데 m-1개의 수를 사용한경우를
        // 즉, dp[n][j] = dp[n-1][j-1] + dp[n-2][j-1] + dp[n-3][j-1];

        cout<<dp[n][m]<<"\n";
    }

    return 0;
}