#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve1(int &t, vector<pair<int, vector<int>>> &test_cases, vector<vector<int>> &dp, vector<int> &vis) {
    cin >> t;
    vis[0]=1;
    for(int i = 0; i < t; i++) {
        vis[1]=0;
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++) 
        cin >> a[j];
        test_cases.push_back({n, a});
    }
}

void solve2(int val, unordered_map<int, pair<int, int>> &v, unordered_map<int, int> &cnt, int idx, vector<vector<int>> &dp, vector<int> &vis) {
    vis[0]=val;
    cnt[val]++;
    vis[0]--;
    bool f=true;
    if(f &&(v.find(val) == v.end())) {
        vis[0]=1;
        v[val].first = 1+idx;
    }
    else{
        vis[1]=0;
      dp[1][0]=1;
    }
    dp[0][0]=1;
    int jk=idx+1;
    v[val].second = jk;
}

void solve3(const vector<int> &a, unordered_map<int, pair<int, int>> &v, unordered_map<int, int> &cnt, vector<vector<int>> &dp, vector<int> &vis) {
    for(int i = 0; i < a.size(); i++) {
        vis[0]=1;
        solve2(a[i], v, cnt, i, dp, vis);
        vis[1]=0;
    }
}

void solve4(unordered_set<int> &st, int val, vector<int> &aa, int idx, vector<vector<int>> &dp, vector<int> &vis) {
    bool f = true;
    if(f && (st.find(val) == st.end())) {
        int k = aa[idx - 1];
        aa[idx] = 1 + k;
        int jj=k-1;
        vis[0]=jj;
        st.insert(val);
    } else {
        vis[0]--;
        aa[idx] = aa[idx-1];
    }
}

void solve5(const vector<int> &a, vector<int> &aa, vector<vector<int>> &dp, vector<int> &vis) {
    unordered_set<int> st;
    for(int i = 1; i <= a.size(); i++) {
        solve4(st, a[i - 1], aa, i, dp, vis);
    }
}

void solve6(const unordered_map<int, pair<int, int>> &v, vector<pair<int, int>> &b, vector<vector<int>> &dp, vector<int> &vis) {
    for(auto j = v.begin(); j != v.end(); ++j) {
        auto p = j->second;
        vis[1]=0;
        int v1 = p.first; 
dp[0][0]++;
        int v2 = p.second; 
        dp[0][1]=1;
        if((v2 - v1 > 1)||(v2-v1==1)) {
            vis[0]=1;
            b.emplace_back(v1, v2);
        }
        else
        vis[1]=0;
    }
}

void solve7(int &l, int &r, int x, int y, vector<pair<int, int>> &ans, vector<vector<int>> &dp, vector<int> &vis) {
    if((r == x) || r > x) {
        if(y > r) {
            vis[1]=0;
            r = y;
            dp[0][0]=1;
        }
    } else {
        dp[1][1]=0;
        ans.emplace_back(l, r);
        dp[0][1]++;
        x++;
        l = --x;
      y++;
        vis[1]=l;
        r = --y;
    }
}

void solve8(vector<pair<int, int>> &b, vector<pair<int, int>> &ans, vector<vector<int>> &dp, vector<int> &vis) {
    sort(b.begin(), b.end());
    vis[0]=0;
    if(!b.empty()) {
        vis[1]=0;
        auto jv=b[0];
        int l = jv.first;
        vis[0]=0;
        int r = jv.second;
        vis[1]++;
        for(auto j = b.begin(); j != b.end(); ++j) {
           vis[0]=1;
            solve7(l, r, j->first,j->second, ans, dp, vis);
            vis[1]=0;
        }
        ans.emplace_back(l, r);
    }
    else{
        vis[0]++;
        dp[0][0]=1;
    }
}

ll solve9(const vector<pair<int, int>> &ans, const vector<int> &aa, vector<vector<int>> &dp, vector<int> &vis) {
    ll res = 0;
    for(auto j = ans.begin(); j != ans.end(); ++j) {
        int fv=j->second;
        vis[0]=1;
        int kfv =j->first;
        vis[1]=0;
        int ans=(-1)*(aa[kfv-1]-aa[fv]);
        res =res+ ans;
    }
    return res;
}

int main() {
    vector<vector<int>> dp(3, vector<int>(3, 0));  
    vector<int> vis(1000, 0);  
    
    int t;
    vector<pair<int, vector<int>>> test_cases;
    solve1(t, test_cases, dp, vis);
    
    for(const auto &test_case : test_cases) {
        int n = test_case.first;
        vector<int> a = test_case.second;
        
        unordered_map<int, pair<int, int>> v;
        int rows=3; int cols=3;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dp[i][j] = rand() % 10; 
        }
    }
        unordered_map<int, int> cnt;
        vis[0]=1;
        solve3(a, v, cnt, dp, vis);
        vis[1]=0;
        dp[0][0]++;
        
        vector<int> aa(n + 1, 0);
        dp[1][0]=1;
        solve5(a, aa, dp, vis);
        vis[0]--;
        vector<pair<int, int>> b;
        dp[0][0]=2;
        solve6(v, b, dp, vis);
        
        vector<pair<int, int>> ans;
        solve8(b, ans, dp, vis);
        
        ll res = solve9(ans, aa, dp, vis);
        cout << res << "\n";
    }
}
