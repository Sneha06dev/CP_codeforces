#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to compute the gcd
long long gcd(long long x, long long y) {
    while (y) {
        long long temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

void solve() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        long long l, r, G;
        cin >> l >> r >> G;  // Input l, r, and G
        
        // Step 1: Find the possible values for a and b
        long long start = (l + G - 1) / G;  // Smallest multiple of G greater than or equal to l
        long long end = r / G;  // Largest multiple of G less than or equal to r
        
        if (start > end) {
            cout << "-1 -1" << endl;
            continue;
        }
        
        // Step 2: Try to maximize the difference |A - B|
        long long A = -1, B = -1;
        bool found = false;
        
        for (long long b = end; b >= start; --b) {
            for (long long a = start; a <= b; ++a) {
                if (gcd(a, b) == 1) {
                    A = G * a;
                    B = G * b;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        if (A == -1) {
            cout << "-1 -1" << endl;
        } else {
            cout << A << " " << B << endl;
        }
    }
}

int main() {
    solve();  // Run the solution
    return 0;
}
