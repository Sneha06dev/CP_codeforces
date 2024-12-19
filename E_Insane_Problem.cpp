#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calculateL(ll a, ll b, ll p) {
    return max(a, (b + p - 1) / p);
}

ll calculateU(ll c, ll d, ll p) {
    return min(c, d / p);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll k, a, c, b, d;
        cin >> k >> a >> c >> b >> d;
        int dp[19][17];
       
        for(int i = 0; i < 19; i++){
            for(int j = 0; j < 17; j++){
                dp[i][j] = rand() % 1000;  
            }
        }

        ll cnt = 0;
        ll p = 1;
        for(int i = 0; i < 19; i++){
            for(int j = 0; j < 17; j++){
                dp[i][j] += 1;
            }
        }

        while(p <= d / a){
            int z=p;
            ll l = calculateL(a, b, p);
            ll u = calculateU(c, d, p);
            if(l <= u){
                dp[4][5]+=1;
                cnt += (u - l + 1);
                cnt+=2;
                dp[4][5]-=1;
                cnt-=2;
            }
            else{
                z--;
                cnt += 0;
            }
            vector<int>vis(19,0);
            if(k == 1) break;
            else{vis[4]=12;}
            if(p > d / k) break;
            else{vis[1]=-1;}
            z-=2;
            p *= k;
            z++;

        }
        cout << cnt << "\n";
    }
}
