#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int r1 = min(a, m);
        int r2 = min(b, m);
        a -= r1;
        b -= r2;
        int leftover = 2 * m - r1 - r2;
        int canbe = min(c, leftover);
        cout << r1 + r2 + canbe << endl;
    }
    return 0;
}
