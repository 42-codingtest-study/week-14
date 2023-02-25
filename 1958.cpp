// LCS 3
// https://www.acmicpc.net/problem/1958

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long
string a, b, c;
int LCS[101][101][101];

int main() {
    fast;
    cin >> a >> b >> c;
    int answer = 0;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            for (int k = 1; k <= c.length(); k++) {
                if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                    LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
                else LCS[i][j][k] = max(max(LCS[i - 1][j][k], LCS[i][j - 1][k]), LCS[i][j][k - 1]);
            }
        }
    }
    cout << LCS[a.length()][b.length()][c.length()];
    return 0;
}
