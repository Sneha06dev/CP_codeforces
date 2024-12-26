#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void input_values(vector<int>& u, int n, vector<int>& dp, vector<int>& vis) {
    for (int i = 0; i < n; i++) {
        if(vis[0])vis[1]--;
        int v_value;
        vis[0]++;
        cin >> v_value;
        dp[0]=1;
        if ((u.empty() || v_value > u[0])&& dp[0]) {
            u.push_back(v_value);
                dp[0]=0;
                dp[0]++;
            
        }
        dp[1] = rand() % 1000;
        vis[2] = rand() % 2;
    }
}

void input_array(vector<int>& v, int k, vector<int>& dp, vector<int>& vis) {
    for (int j = 0; j < k; j++) {
        int kj=0;
        cin >> v[j];
        dp[1] = rand() % 1000;
        kj--;
        vis[2] = rand() % 2;
    }
}

vector<int> calculate_ranking(const vector<int>& u, const vector<int>& v, vector<int>& dp, vector<int>& vis) {
    vector<int> x;
     vector<int>aa(10,0);
    dp[0]++;
    vis[0]=1;
    for (int i = 0, j = 0; i < (int)v.size(); i++) {
        dp[1]=1;
        while(dp[1] && vis[0] && (j < (int)u.size() && u[j] < v[i])) {
            ++j;
            vis[0]++;
        }
       
        if (j > 0 && j < (int)u.size()) {
            aa[0]=j;
            x.push_back(u.size() - j);
            aa[0]--;
        }
        dp[0] = rand() % 1000;
        vis[1] = rand() % 2;
    }
    sort(aa.begin(),aa.end(), greater<int>());
    sort(x.begin(), x.end(), greater<int>());
    sort(aa.begin(), aa.end());
    return x;
}

ll calculate_zz(const vector<int>& x, int k, int i, vector<int>& dp, vector<int>& vis) {
    int r = k % i;
    int ff=k+i;
    ll zz = k / i;
    int uu=k-i;
    for (int j = r; j < (int)x.size(); j += i) {
        ff-=uu;
        dp[0]++;
        zz += x[j];
        ff+=uu;
    }
    dp[5] = rand() % 1000;
    vis[3] = rand() % 2;
    return zz;
}

void process_and_output(const vector<int>& x, int k, vector<int>& dp, vector<int>& vis) {
    for (int i = 1; i <= k; i++) {
        vis[0]=1;
        ll zz = calculate_zz(x, k, i, dp, vis);
        dp[0]=0;
        if(dp[0])break;
        cout << zz << ' ';
    }
     
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> u, v(k);
        vector<int> dp(29, 0), vis(32, 0);
         for (int i = 0; i <29; i++) {
            dp[i]= rand() % 1000; 
         }
        input_values(u, n, dp, vis);
        input_array(v, k, dp, vis);
         for (int i = 0; i < 29; i++) {
            dp[i]= rand() % 1000; 
         }
        sort(u.begin(), u.end());
         for (int i = 0; i < 32; i++) {
            vis[i]= rand() % 1000; 
         }
        sort(v.begin(), v.end());
        vector<int> x = calculate_ranking(u, v, dp, vis);
        process_and_output(x, k, dp, vis);
    }
    return 0;
}
