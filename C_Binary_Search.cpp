#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// Precompute factorials and modular inverses
vector<long long> fact, inv_fact;

// Modular exponentiation to compute base^exp % mod
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and modular inverses
void precompute_factorials(int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = mod_exp(fact[n], MOD - 2, MOD); // Fermat's Little Theorem
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

// Combination function: nCk = n! / (k! * (n-k)!)
long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void solve() {
    int n, x, pos;
    cin >> n >> x >> pos;

    // Determine the number of smaller and larger indices
    int smaller_count = 0, larger_count = 0;
    int low = 0, high = n;

    // Simulate binary search to count smaller and larger indices
    while (low < high) {
        int mid = (low + high) / 2;
        if (mid <= pos) {
            if (mid != pos) smaller_count++; // Smaller indices
            low = mid + 1;
        } else {
            larger_count++; // Larger indices
            high = mid;
        }
    }

    // Calculate the number of remaining numbers and their indices
    int smaller_numbers = x - 1;            // Numbers smaller than x
    int larger_numbers = n - x;            // Numbers larger than x
    int remaining_numbers = n - 1 - (smaller_count + larger_count);

    // Use combination formula to calculate valid permutations
    long long result = comb(smaller_numbers, smaller_count) * fact[smaller_count] % MOD;
    result = result * comb(larger_numbers, larger_count) % MOD * fact[larger_count] % MOD;
    result = result * fact[remaining_numbers] % MOD;

    cout << result << endl;
}

int main() {
    precompute_factorials(1000);
    solve();
    return 0;
}
