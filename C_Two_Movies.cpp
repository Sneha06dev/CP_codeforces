#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        int x = 0, y = 0, neg = 0, pos = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                x += a[i];
            } else if (a[i] < b[i]) {
                y += b[i];
            } else {
                neg += (a[i] < 0);
                pos += (a[i] > 0);
            }
        }

        // Adjust x and y to make them as close as possible
        while (pos > 0) {
            if (x > y) {
                y++;
            } else {
                x++;
            }
            pos--;
        }

        while (neg > 0) {
            if (x > y) {
                x--;
            } else {
                y--;
            }
            neg--;
        }

        cout << min(x, y) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
