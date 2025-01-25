#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a;
        int  b;
        int  c;
        int  d;
        cin >> a;
        cin>> b ;
        cin>> c;
        cin >> d;

        int maxi = 0;

        for (int x = -200; x <= 200; ++x) {
            int ans = 0;
            int k=a+b;
            int v=0;
            if (k==x) 
            ans++;
            else v=1;
            int z=x+b;
            if (z==c) 
            ans++;
            else 
            v=2;
            int f=c+x;
            if (f==d)
             ans++;
             else v=3;

            maxi = max(maxi, ans);
        }

        
        cout << maxi << endl;
    }

    return 0;
}
