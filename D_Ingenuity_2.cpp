#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int north = 0, south = 0, east = 0, west = 0;

        for (char c : s) {
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;
        }

        // Pair counts
        int nsPairs = min(north, south);
        int ewPairs = min(east, west);

        // Remaining moves
        int remNorth = north - nsPairs;
        int remSouth = south - nsPairs;
        int remEast = east - ewPairs;
        int remWest = west - ewPairs;
        int y = (remNorth + remSouth);
        int z = (remEast + remWest);

        // Check if it's possible
        if ((remNorth + remSouth) % 2 != 0 || (remEast + remWest) % 2 != 0) {
            cout << "NO" << endl;
        }
        else if(nsPairs+ewPairs<=1 && y==0 && z==0) {cout << "NO" << endl;}
        else{
        // Output the assignment
        string ans=s; // Default assignment
        int nc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'N' && nc < nsPairs) {
                ans[i] = (nc % 2 == 0) ? 'R' : 'H';
                nc++;
            }
        }
        
        int sc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'S' && sc < nsPairs) {
                ans[i] = (sc % 2 == 0) ? 'R' : 'H';
                sc++;
            }
        }

        int ec = 0; // To count occurrences of 'E'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'E' && ec < ewPairs) {
                ans[i] = (ec % 2 == 0) ? 'H' : 'R';
                ec++;
            }
        }       

        int wc = 0; // To count occurrences of 'W'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W' && wc < ewPairs) {
                ans[i] = (wc % 2 == 0) ? 'H' : 'R';
                wc++;
            }
        }

        // Assign remaining N/S moves
        int y1 = 0;
        for (int i = 0; i < n; i++) {
            if ((ans[i] == 'N' || ans[i] == 'S') && y1 < y) {
                ans[i] = (y1 % 2 == 0) ? 'R' : 'H';
                y1++;
            }
        }      

        // Assign remaining E/W moves
        int z1 = 0;
        for (int i = 0; i < n; i++) {
            if ((ans[i] == 'E' || ans[i] == 'W') && z1 < z) {
                ans[i] = (z1 % 2 == 0) ? 'R' : 'H';
                z1++;
            }
        }     

        cout << ans << endl;
    }
}
}

int main() {
    solve();
    return 0;
}
