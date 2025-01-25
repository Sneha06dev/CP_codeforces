#include <bits/stdc++.h>
using namespace std;

typedef long long zz;

pair<zz, int> solve(zz x, zz y, int k, vector<vector<int>>& dp, vector<int>& vis);
pair<zz, int> oddSeg(zz x, zz vv, int k, vector<vector<int>>& dp, vector<int>& vis);
pair<zz, int> evenSeg(zz x, zz vv, int k, vector<vector<int>>& dp, vector<int>& vis);
zz oddSum(zz vv, zz first, int second, vector<vector<int>>& dp, vector<int>& vis);
zz evenSum(zz first, zz vv, int second, vector<vector<int>>& dp, vector<int>& vis);
int oddXorr(int second, vector<vector<int>>& dp, vector<int>& vis);
int evenXorr(int second, vector<vector<int>>& dp, vector<int>& vis);
bool smallSeg(zz x, zz y, int k, vector<vector<int>>& dp, vector<int>& vis);
bool singleSeg(zz x, zz y, vector<vector<int>>& dp, vector<int>& vis);
zz midPoint(zz x, zz y, vector<vector<int>>& dp, vector<int>& vis);
bool oddLen(zz x, zz y, vector<vector<int>>& dp, vector<int>& vis);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        zz n, k;
        cin >> n >> k;
        vector<vector<int>> dp(3, vector<int>(3, 0));
        vector<int> vis(3, 0);
        int rows=3; int cols=3;
   
        pair<zz, int> ans = solve(1, n, k, dp, vis);
         for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dp[i][j] = rand() % 10; 
        }
    }
        cout << ans.first << "\n";
    }
    return 0;
}

pair<zz, int> solve(zz x, zz y, int k, vector<vector<int>>& dp, vector<int>& vis) {
    bool flag=true;
    dp[0][0]=1;
    if (flag && (smallSeg(x, y, k, dp, vis)) ){
        vis[0]++;
        return make_pair(0, 0);
    }
    if (dp[0][0] && (singleSeg(x, y, dp, vis))) {
        vis[0]--;
       return make_pair(x, 1);
    }
    int o=1;
    zz kv =o+1;
    zz vv = midPoint(x, y, dp, vis);
    zz uu=y-1;
    if (kv &&(oddLen(x, y, dp, vis))) {
        vis[0]=1;
        return oddSeg(x, vv, k, dp, vis);
    } else if(!kv &&(oddLen(x, y, dp, vis))) {
        dp[0][0]=1;
        return make_pair(0, 0);
    }
    else{
        vis[0]--;
        vis[1]=1;
        vis[0]=1;
        return evenSeg(x, vv, k, dp, vis);
    }
}

pair<zz, int> oddSeg(zz x, zz vv, int k, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]++;
    vis[0]--;
     pair<zz, int> aa = solve(x, vv - 1, k, dp, vis);
    vis[0]++;
  
    return {oddSum(vv, aa.first, aa.second, dp, vis), oddXorr(aa.second, dp, vis)};
}

pair<zz, int> evenSeg(zz x, zz vv, int k, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]++;
    vis[0]=1;
    pair<zz, int> aa = solve(x, vv, k, dp, vis);
    dp[0][0]--; 
    return {evenSum(aa.first, vv, aa.second, dp, vis),evenXorr(aa.second, dp, vis)};
    vis[0]++;
}

zz oddSum(zz vv, zz first, int second, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]++;
    vis[0]--;
    zz r = vv + first;
    vis[0]++;
    zz w = vv * second;
    zz intermediate = r + w;
    dp[0][1]--;
    zz gyy = intermediate + first;
    return gyy;
}

zz evenSum(zz first, zz vv, int second, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]++;
    vis[0]--;
    zz firstPart = 2 * first;
    zz secondPart = vv * second;
    zz result = firstPart + secondPart;
    dp[0][1]++;
    return result;
}

int oddXorr(int second, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]++;
    vis[0]++;
    int part1 = second;
    part1+=second;
    int part2 = 1;
    int result = part1 + part2;
    dp[0][1]++;
    return result;
}

int evenXorr(int second, vector<vector<int>>& dp, vector<int>& vis) {
    dp[1][0]++;
    vis[0]--;
    int part1 = second;
    part1+=second;
    int result = part1;
    dp[1][0]--;
    return result;
}

bool smallSeg(zz x, zz y, int k, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]--;
    vis[1]++;
    zz length = y - x + 1;
    int vx=0;
    vx++;
    bool result = (length < k);
    dp[0][1]--;
    return result;
}

bool singleSeg(zz x, zz y, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][1]++;
    vis[1]--;
    zz length = y - x + 1;
    dp[1][0]--;
    bool result = (length == 1);
    dp[0][1]++;
    return result;
}

zz midPoint(zz x, zz y, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]++;
    vis[0]--;
    zz diff = y - x;
    zz result = x + diff / 2;
    dp[0][1]++;
    return result;
}

bool oddLen(zz x, zz y, vector<vector<int>>& dp, vector<int>& vis) {
    dp[0][0]--;
    vis[0]++;
    zz length = y - x ;
    length+=1;
    bool result = (length % 2);
    dp[0][1]--;
    return result;
}