#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<pair<int, int>> segments(m);
        for (int i = 0; i < m; i++) {
            cin >> segments[i].first >> segments[i].second;
        }
        
        int q;
        cin >> q;
        vector<int> updates(q);
        for (int i = 0; i < q; i++) {
            cin >> updates[i];
        }
        
        vector<int> a(n, 0);  // Initializing the array a with 0's
        set<int> ones_set;  // To keep track of indices that are set to 1
        
        // For each segment, calculate how many ones are needed to make it beautiful
        vector<int> segment_needed(m);  // Store how many ones are needed for each segment to be beautiful
        for (int i = 0; i < m; i++) {
            int l = segments[i].first;
            int r = segments[i].second;
            segment_needed[i] = (r - l + 1) / 2 + 1;  // At least this many ones to be beautiful
        }
        
        // Process each update
        bool found = false;
        for (int i = 0; i < q; i++) {
            int x = updates[i] - 1;  // Convert 1-based index to 0-based
            a[x] = 1;
            ones_set.insert(x);  // Mark this index as set to 1
            
            // Check each segment to see if it becomes beautiful
            for (int j = 0; j < m; j++) {
                int l = segments[j].first - 1;
                int r = segments[j].second - 1;
                
                // Count the number of ones in the current segment
                int ones_count = 0;
                for (int k = l; k <= r; k++) {
                    if (ones_set.find(k) != ones_set.end()) {
                        ones_count++;
                    }
                }
                
                // If the number of ones is greater than half the length of the segment, it's beautiful
                if (ones_count >= segment_needed[j]) {
                    cout << i + 1 << endl;
                    found = true;
                    break;
                }
            }
            
            if (found) break;
        }
        
        // If no segment became beautiful, output -1
        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
