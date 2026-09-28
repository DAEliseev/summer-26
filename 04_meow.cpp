#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll md = 1000000007;

ll pw(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) {
            r = r * a % md;
        }
        a = a * a % md;
        b >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> f(n + 1);
        vector<ll> g(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i % md;
        }
        g[n] = pw(f[n], md - 2);
        for (int i = n; i > 0; --i) {
            g[i - 1] = g[i] * i % md;
        }
        auto cb = [&](int a, int b) -> ll {
            if (b < 0 || b > a) {
                return 0;
            }
            return f[a] * g[b] % md * g[a - b] % md;
        };

        ll an = 0;
        for (int x = 1; x <= n; ++x) {
            for (int m = 0; m < x; ++m) {
                int r = 2 * m - x + 1;
                if (r < 0 || r > n - x) {
                    continue;
                }
                ll z = cb(x - 1, m) * cb(n - x, r) % md;
                an = (an + z * x) % md;
            }
        }
        for (int m = 0; m <= n; ++m) {
            int x = 2 * m + 1;
            if (x > n) {
                an = (an + cb(n, m) * x) % md;
            }
        }
        cout << an << '\n';
    }

    return 0;
}
