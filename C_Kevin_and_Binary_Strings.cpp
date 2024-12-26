#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        
   
        int x = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                x = i;
                break;
            }
        } 
        if (x == -1) {
            cout << 1 << " " << n << " " << n << " " << n << "\n";
        } else {
            cout << x << " " << n-1 << " " << 1<< " " << n << "\n";
        }
    }

    return 0;
}