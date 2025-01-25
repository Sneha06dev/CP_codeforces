#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll solve(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

class Solution {
public:
    int countGoodArrays(int a, int b, int j) {
        if(j > a-1) return 0;
        vector<ll> ans(a, 1);
        for(int i = 1; i < a; i++) ans[i] = ans[i-1] * i % MOD;
        vector<ll> mp(a, 1);
        mp[a-1] = solve(ans[a-1], MOD-2);
        for(int i = a-2; i >= 0; i--) mp[i] = mp[i+1] * (i+1) % MOD;
        ll vv = ans[a-1] * mp[j] % MOD * mp[a-1-j] % MOD;
        ll res = solve(b-1, a-1-j);
        return vv * b % MOD * res % MOD;
    }
};
