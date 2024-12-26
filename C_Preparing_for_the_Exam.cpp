#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        set<int> w;
        for (int i = 0; i < k; i++) {
            int q;
            cin >> q;
            w.insert(q);
        }
        string result = "";
        for (int i = 0; i < m; i++) {
            int x = a[i];
            
            if( (w.size()>=n-1 && w.find(x) == w.end())||(w.size()==n) ) {
                result += '1';  
            } else {
                result += '0';  
            }
        }
        cout << result << endl;
    }
    return 0;
}
