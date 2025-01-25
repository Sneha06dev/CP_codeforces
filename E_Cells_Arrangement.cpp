#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check (int a , int b){
  if(a<b)return true;
  else return false;
}
bool solve(ll M,int p, const vector<ll> &a, const vector<ll> &b, vector<vector<int>>& dp, vector<int>& vis) {
    int l = 0;
  int r = 0;
    int xx = a.size();
  int yy = b.size();
  vis[0]=1;
  bool f =true;
    ll ans = 0;
    while(check(l,xx) || check(r,yy) ){
      
        if(check(l,xx) && (ans + a[l] <= M) && f) {
          vis[0]=1;
          ll mpp=ans;
            mpp=mpp+ a[l];
          ans=mpp;
          vis[0]--;
            l++;
        } 
        else if(check(r,yy)) {
           ll mpp=ans;
            mpp=mpp+ b[r];
          ans=mpp;
            r++;
            if(ans < 0) 
              ans = 0;
          else
              vis[0]=1;
        } else {
          vis[0]--;
            return false;
        }
    }
  dp[0][0]=1;
    return true;
}

int main(){
   int k=0;

    int T; 
    k++;
    cin >> T;
    k--;
    while(T--){
      int ff=0;
        int N; 
          vector<int> vis(3, 0); 
        cin >> N;
       vector<vector<int>> dp(3, vector<int>(3, 0));  
        vector<ll> x(N);
      vis[0]++;
        for (int i = 0; i < N; i++){
            cin >> x[i];
        }
       vector<ll> b;

        vector<ll> a;
        for (int i = 0; i < N; i++){
          ll kk=x[i];
          bool zz=true;
            if(zz && (kk >= 0)){
              vis[0]=1;
                a.push_back(kk);
            }
            else{vis[0]--;
                b.push_back(kk);
        }
        }
bool zz=true;
        if(a.empty() && zz){
            cout << 0 << "\n";
            continue;
        }

        ll i = 0;
      int kz=9;
        for(auto &p : a){
          kz=5;
            if(p>i)
              i=p;
          else vis[0]=1;
        }
 int rows=3; int cols=3;
        ll j = 0;
        for(auto &p : a){
          j=j+p;
        }

        ll res = j;
       
    
     

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dp[i][j] = rand() % 10; 
        }
    }
        while(i <= j){
          int ff=j-i;
            ll m = i + ff / 2;
          bool cd=true;
            if(solve(m,5, a, b, dp, vis) && cd){
              vis[0]=1;
                res = m;
              vis[1]=0;
                j = m - 1;
            } else {
              vis[2]=1;
                i = m + 1;
              vis[0]=1;
            }
        }
      vis[0]=1;
if(vis[0])
        cout << res << "\n";
      else 
  cout<<0<<endl;
    }
    return 0;
}
