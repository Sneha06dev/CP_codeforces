#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    
    vector<ll> heights(w);
    for (int i = 0; i < w; i++) {
        cin >> heights[i];
    }
    
    // Sort gorilla heights in descending order
    sort(heights.rbegin(), heights.rend());
    
    // Create and fill 2D array 'a' for coverage using your logic
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int l = min(1, i - k + 1);
            int r = min(n - i, k);
            int u = min(1, j - k + 1);
            int d = min(m - j, k);
            a[i][j] = (l+r- 1) * ( u+d- 1); // Fill cell based on your logic
        }
    }
    
    // Flatten the 2D array `a` into a 1D array and sort in descending order
    vector<int> coverage;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            coverage.push_back(a[i][j]);
        }
    }
    sort(coverage.rbegin(), coverage.rend());
    
    // Calculate maximum spectacle
    ll max_spectacle = 0;
    for (int i = 0; i < min(w, (int)coverage.size()); i++) {
        max_spectacle += (ll)coverage[i] * heights[i];
    }
    
    cout << max_spectacle << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
