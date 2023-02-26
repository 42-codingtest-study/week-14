// 삼각 그래프
// https://www.acmicpc.net/problem/4883

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int dp[100001][3];

int main() {
    fast;
    int cnt = 1;
    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        dp[0][0] = 987654321;
        dp[0][2] += dp[0][1];
        for (int i = 1; i < N; i++)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][0];
            dp[i][1] = min(min(dp[i - 1][0], dp[i][0]), min(dp[i - 1][1], dp[i - 1][2])) + dp[i][1];
            dp[i][2] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i][1])) + dp[i][2];
        }
        cout << cnt << ". " << dp[N - 1][1] << "\n";
        cnt++;
    }
}
