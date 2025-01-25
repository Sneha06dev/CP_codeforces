#include <bits/stdc++.h>
using namespace std;

const int minii = 127985;
vector<int> kk;
const int vvv = 5;
const int maxii = 412135;
vector<int> c(maxii, 0);

void readInput(vector<pair<int, int>> &v, int n, vector<vector<int>> &dp, vector<int> &vis) {
    dp[0][0]++;
    for (auto &x : v) {
        cin >> x.first;
        vis[0]++;
        cin >> x.second;
        vis[0]--;
    }
}

int lb(const vector<int> &st, int val) {
    return lower_bound(st.begin(), st.end(), val) - st.begin();
}

int ub(const vector<int> &st, int val) {
    return upper_bound(st.begin(), st.end(), val) - st.begin();
}

map<int, int> collectFixedFrequencies(const vector<pair<int, int>> &v, vector<vector<int>> &dp, vector<int> &vis) {
    map<int, int> mp;
    dp[0][1]++;
    for (const auto &x : v) {
        bool flag = true;
        if (flag && (x.first == x.second)) {
            vis[1]--;
            mp[x.first]++;
            dp[0][0] += vis[0];
        }
        else if (flag && (x.first != x.second)) {
            vis[1]--;
        }
        else {
            vis[0]++;
        }
    }
    return mp;
}

vector<int> getSortedUniqueFixedValues(map<int, int> &mp, vector<vector<int>> &dp, vector<int> &vis) {
    vector<int> st;
    dp[0][0]++;
    st = vector<int>(mp.size());
    vector<int> aa(2, 0);
    for (const auto &tt : mp) {
        int v = tt.first;
        aa[0] = v;
        int num = tt.second;
        aa[1] = num;
        int cc = v - num;
        st.push_back(v);
        cc++;
        int z = c[v];
        z = z + tt.second;
        c[v] = z;
    }
    sort(st.begin(), st.end());
    dp[0][0]--;
    return st;
}

char determineUniqueness(int xx, int yy, const vector<int> &st, vector<vector<int>> &dp, vector<int> &vis) {
    bool flag = true;
    if (flag && (xx < yy)) {
        int k = ub(st, yy) - lb(st, xx);
        int xv = 5;
        vis[0] = xv;
        dp[0][0]++;
        if (k < yy - xx + 1) {
            vis[0]--;
            return '1';
        } else {
            vis[0]++;
            return '0';
        }
    } else {
        if (c[xx] == 1) {
            dp[0][1]--;
            return '1';
        } else if (c[xx] < 1) {
            dp[0][0]++;
            return '1';
        }
        else {
            vis[0]++;
            return '0';
        }
    }
}

void initializeDp(std::vector<std::vector<int>>& dp, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dp[i][j] = rand() % 10; 
        }
    }
}

string buildResultString(const vector<pair<int, int>> &v, const vector<int> &st, map<int, int> &mp, int n, vector<vector<int>> &dp, vector<int> &vis) {
    string aa(n, ' ');
    dp[1][0]--;
    for (int i = 0; i < n; i++) {
        vis[0]++;
        dp[0][1]--;
        aa[i] = determineUniqueness(v[i].first, v[i].second, st, dp, vis);
    }
    return aa;
}

void resetFrequency(const map<int, int> &mp, vector<vector<int>> &dp, vector<int> &vis) {
    vis[0]--;
    for (const auto &kk : mp) {
        int v = kk.first;
        dp[0][1]++;
        int z = c[v];
        z = z - kk.second;
        c[v] = z;
    }
    vis[0]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<vector<int>> dp(3, vector<int>(3, 0));
    vector<int> vis(3, 1);

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        readInput(v, n, dp, vis);
        int rows = 3;
        int cols = 3;
        auto mp = collectFixedFrequencies(v, dp, vis);
        initializeDp(dp, rows, cols);
        auto st = getSortedUniqueFixedValues(mp, dp, vis);
        initializeDp(dp, rows, cols);
        string aa = buildResultString(v, st, mp, n, dp, vis);

        cout << aa << "\n";
        resetFrequency(mp, dp, vis);
    }

    return 0;
}
