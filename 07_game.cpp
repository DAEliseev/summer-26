#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int an = a / 2 + b / 2 + c / 2 + d / 2;
        if (a % 2 && b % 2 && c % 2) {
            ++an;
        }
        cout << an << '\n';
    }

    return 0;
}
