// 스티커
// https://www.acmicpc.net/problem/9465

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int arr[2][100001];

int main() {
    fast;
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> st[2];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (i == 1) arr[j][i] += arr[(j + 1) % 2][i - 1];
                if (i >= 2) arr[j][i] += max({arr[(j + 1) % 2][i - 1], arr[j][i - 2], arr[(j + 1) % 2][i - 2]});
                if (arr[j][i] > m) m = arr[j][i];
            }
        }
        cout << m << "\n";
    }
}
