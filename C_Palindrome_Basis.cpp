#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

// Precomputed palindromic numbers
vector<int> palin;

// Memoization table
// dp[index][sum] represents the number of ways to form "sum" using palindromic numbers from index onward
long long dp[502][40004];

// Function to check if a number is a palindrome
bool isPalindrome(int n) {
    int rev = 0, orig = n;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev == orig;
}

// Recursive function with memoization
long long countWays(int index, int sum) {
    // Base cases
    if (sum == 0) return 1; // Valid way to form sum
    if (index == palin.size() || sum < 0) return 0; // No more palindromes or invalid sum

    // Check if already computed
    if (dp[index][sum] != -1) return dp[index][sum];

    // Recurrence relation: take or skip the current palindromic number
    long long take = countWays(index, sum - palin[index]) % MOD;
    long long skip = countWays(index + 1, sum) % MOD;

    // Store and return result
    return dp[index][sum] = (take + skip) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Generate all palindromic numbers up to 40000
    for (int i = 1; i <= 40000; i++) {
        if (isPalindrome(i)) palin.push_back(i);
    }

    // Initialize memoization table
    memset(dp, -1, sizeof(dp));

    // Read number of test cases
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Solve for each test case
        cout << countWays(0, n) << '\n';
    }

    return 0;
}
