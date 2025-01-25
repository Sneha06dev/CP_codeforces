#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve1(vector<ll>& a, int n, vector<int>& vis) {
    bool f =true;
    for(int i=0; i<n-1; i++) {
        if((a[i] <= a[i+1] )&& f) {
            vis[0]=1;
            ll x = a[i];
            vis[1]=1;
            ll y = a[i+1];
            a[i] = 0;
            y =y- x;
            a[i+1]=y;
        }
        vis[1]=0;
    }
}

bool solve2(const vector<ll>& a, int n, vector<int>& vis) {
    bool k=true;
    for(int i=0; i<n-1; i++) {
        if((a[i] > a[i+1])&&k) {
            vis[0]=0;
            return false;
        }
        else 
        vis[0]=1;
    }
    return true;
}

void solve3(vector<int>& vis) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    solve1(a, n, vis);
    if(solve2(a, n, vis)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    vector<int> vis(3); 
    while(t--) {
        solve3(vis);
    }
}
