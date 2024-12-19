#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> q(n), min_perm(n), max_perm(n);
    for (int i = 0; i < n; i++) cin >> q[i];

    set<int> s1;
    for (int i = 1; i <= n; i++) s1.insert(i);
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (q[i] != last) {
            min_perm[i] = q[i];
            s1.erase(q[i]);
            last = q[i];
        } else {
            min_perm[i] = *s1.begin();
            s1.erase(s1.begin());
        }
    }

    set<int> s2;
    for (int i = 1; i <= n; i++) s2.insert(i);
    last = 0;
    for (int i = 0; i < n; i++) {
        if (q[i] != last) {
            max_perm[i] = q[i];
            s2.erase(q[i]);
            last = q[i];
        } else {
            auto it = s2.lower_bound(q[i]);
            --it;
            max_perm[i] = *it;
            s2.erase(it);
        }
    }

    for (int i = 0; i < n; i++) cout << min_perm[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++) cout << max_perm[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
