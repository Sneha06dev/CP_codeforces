#include <iostream>
#include <vector>
using namespace std;

void solve(int n) {
    vector<int> result(n);
    
    // First, fill in numbers such that the XOR of odd indices and even indices match
    for (int i = 0; i < n; i++) {
        result[i] = i; // Simple distinct numbers
    }
    
    // We will modify the array to make the XOR condition valid.
    int oddXOR = 0, evenXOR = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenXOR ^= result[i];
        } else {
            oddXOR ^= result[i];
        }
    }
    
    // If the XOR of even indices is not equal to the XOR of odd indices,
    // adjust the last element to make it balanced.
    if (oddXOR != evenXOR) {
        result[n - 1] ^= (oddXOR ^ evenXOR);
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
