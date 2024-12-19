#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long>& aa, long long k) {
    vector<long long> a;
    long long n = aa.size();

    // Push elements with values from k+1 to n-k into the vector 'a'
    for (long long i = 0; i < n; i++) {
        if (aa[i] >= k + 1 && aa[i] <= n - k) {
            a.push_back(aa[i]);
        }
    }

   

    if(a.empty())return true;
    else{
    // Check if the remaining array is sorted
    for (long long i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;  // If any element is greater than the next, return false
        }
    }
 }
    return true;  // Return true if the array is sorted
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n); // Use vector instead of C-style array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long l = 0;
        long long h = n / 2; // Set high value
        long long mid = l + (h - l) / 2;
        long long ans = h;
        while (l <= h) {
            if (check(a, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
            mid = l + (h - l) / 2;  // Update mid value inside the loop
        }

        cout << ans << endl;  // Final result
    }
}
