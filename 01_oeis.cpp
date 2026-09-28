#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mx = 200000;
    vector<int> is(mx + 1, 1);
    vector<int> p;
    is[0] = is[1] = 0;
    for (int i = 2; i <= mx; ++i) {
        if (!is[i]) {
            continue;
        }
        p.push_back(i);
        if (1LL * i * i <= mx) {
            for (int j = i * i; j <= mx; j += i) {
                is[j] = 0;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        a[0] = p[0];
        for (int i = 1; i + 1 < n; ++i) {
            a[i] = 1LL * p[i - 1] * p[i];
        }
        a[n - 1] = p[n - 2];
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " \n"[i + 1 == n];
        }
    }

    return 0;
}
