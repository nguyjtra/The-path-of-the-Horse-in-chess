#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[500][500];
int dx[8] = { -2, -2, -1, -1, +1, +1, +2, +2 };
int dy[8] = { -1, +1, -2, +2, -2, +2, -1, +1 };
void check(int s, int t, int n) {
    a[s][t] = 0;
    for (int i = 0; i < 8; i++) {
        int idx = s + dx[i];
        int idy = t + dy[i];
        if (idx >= 0 && idx < n && idy >= 0 && idy < n && a[idx][idy] == 1) {
            check(idx, idy, n);
        }
    }
}

int main() {
    int n; cin >> n;
    int s, t, u, v; cin >> s >> t >> u >> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    s--; t--; u--; v--;
    check(s, t, n);
    if (a[u][v] == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
