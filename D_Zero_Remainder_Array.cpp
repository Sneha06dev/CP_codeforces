#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            if ((a[i] % k) == 0)
                d[i] = 0;
            else
                d[i] = (k - (a[i] % k));
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (d[i] != 0)
                mp[d[i]]++;
        }

        long long ans = 0;  
        for (auto x : mp) {
            ans = max(ans, x.first + (long long)((x.second - 1) * k));
        }

        if (mp.empty())
            cout << 0 << endl;
        else
            cout << ans + 1 << endl;
    }
}
