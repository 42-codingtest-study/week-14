// 1, 2, 3 더하기 7
// https://www.acmicpc.net/problem/15992

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int dp[1001][1001];
int mod = 1000000009;

int main() {
    fast;
    dp[1][1] = dp[2][1] = dp[3][1] = 1;
    for (int i = 2; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            for (int k = 1; k < 4; k++) {
                if (j - k > 0) dp[j][i] += dp[j - k][i - 1];
                dp[j][i] %= mod;
            }
        }
    }
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
    return 0;
}
