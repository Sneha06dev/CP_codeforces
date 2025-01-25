#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int prev = INT_MIN;
    int l = 0, r = 0, c = 0, ans = 1;
   
    // if(a[1]<=a[0]){
    //     r=1;
    //     l=1;
    // }
    while (r < n - 1) {
     // cout<<r<<" "<<l<<" "<<prev<<endl;
        if (a[r] < a[r + 1]) {
            r++;
        } else if (c == 0 && a[r] >= a[r + 1]) {
            
            if (r<n-2&&((a[r]<a[r+2])||(a[r+1]<a[r+2]))) {
              //  cout << "YES"  << "\n";
                
                r+=2;
                c++;   
            }
            else{
                r++;
                l=r;
                
            }
            
        } else if (c == 1) {
            while (l < r && a[l] < a[l + 1]) {
                l++;
            }
            if (l < n - 1) {
                l++;
            }
            c = 0;
        }

        if (c) {
            ans = max(ans, r - l);
        } else {
            ans = max(ans, r - l + 1);
        }
    
    }

    cout << ans << endl;

    return 0;
}