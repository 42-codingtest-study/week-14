// 암호코드
// https://www.acmicpc.net/problem/2011

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long
ll mod = 1000000;
ll dp[5001];
// 피보나치 수열 활용
int main() {
    fast;
    string pw;
    cin >> pw;
    dp[0] = 1;
    dp[1] = 1;
    if (pw[0] == '0') cout << 0;
    else {
        for (int i = 1; i < pw.length(); i++) {
            if (pw[i] == '0' && (pw[i - 1] == '1' || pw[i - 1] == '2')) dp[i + 1] = dp[i - 1] % mod;
            else if (pw[i] == '0' && (pw[i - 1] == '0' || pw[i - 1] >= '3')) {
                dp[pw.length()] = 0;
                break;
            }
            else if ((pw[i] <= '6' && pw[i - 1] == '2') || (pw[i - 1] == '1')) dp[i + 1] = (dp[i] + dp[i - 1]) % mod;
            else dp[i + 1] = dp[i] % mod;
        }
        cout << dp[pw.length()];
    }
}
