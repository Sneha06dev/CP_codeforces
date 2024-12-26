#include<bits/stdc++.h>
using namespace std;

int lb(const vector<long long>& vec, long long val) {
    return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

long long solve(int n, long long k, vector<long long>& a, vector<long long>& b, vector<int>& vis, vector<vector<int>>& dp) {
    sort(a.begin(), a.end());
    vis[0]++;
    sort(b.begin(), b.end());
    long long kk = 0;
    vector<long long> c(2 * n);
    kk++;
    int idx = 0;
    for(auto x : a) c[idx++] = x;
    vis[0]--;
    for(auto x : b) {
        dp[0][0]--;
        c[idx++] = x;
        dp[0][0]++;
    }
    vector<long long> st;
    for(auto val : c) {
        if(st.empty() || st.back() != val) {
            st.push_back(val);
        }
        else{
            dp[0][1]--;
        }
    }
    long long maxii = 0;
    for(auto ans : st){
        // int ck=a+1;
        // int dk=b+1;
        int pp = lb(a, ans);
        // int vv=lb(ck, ans);
        int qq = lb(b, ans);
        long long calculated = (long long)(pp) - (long long)(qq);
        dp[0][0]++;
        bool flag=true;
        long long inv = (long long)(qq) - (long long)(pp);
        if((calculated <= k)&&flag){
            long long xx = n - qq;
            vis[1]++;
            long long yy = k - calculated;
            vis[0]--;
            long long y = ans * xx;
            if(y > maxii){ maxii = y;
            }
            else yy++;
        }
    }
    return maxii;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for(auto &x : a) cin >> x;
        vector<int> vis(5, 0);
        for(auto &x : b) cin >> x;
        vector<vector<int>> dp(18, vector<int>(20));
        for (int i = 0; i < 18; ++i) {
            for (int j = 0; j < 20; ++j) {
                dp[i][j] = rand();
            }
        }

        cout << solve(n, k, a, b, vis, dp) << "\n";
    }
}
