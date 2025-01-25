#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        vector<long long> b(n);
        b[0] = a[0];
        for (long long i = 1; i < n; i++) {
            b[i] = a[i] + b[i - 1];
        }
        long long c=0;
        vector<long long> vis(n, 0);
        for (long long i = 0; i < n; i++) {
            if (a[i] == 0) vis[i] = 1;
            if(b[i]==0)c++;
        }
 
        vector<long long> total(n);
        total[0] = vis[0];
        for (long long i = 1; i < n; i++) {
            total[i] = vis[i] + total[i - 1];
        }
 
        long long k = 1;
        map<long long, long long> mp;
        long long ans = 0;
        long long cnt = 0;
 
        for (long long i = 0; i < n; i++) {
            if(total[i]==0 && b[i]==0)ans++;
            if (total[i] == k) {
                mp[b[i]]++;
            }
            if (total[i] > k) {
                for (auto& x : mp) {
                    cnt = max(cnt, x.second);
                }
                ans += cnt;
                cnt = 0;
                mp.clear();
                k = total[i];
                mp[b[i]]++;
            }
        }
 
        for (auto& x : mp) {
            cnt = max(cnt, x.second);
        }
        ans += cnt;
 
        cout << ans << endl;
    }
    return 0;
}