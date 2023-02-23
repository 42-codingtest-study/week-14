// 출근 경로
// https://www.acmicpc.net/problem/5569

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int w, h;
ll map[101][101][2];
int dx[2] = {1, 0}, dy[2] = {0, 1};
int nx, ny;
void solve(int x, int y, int flag, int prev) {
    if (x == w && y == h) {
        return ;
    }
    // cout << x << " " << y << " " << flag << "\n";
    if (x == 0 && y == 0) {
        for (int i = 0; i < 2; i++) {
            nx = x + dx[i], ny = y + dy[i];
            map[nx][ny][0] += map[x][y][0];
            solve(nx, ny, 0, i);
        }
    } else {
        for (int i = 0; i < 2; i++) {
            nx = x + dx[i], ny = y + dy[i];
            if (nx <= w && ny <= h && flag == 0 && prev != i) {
                map[nx][ny][i] += map[x][y][flag];
                solve(nx, ny, i, i);
            } else if (nx <= w && ny <= h && flag == 0 && prev == i) {
                map[nx][ny][flag] += map[x][y][flag];
                solve(nx, ny, flag, i);
            } else if (nx <= w && ny <= h && flag == 1 && prev == i) {
                map[nx][ny][0] += map[x][y][flag];
                solve(nx, ny, 0, i);
            }
        }
    }
}

int main() {
    fast;
    cin >> w >> h;
    map[0][0][0] = 1;
    map[0][0][1] = 1;
    // map[0][0][2] = 1;
    solve(0, 0, 0, 0);
    // for (int i = 0; i < w; i++) {
    //     for (int j = 0; j < h; j++) {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << map[w - 1][h - 1][0] << " " << map[w - 1][h - 1][1];
}
