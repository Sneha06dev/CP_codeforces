#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        map<long long, long long> index_map;
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            index_map[a[i]] = i;
        }
        long long k = 1;
        bool flag = false;
        vector<long long> vis(n, 0);
        while (k <= n) {
            if (index_map.find(k) == index_map.end()) {
                flag = true;
                break;
            }
            long long j = index_map[k];
            while (j < n && !vis[j]) {
                if (a[j] == k) {
                    vis[j] = 1;
                    k++;
                    j++;
                } else {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
