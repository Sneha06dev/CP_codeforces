#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n, vector<vector<char>> &graph) {
    vector<ll> a(n + 1, 0);

    // Calculate in-degrees
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (graph[i - 1][j - 1] == '1') {
                a[j]++;
            }
        }
    }

    vector<pair<ll, int>> nodes;

    // Create pairs of (in-degree, index)
    for (int i = 1; i <= n; i++) {
        nodes.push_back({a[i], i});
    }

    // Sort nodes by in-degree (desc) and index (asc)
    sort(nodes.rbegin(), nodes.rend(), [](const pair<ll, int> &a, const pair<ll, int> &b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    vector<int> ans(n); // Resultant permutation

   
    for (int i = 0; i < n; i++) {
        ans[n - i - 1] = nodes[i].second;
    }

        reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<char>> graph(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        solve(n, graph);
    }

    return 0;
}
