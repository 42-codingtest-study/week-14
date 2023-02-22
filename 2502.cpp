// 떡 먹는 호랑이
// https://www.acmicpc.net/problem/2502

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

vector<pair<int, int> > day;

int main() {
    fast;
    int D, K;
    cin >> D >> K;
    day.push_back(make_pair(1, 0));
    day.push_back(make_pair(0, 1));
    for (int i = 1; i <= D; i++) {
        day.push_back(make_pair(day[i - 1].first + day[i].first, day[i - 1].second + day[i].second));
    }
    int a = day[D - 1].first, b = day[D - 1].second;
    for (int i = 1; i < K; i++) {
        for (int j = i; j < K; j++) {
            if (a * i + b * j == K) {
                cout << i << "\n" << j;
                return 0;
            }
        }
    }
    return 0;
}
