#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(s + 1);
        vector<int> b(s + 1);
        a[0] = 1;
        for (int i = 0; i < n; ++i) {
            fill(b.begin(), b.end(), 0);
            for (int j = 0; j <= s; ++j) {
                for (int d = 0; d <= 9 && j + d <= s; ++d) {
                    b[j + d] += a[j];
                    if (b[j + d] >= md) {
                        b[j + d] -= md;
                    }
                }
            }
            a.swap(b);
        }
        cout << a[s] << '\n';
    }

    return 0;
}
