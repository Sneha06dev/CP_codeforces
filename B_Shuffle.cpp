#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,m;
        cin>>n>>x>>m;
//         vector<pair<int,int>>v;
//         vector<int>vis;
//         vector<int>mark(n,0);
//         while(m--){
//             cin>>x;
//             cin>>y;
//             v.push_back({x,y});
//             if(x<=k && k<=y)vis.push_back(1);
//             else vis.push_back(0);
//         }
//         for(int i=0;i<m;i++){
//             auto x=v[i];
//             int a=x[0];
//             int b=x[1];
//             if(vis[i]==1)mark[]
//         }
//         #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     int t;
//     cin >> t; // Number of test cases

//     while (t--) {
//         long long n, x, m;
//         cin >> n >> x >> m;

        long long L = x, R = x; // Initially, active range is [x, x]

        for (int i = 0; i < m; i++) {
            long long l, r;
            cin >> l >> r;

            // Check if the current operation range overlaps with the active range
            if (r >= L && l <= R) {
                L = min(L, l);
                R = max(R, r);
            }
        }

        // The result is the size of the active range
        cout << R - L + 1 << endl;
    }

    return 0;
}
        
    