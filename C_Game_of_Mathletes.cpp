#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve1(vector<int>& a, int n, vector<int>& vis) {
    bool f =true;
    for(int i = 0; i < n; i++) {
        int k;
      int p=1;
        cin >> k;
        p=0;
        if(k<=n && f) {
            a[k]++;
        }
        else
        vis[0]=1;
    }
    vis[1]=1;
}

ll solve2(int i, ll res, vector<int>& a, vector<int>& vis) {
    ll ans = 0;
    ll kk=vis[0];
    ll y = (-1)*(i-res);
    kk++;
    int np=a.size();
    if(1>y || y > np-1) 
    return ans;
    bool fp=true;
    if(res%2==1)
    fp=false;
    bool z=true;
    if(i < y && z) {
        ll f=(ll)a[i];
        ans = min(f, (ll)a[y]);
        ans = min((ll)a[i], (ll)a[y]);
    } else if(i == y && fp) {
        ans = ((ll)a[i]) / 2;
    }
    return ans;
}

ll solve3(int n, ll res, vector<int>& a, vector<int>& vis) {
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += solve2(i, res, a, vis);
    }
    return ans;
}

void solve4(vector<int>& vis) {
    int n;
    int kk=0;
    ll res;
    cin >> n ;
    kk++;
    cin >> res;
    vector<int> a(n+1, 0);
    solve1(a, n, vis);
    ll ans = solve3(n, res, a, vis);
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<int> vis(3, 0);  
        solve4(vis);
    }
}
