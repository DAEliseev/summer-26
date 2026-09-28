#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }

    int z = 1 << n;
    const int inf = 1000000000;
    vector<int> dp(z * n, inf);
    dp[n] = 0;

    for (int m = 1; m < z; ++m) {
        if (!(m & 1)) {
            continue;
        }
        for (int v = 0; v < n; ++v) {
            if (!(m >> v & 1)) {
                continue;
            }
            int vl = dp[m * n + v];
            if (vl == inf) {
                continue;
            }
            for (int u = 0; u < n; ++u) {
                if (m >> u & 1) {
                    continue;
                }
                int nm = m | 1 << u;
                int &to = dp[nm * n + u];
                to = min(to, vl + c[v][u]);
            }
        }
    }

    int an = inf;
    for (int v = 0; v < n; ++v) {
        an = min(an, dp[(z - 1) * n + v] + c[v][0]);
    }
    cout << an << '\n';

    return 0;
}
