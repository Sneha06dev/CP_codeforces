#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void solve() {
    int q;
    cin >> q;

    unordered_set<long long> s; // To store the added elements
    unordered_map<long long, long long> mex_map; // To store the current k-mex for each k

    while (q--) {
        char query_type;
        cin >> query_type;

        if (query_type == '+') {
            // Add x to the set
            long long x;
            cin >> x;
            s.insert(x);
        } else if (query_type == '?') {
            // Find the k-mex
            long long k;
            cin >> k;

            // Start searching from the current k-mex or from 0 if not yet initialized
            if (mex_map.find(k) == mex_map.end()) {
                mex_map[k] = 0;
            }

            long long current_mex = mex_map[k];
            while (s.count(current_mex)) {
                current_mex += k; // Move to the next multiple of k
            }

            mex_map[k] = current_mex; // Update the k-mex for future queries
            cout << current_mex << endl; // Output the k-mex for this query
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
