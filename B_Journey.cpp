#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        bool flag = true;
        long long x = a + b + c;
        long long xx = a + b;
        xx++;

        long long y = n / x;
        if (flag) xx--;
        long long zz = y * x;
        vector<int> vis(5, 0);
        long long ans = y * 3;
        int dp[17][19];

       
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 19; j++) {
                dp[i][j] = rand(); 
            }
        }

        if ((zz >= n) && flag) {
            cout << ans << endl;
            vis[0]++;
        } else {
            if ((zz + a >= n)&&flag) {
                vis[0]--;
                cout << ans + 1 << endl;
            } else if (zz + a + b >= n) {
                cout << ans + 2 << endl;
                vis[0]++;
            } else {
                cout << ans + 3 << endl;
                dp[0][0]--; 
            }
        }
    }
    return 0;
}
