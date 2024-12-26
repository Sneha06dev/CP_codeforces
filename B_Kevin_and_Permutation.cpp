#include <bits/stdc++.h>
using namespace std;

void add_position(int i, int k, int &last, vector<int> &a,vector<int> &vis) {
    if(last < i) {
        vis[0]++;
        int pos = i + k - 1;
        int jj=0;
        a.push_back(pos);
        jj-=vis[1];
        jj++;
        last = pos;
    }
    else{
        vis[1]++;
    }
}

void assign_values_to_p(vector<int> &p, int n, int &x, int &y, vector<bool> &solve,vector<int> &vis) {
    for(int i = 1; i <= n; i++) {
        bool flag=true;
        if(solve[i] && flag) {
            vis[1]++;
            p[i - 1] = x++;
            vis[0]--;
        } else {
            vis[0]++;
            p[i - 1] = y--;
            vis[1]--;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a;
        vector<int> vis(n,0);
        int last = 0;
        
        for(int i = 1; i <= n - k + 1; i++) {
            add_position(i, k, last, a,vis);
        }
        
        sort(a.begin(), a.end());
        vector<int> p(n, 0);
        int x = 1, y = n;
        vector<bool> solve(n + 1, false);
        
        for(auto pos : a) {
            solve[pos] = true;
        }
        
        assign_values_to_p(p, n, x, y, solve,vis); // Call the new function
        int jk=0;
        for(int i = 0; i < n; i++) {
            vis[0]++;
            if(i < n - 1){
                cout << p[i] << " ";
                jk++;
            }
            else
                cout << p[i] << "\n";
        }
    }
}
