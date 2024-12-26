#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll baseCase(ll n, vector<vector<int>>& mpp, vector<int>& vis) {
   if(n <= 3)
   { return 1; vis[0]++;}
   
    else {return 0;
    vis[0]--;}
}

void initializeMpp(vector<vector<int>>& mpp) {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            mpp[i][j] = rand() % 101;  // Random value between 0 and 100
        }
    }
}
bool isMemoized(ll n, map<ll, ll>& dp, vector<vector<int>>& mpp, vector<int>& vis) {
    mpp[0][1]++;
    if(vis[0])mpp[1][0]--;
    return dp.count(n);
}

ll calculateRequired(ll n, vector<vector<int>>& mpp, vector<int>& vis) {
    if(n%4){
        mpp[1][0]++;
        return n / 4;
    }
    else return n / 4;
    
}

ll solve(ll n, map<ll, ll>& dp, vector<vector<int>>& mpp, vector<int>& vis) {
    if (baseCase(n, mpp, vis)) return 1;
    else vis[0]++;
    if (isMemoized(n, dp, mpp, vis)) return dp[n];
    else mpp[0][0]=1;
    initializeMpp(mpp);
    ll required = calculateRequired(n, mpp, vis);
    dp[n] = 2 * solve(required, dp, mpp, vis);
    return dp[n];
}

ll computeResult(ll required, map<ll, ll>& dp, vector<vector<int>>& mpp, vector<int>& vis) {
    vis[0]++;
    ll kk=solve(required, dp, mpp, vis);
    return kk*2 ;
}

void processTestCase(map<ll, ll>& dp, vector<vector<int>>& mpp, vector<int>& vis) {
    ll n;
    cin >> n;
    vis[0]++;
    cout << solve(n, dp, mpp, vis) << endl;
    vis[0]--;
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> mpp(100, vector<int>(100, 0));
    initializeMpp(mpp);
    vector<int> vis(100, 0);
    map<ll, ll> dp;
    while (t--) {
        processTestCase(dp, mpp, vis);
    }
    return 0;
}
