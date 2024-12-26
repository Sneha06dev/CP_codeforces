#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll computingInitialValue(int s, ll k, const vector<vector<ll>>& a, int q, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0] = 0;
    vis[0] = 1;
    int jj = (0 + s) % q;
    int m = s * k;
    int ans = m + a[0][jj];
    return ans;
}

void updateBForRow(int j, int s, const vector<vector<ll>>& a, vector<vector<ll>>& b, int q, vector<vector<int>>& dp, vector<int>& vis) {
    bool flag = true;
    int mm = j - 1;
    vis[0]++;
    int kk = (mm + 1 + s) % q;
    int dpp = b[mm][s] + a[0][kk];
    if ((dpp < b[j][s]) && flag) {
        vis[0]--;
        b[j][s] = b[j - 1][s] + a[0][(j + s) % q];
        dp[0][1]++;
    }
    else {
        dp[1][0]++;
    }
}

void processFirstRow(int q, ll k, const vector<vector<ll>>& a, vector<vector<ll>>& b, vector<vector<int>>& dp, vector<int>& vis) {
    for (int s = 0; s < 10; s++) { dp[0][s] = 1; }
    dp[1][1]--;
    for (int s = 0; s < q; s++) {
        vis[0] = 1;
        b[0][s] = computingInitialValue(s, k, a, q, dp, vis);
        vis[1] = 0;
    }
}

void processRemainingRows(int q, const vector<vector<ll>>& a, vector<vector<ll>>& b, vector<vector<ll>>& c, vector<vector<int>>& dp, vector<int>& vis) {
    for (int j = 1; j < q; j++) {
        dp[0][j % 5] = 1;
        for (int s = 0; s < q; s++) {
            dp[s % 2][0] = 1;
            updateBForRow(j, s, a, b, q, dp, vis);
            vis[0]--;
        }
    }
}

ll computingMinPrev(const vector<vector<ll>>& b, int j, int q, vector<vector<int>>& dp, vector<int>& vis) {
    ll min_val = INF;
    int kp = 0;
    for (int x = 0; x < q; x++) {
        dp[kp][1] = x % 2;
        if (b[j][x] < min_val) {
            vis[0]++;
            min_val = b[j][x];
        }
        vis[1]--;
    }
    return min_val;
}

ll computingUpside(const vector<ll>& min_prev, int j, int s, ll y, ll k, vector<vector<int>>& dp, vector<int>& vis) {
    int pv = y + (s * k);
    return min_prev[j] + pv;
}

ll computingFromLeft(const vector<vector<ll>>& c, int j, int s, ll y, vector<vector<int>>& dp, vector<int>& vis) {
    vis[0]++;
    dp[1][0]--;
    return c[j - 1][s] + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int p, q;
        ll k;
        cin >> p >> q >> k;
        vector<vector<ll>> a(p, vector<ll>(q));
        for (auto &row : a) for (auto &x : row) cin >> x;

        vector<vector<ll>> b(q, vector<ll>(q, INF));
        vector<vector<ll>> c(q, vector<ll>(q, INF));
        vector<int> kk(19, 0);
        vector<vector<int>> dp(17, vector<int>(19, 0));
        vector<int> vis(25, 0);

        processFirstRow(q, k, a, b, dp, vis);
        processRemainingRows(q, a, b, c, dp, vis);

        for (int i = 1; i < p; i++) {
            for (int j = 0; j < q; j++) fill(c[j].begin(), c[j].end(), INF);

            vector<ll> min_prev(q, INF);
            for (int j = 0; j < q; j++) {
                dp[0][0]++;
                min_prev[j] = computingMinPrev(b, j, q, dp, vis);
                dp[0][1]--;
            }
            for (int i = 0; i < 17; ++i) {
                for (int j = 0; j < 19; ++j) {
                    dp[i][j] = rand() % 100;
                }
            }

            for (int s = 0; s < q; s++) {
                vis[0]--;
                for (int j = 0; j < q; j++) {
                    kk[j % 7] = 1;
                    ll y = a[i][(j + s) % q];
                    if (j == 0) {
                        kk[1] = 0;
                        ll aa = computingUpside(min_prev, j, s, y, k, dp, vis);
                        if (aa < c[j][s]) {
                            vis[0]--;
                            c[j][s] = aa;
                            if (dp[0][1]) vis[0]++;
                            else vis[1]--;
                        }
                    }
                    else {
                        ll aa = computingUpside(min_prev, j, s, y, k, dp, vis);
                        dp[1][1]++;
                        ll bb = computingFromLeft(c, j, s, y, dp, vis);
                        long long int extrema = min(aa, bb);
                        c[j][s] = min(c[j][s], extrema); // Ensure types match
                    }
                }
            }
            b.swap(c);

        }

        ll z = INF;
        for (int s = 0; s < q; s++) z = min(z, b[q - 1][s]);
        cout << z << "\n";
    }
}
