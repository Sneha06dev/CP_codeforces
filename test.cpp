#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned int ull;
typedef long double lld;
 
/---------------------------------------------------------------------------------------------------------------------------------------------/
#ifdef ONLINE_JUDGE
#define debug(x)
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#else
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#endif
#define int long long 
#define maxim(l) *max_element(l.begin(),l.end())
#define minim(l) *min_element(l.begin(),l.end())
#define sum(l) accumulate(l.begin(),l.end(),0ll)
#define vsort(l) sort(l.begin(),l.end())
#define revs(l) sort(l.rbegin(),l.rend())
#define pb push_back
#define mk make_pair
#define in(a) for(int i=0;i<a.size();i++) cin>>a[i];
#define out(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" "
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pll pair<ll, ll>
#define vp vector<pll>
#define INF 1e18
#define endl "\n"
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define yes cout<<"YES";
#define no cout<<"NO";
#define all(x) (x).begin(), (x).end()

 
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/---------------------------------------------------------------------------------------------------------------------------------------------/
 
 
  //find the smallest power of 2 greater than or equal to n
ll maxPow2(ll n) {if (n == 0) return 1;  n--; n |= n >> 1; n |= n >> 2;n |= n >> 4;n |= n >> 8;n |= n >> 16;n |= n >> 32;  return (n + 1);}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
int random(int s, int e){return s + rand() % (e - s + 1);}
 
 
//flip all bits of number n ex:101 to 010
int flip(int n){ for(int i=0;i<=31;i++){ int num = 1<<i; if(num > n) break; n = n xor num;} return n; }
 
ll power(ll x, ll y){if (y == 0) return 1;  if (x == 0) return 0;   ll res = 1; while (y > 0){ if (y & 1) res = (ll)(res*x); y = y>>1; x = (ll)(x*x); } return res; }
 
// Function to calculate x^y % p in O(log y)
ll binexp(ll x, ll y, ll p) {ll res = 1;x = x % p;while (y > 0) {if (y & 1) res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
 

const ll MOD = 1e9 + 7;

vector<vector<int>>dp;
ll cal(string& s,map<char,char>&m,int i,char prev){
    if(i>=s.size()) return 0;
    ll c1=INT_MAX,c2=INT_MAX;
    if(s[i]>=prev){
        if(dp[i][0]!=-1) c1=dp[i][0];
        else c1=dp[i][0]=cal(s,m,i+1,s[i]);
    }
    if(m[s[i]]>=prev){
        if(dp[i][1]!=-1) c2=dp[i][1];
        else c2=dp[i][1]=cal(s,m,i+1,m[s[i]])+1;
    }
    return min(c1,c2);
}

void solve() {
    ll n;
    string s, p;
    cin >> n;
    cin >> s >> p;

    dp.assign(n, vector<int>(2, -1));

    map<char, char> m;
    for (int i = 0; i < 26; i++) {
        m[p[i]] = p[25 - i];
    }
    ll val=cal(s, m, 0, 'a') ;
     if(val==INT_MAX) cout<<-1<<endl;
     else
    cout <<val << endl;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
  int t=1; 
  cin >> t;
  while(t--){
    solve();
  }
 return 0;
}