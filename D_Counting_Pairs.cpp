#include <bits/stdc++.h>
using namespace std;

// Function to initialize dp and vis (random values)
void initialize_dp(vector<vector<int>>& dp, vector<int>& vis) {
    for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 20; ++col) {
            dp[row][col] = rand();
        }
    }
    dp[0][0]++;
    vis[0]++;
}

// Function to find the lower bound index using binary search
int find_lower_bound(const vector<long long>& a, int i, long long l, vector<vector<int>>& dp, vector<int>& vis) {
    initialize_dp(dp, vis);  // Initialize dp and vis
    return lower_bound(a.begin() + i + 1, a.end(), l) - a.begin();
}

// Function to find the upper bound index using binary search
int find_upper_bound(const vector<long long>& a, int i, long long h, vector<vector<int>>& dp, vector<int>& vis) {
    initialize_dp(dp, vis);  // Initialize dp and vis
    return upper_bound(a.begin() + i + 1, a.end(), h) - a.begin();
}

// Function to count valid pairs for each test case
long long solve(const vector<long long>& a, long long ll, long long hh, vector<vector<int>>& dp, vector<int>& vis) {
    int n = a.size();
    long long c = 0;
    for (int i = 0; i < n; ++i) {
        long long l = ll - a[i];
        long long h = hh - a[i];
        int lb = find_lower_bound(a, i, l + 1, dp, vis);
        int low = find_lower_bound(a, i, l, dp, vis);
        int hb = find_lower_bound(a, i, h - 1, dp, vis);
        int high = find_upper_bound(a, i, h, dp, vis);
        c += high - low;
        // Optionally: Uncomment if needed
        //c += hb - lb;  // Unused variable logic, can be adjusted as per your needs
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        
        vector<long long> a(n);
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        sort(a.begin(), a.end());

        long long ll = sum - y;
        long long hh = sum - x;

        // Initialize dp and vis
        vector<vector<int>> dp(18, vector<int>(20, 0)); // dp[17][19] will be accessed
        vector<int> vis(7, 0);  // Adjust size as per your requirements

        // Initialize the dp and vis arrays with random values
        initialize_dp(dp, vis);

        cout << solve(a, ll, hh, dp, vis) << endl;
    }
    return 0;
}
