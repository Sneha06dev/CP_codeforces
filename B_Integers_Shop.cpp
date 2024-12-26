#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<tuple<int, int, int>> segments(n);
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            segments[i] = {x, y, z};
        }

        // Map to store the minimum cost for each (x, y)
        map<pair<int, int>, int> mp;
        int mini = INT_MAX, maxi = INT_MIN;
        int minZ = INT_MAX, maxZ = INT_MAX;
        int j=0;
        while(j<n){
        
            int x = get<0>(segments[j]);
            int y = get<1>(segments[j]);
            int z = get<2>(segments[j]);

            // Update the map with the current segment
            if (mp.find({x, y}) == mp.end()) {
                mp[{x, y}] = z;
            } else {
                mp[{x, y}] = min(mp[{x, y}], z);
            }

            // Dynamically update `mini`, `maxi`, `minZ`, `maxZ`
            if (x < mini) {
                mini = x;
                minZ = z; // Reset minZ when mini changes
            } else if (x == mini) {
                minZ = min(minZ, z); // Update minZ for the same mini
            }

            if (y > maxi) {
                maxi = y;
                maxZ = z; // Reset maxZ when maxi changes
            } else if (y == maxi) {
                maxZ = min(maxZ, z); // Update maxZ for the same maxi
            }

            // Compute the answer using the current state of `mini`, `maxi`, `minZ`, `maxZ`
            int ans = minZ + maxZ;
            if (mp.find({mini, maxi}) != mp.end()) {
                ans = min(ans, mp[{mini, maxi}]);
            }

            // Output the result for the current segment
            cout << ans << endl;
            j++;
        }
    }
    return 0;
}
