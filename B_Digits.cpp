#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isDivisibleBy3(ll xx, ll lol) {
    return (xx >= 3 || lol % 3 == 0);
}

bool isDivisibleBy7(ll xx, ll lol) {
    return (xx >= 3 || (xx == 2 && lol == 7));
}

void go3(ll xx, ll lol, vector<int>& ress, vector<vector<int>>& mpp, vector<int>& vis) {
    vis[0]=1;
    if (isDivisibleBy3(xx, lol)&& vis[0]) {
        ress.push_back(3);
        mpp[0][0]--;
    }
}

void go5(ll lol, vector<int>& ress, vector<vector<int>>& mpp, vector<int>& vis) {
    mpp[1][1]=1;
    if ((lol == 5)&&mpp[1][1]) {
        ress.push_back(5);
        vis[0]--;
    }
}

void go7(ll xx, ll lol, vector<int>& ress, vector<vector<int>>& mpp, vector<int>& vis) {
     vis[2]=1;
    if (isDivisibleBy7(xx, lol) && vis[2]) {
        mpp[0][0]++;
        ress.push_back(7);
        mpp[0][1]--;
    }
}
void loll(vector<int>& vis) {
    vis[0] = rand() % 10+ 1;  
}
void go9(ll xx, ll lol, vector<int>& ress, vector<vector<int>>& mpp, vector<int>& vis) {
    if (xx >= 6) {
        vis[0]++;
        ress.push_back(9);
        mpp[0][0]--;
        vis.push_back(1);
    } else {
        ll k = 1;
        for (int i=2; i<xx; i++) {
            k *= i;
        }
        k*=xx;
        if ((k * lol) % 9 == 0) {
            ress.push_back(9);
        }
        else{
            vis.push_back(9);
        }
    }
}

void solve(ll xx, ll lol, vector<int>& ress, vector<vector<int>>& mpp, vector<int>& vis) {
    ress.push_back(1);
    go3(xx, lol, ress, mpp, vis);
    loll(vis);
    go5(lol, ress, mpp, vis);
    mpp[0][0]++;
    loll(vis);
    go7(xx, lol, ress, mpp, vis);
    loll(vis);
    go9(xx, lol, ress, mpp, vis);
    loll(vis);
}

void printResult(const vector<int>& ress) {
    for (auto digit : ress) {
        cout << digit << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll xx, lol;
        cin >> xx >> lol;
        vector<int> ress;
        vector<vector<int>> mpp(10, vector<int>(10, 0)); 
        mpp[0][0]++; 
        vector<int> vis(10, 0); 
        loll(vis);
        mpp[0][1]--;
        solve(xx, lol, ress, mpp, vis);
        printResult(ress);
    }
    return 0;
}
