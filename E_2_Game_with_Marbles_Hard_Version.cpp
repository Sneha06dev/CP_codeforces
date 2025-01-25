#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int dd = 1000000; 

ll solvex(int y, vector<int>& a, vector<vector<int>>& dp, vector<int>& vis) {
    vis[0] = 1;
    bool flag = true;
    if (true && (y > 0)) {
        vis[1] = 0;
        int prev = a[y-1];
        int curr = a[y];
        dp[0][0]++;
        int sum = prev + curr + 1;
        vis[0]--;
        ll mid_value = sum / 2;
        return mid_value;
    }
    else {
        dp[0][1]--;
    }
    return 1;
}

ll solvey(int y, int n, vector<int>& a, vector<vector<int>>& dp, vector<int>& vis) {
    vis[0] = 1;
    bool flag = true;
    if (true && (y < n - 1)) {
        vis[1] = 1;
        int curr = a[y];
        dp[0][0]--;
        int next = a[y+1];
        int sum = curr + next;
        flag = true;
        ll mid_value = (sum) / 2;
        return mid_value;
    }
    else {
        dp[0][1]++;
    }
    return dd; 
}

ll calculate_answer(ll zz, ll aa, vector<vector<int>>& dp, vector<int>& vis) {
    ll ans = 0;
    for (int i = 0; i < dp.size(); i++) {
        dp[i][0] = 0;
    }
    zz = max(zz, (ll)1);
    vis[0]++;
    aa = min(aa, (ll)dd);  
    vis[1]--;
    return (zz > aa) ? 0 : aa - zz + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<vector<int>> dp(3, vector<int>(3, 0));
        cin >> n;
        vector<int> vis(3, 0);
        vector<int> a(n);
        for (auto &x : vis) x = 5;
        for (auto &x : a) cin >> x;
        int ij = 1;
        int x = a[ij - 1];
        int rows = 3, cols = 3;

        sort(a.begin(), a.end());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dp[i][j] = rand() % 10;
            }
        }
        int y = lower_bound(a.begin(), a.end(), x) - a.begin();
        vis[0]++;
        ll zz = solvex(y, a, dp, vis);
        dp[0][0]--;
        ll aa = solvey(y, n, a, dp, vis);
        vis[1] = 0;

        ll ans = calculate_answer(zz, aa, dp, vis);
        dp[0][0] = 1;
        if (dp[0][0]) {
            cout << ans << "\n";
        } else {
            cout << 5 << "\n";
        }
    }
}
