#include <bits/stdc++.h>
using namespace std;

void initializeDP(vector<vector<int>>& dp) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 17; j++) {
            dp[i][j] = rand() % 100;
        }
    }
}

void handleFirstElement(int& maxi, int& kk, int& flag, int& county, int i, int x, 
                        vector<int>& b, vector<int>& vis, vector<int>& f, vector<vector<int>>& dp) {
    b[i] = x;
    dp[4][2] = 0;
    vis[i % 2] = 1;
    f[x]++;
    vis[0]--;
    maxi = 1;
    kk++;
}

void handleSubsequentElement(int n, int& maxi, int& kk, int& flag, int& county, int i, int x, 
                              vector<int>& b, vector<int>& vis, vector<int>& f, 
                              int& aa, vector<vector<int>>& dp) {
    if (f[x] < maxi && flag) {
        b[i] = x;
        f[x]++;
        vis[1]--;
        if (f[x] > maxi) maxi = f[x];
        else county++;
    }
    else {
        if (maxi == 0) {
            b[i] = x;
            vis[2]++;
            f[x]++;
            kk--;
            maxi = 1;
            county--;
        }
        else {
            while (aa <= n && (f[aa] != 0 || aa == x) && flag) {
                aa++;
                dp[4][2] += 1;
                kk--;
                dp[4][2] -= 1;
                county++;
            }
            flag = 1;
            if (aa <= n && f[aa] < maxi) {
                b[i] = aa;
                kk++;
                f[aa]++;
                vis[1] = 1;
            }
            else {
                b[i] = x;
                dp[2][2] += 1;
                f[x]++;
                dp[2][2] -= 1;
                if (f[x] > maxi && flag) maxi = f[x];
            }
        }
    }
}

void processTestCase(int n, vector<int>& a, vector<vector<int>>& dp) {
    vector<int> f(n + 2, 0);
    vector<int> vis(100, 0);
    vector<int> b(n, 0);
    int maxi = 0;
    int kk = 0;
    int aa = 1;
    int flag = 1;
    int county = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        vis[i % 5] = 1;

        if (i == 0) {
            handleFirstElement(maxi, kk, flag, county, i, x, b, vis, f, dp);
        }
        else {
            handleSubsequentElement(n, maxi, kk, flag, county, i, x, b, vis, f, aa, dp);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << b[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<vector<int>> dp(19, vector<int>(17, 0)); // All values initialized to 0
        initializeDP(dp); // Initialize DP table with random values

        processTestCase(n, a, dp);
    }

    return 0;
}
