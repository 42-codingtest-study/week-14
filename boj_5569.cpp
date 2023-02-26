#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int dp[102][102][4];

int main()
{
    int r, c;

    cin>>c>>r;
    
    //[3][4] 에 도달하는 방법은 [3][3] 에서 , [2][4] 에서 두가지가 있는데, 
    //이 [3][3] 이 [3][2] 에서 온 경우는 가능하고, [2][3] 에서 온 경우는 안됨
    // 마찬가지로 [2][4] 는 [1][4] 는 가능하고 [2][3] 은 안된다.

// 4가지 경우를 다 이용해보자.
    // 아래 - 아래
    // 오른 - 아래
    // 오른 - 오른
    // 아래 - 오른

    int mod = 100000;
    for (int i = 1; i <= r; i++)
    {
        dp[i][1][0] = 1;
    }
    for (int i = 1; i <= c; i++)
    {
        dp[1][i][2] = 1;
    }
    for (int i = 2; i<= r; i++)
    {
        for (int j = 2; j <= c; j++)
        {
            dp[i][j][0] = (dp[i-1][j][1] + dp[i-1][j][0]) % mod;
            dp[i][j][1] = dp[i-1][j][2];

            dp[i][j][2] = (dp[i][j-1][3] + dp[i][j-1][2]) % mod;
            dp[i][j][3] = dp[i][j-1][0];
        }
        
    }
    int ans = 0;
    for (int k = 0; k < 4; k++)
    {
        ans += dp[r][c][k];
    }
    cout<<ans % mod;

    return 0;
}