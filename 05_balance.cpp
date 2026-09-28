#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> w(n);
    int s = 0;
    for (int &x : w) {
        cin >> x;
        s += x;
    }

    const int inf = 1000000000;
    vector<int> dp(s + 1, inf);
    dp[0] = 0;
    int sm = 0;
    int an = inf;

    for (int x : w) {
        vector<int> nd = dp;
        for (int d = 0; d <= sm; ++d) {
            if (dp[d] == inf) {
                continue;
            }
            int vl = dp[d] + 1;
            nd[d + x] = min(nd[d + x], vl);
            int y = abs(d - x);
            if (y == 0) {
                an = min(an, vl);
            } else {
                nd[y] = min(nd[y], vl);
            }
        }
        dp.swap(nd);
        sm += x;
    }

    cout << (an == inf ? -1 : an) << '\n';

    return 0;
}
