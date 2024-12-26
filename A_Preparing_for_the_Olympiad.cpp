#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int ans = a[n - 1];
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > b[i]) 
            ans += (a[i - 1] - b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
