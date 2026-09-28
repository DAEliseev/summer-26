#include <bits/stdc++.h>

using namespace std;

struct St {
    int nx[26] = {};
    int lk = -1;
    int ln = 0;
    int ct = 0;
    int ps = -1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();
    vector<St> st(2 * n + 1);
    int sz = 1;
    int ls = 0;

    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        int u = sz++;
        st[u].ln = st[ls].ln + 1;
        st[u].ct = 1;
        st[u].ps = i;
        int p = ls;
        while (p != -1 && !st[p].nx[c]) {
            st[p].nx[c] = u;
            p = st[p].lk;
        }
        if (p == -1) {
            st[u].lk = 0;
        } else {
            int q = st[p].nx[c];
            if (st[p].ln + 1 == st[q].ln) {
                st[u].lk = q;
            } else {
                int v = sz++;
                st[v] = st[q];
                st[v].ln = st[p].ln + 1;
                st[v].ct = 0;
                while (p != -1 && st[p].nx[c] == q) {
                    st[p].nx[c] = v;
                    p = st[p].lk;
                }
                st[q].lk = v;
                st[u].lk = v;
            }
        }
        ls = u;
    }

    vector<int> cn(n + 1);
    vector<int> od(sz);
    for (int i = 0; i < sz; ++i) {
        ++cn[st[i].ln];
    }
    for (int i = 1; i <= n; ++i) {
        cn[i] += cn[i - 1];
    }
    for (int i = sz - 1; i >= 0; --i) {
        od[--cn[st[i].ln]] = i;
    }
    for (int i = sz - 1; i > 0; --i) {
        int u = od[i];
        st[st[u].lk].ct += st[u].ct;
    }

    long long bs = -1;
    int bi = 1;
    for (int i = 1; i < sz; ++i) {
        long long vl = 1LL * st[i].ln * st[i].ct;
        if (vl > bs) {
            bs = vl;
            bi = i;
        }
    }

    int ln = st[bi].ln;
    int ps = st[bi].ps;
    cout << s.substr(ps - ln + 1, ln) << '\n';

    return 0;
}
