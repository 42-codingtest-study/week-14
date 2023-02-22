// 공통 부분 문자열
// https://www.acmicpc.net/problem/5582

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int LCS[4001][4001];

int main() {
    fast;
    string str1, str2, tmp;
    cin >> str1 >> str2;
    int answer = 0;
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i - 1] == str2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            if (LCS[i][j] > answer) answer = LCS[i][j];
        }
    }
    cout << answer;
    return 0;
}
