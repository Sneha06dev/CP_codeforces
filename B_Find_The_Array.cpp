#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 10000000;
const int MOD = 1000000007;

ll mod_multiply(ll a, ll b, ll mod) {
    return (a * b) % mod;
}

// Square a modulo mod
ll mod_square(ll a, ll mod) {
    return (a * a) % mod;
}
void mark_multiples(int prime, vector<int>& spf, int max_limit) {
    for(int j = prime * prime; j <= max_limit; j += prime) {
        if(spf[j] == 0) spf[j] = prime;
    }
}
// Perform fast exponentiation (a^b) % mod
ll binary_expo(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = mod_multiply(res, a, mod);
        a = mod_square(a, mod);
        b >>= 1;
    }
    return res;
}


vector<int> sieve_of_eratosthenes(int max_limit) {
    vector<int> spf(max_limit + 1, 0);
    for(int i = 2; i <= max_limit; i++) {
        if(spf[i] == 0) {
            spf[i] = i;
            mark_multiples(i, spf, max_limit);
        }
    }
    return spf;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    for(auto &x: A) cin >> x;

    vector<int> spf = sieve_of_eratosthenes(MAX); 

    // Collect primes up to M
    vector<int> primes;
    for(int i = 2; i <= M; i++) if(spf[i] == i) primes.push_back(i);
    int P = primes.size();

    // Map prime to index
    vector<int> prime_to_idx(MAX + 1, -1);
    for(int i = 0; i < P; i++) prime_to_idx[primes[i]] = i;

    // Compute exponents of primes in M!
    vector<ll> e_p(P, 0);
    for(int i = 0; i < P; i++){
        ll p = primes[i];
        ll temp = M;
        while(temp >= p){
            e_p[i] += temp / p;
            temp /= p;
        }
    }

    // Compute F(M!) and precompute inv(e_p + 1)
    ll F_M_fact = 1;
    vector<ll> inv_e_p_plus1(P, 1);
    for(int i = 0; i < P; i++){
        F_M_fact = F_M_fact * (e_p[i] + 1) % MOD;
        inv_e_p_plus1[i] = binary_expo(e_p[i] + 1, MOD - 2, MOD);
    }

    // Process each A_i
    vector<ll> results;
    results.reserve(N);
    for(int i = 0; i < N; i++){
        ll x = A[i];
        ll res = F_M_fact;
        
        // Factorize x
        vector<pair<int, int>> factors;
        while(x > 1){
            int p = spf[x];
            int cnt = 0;
            while(x % p == 0){
                cnt++;
                x /= p;
            }
            factors.emplace_back(p, cnt);
        }

        // Process factors
        for(auto it = factors.begin(); it != factors.end(); ++it){
            int p = it->first;
            int cnt = it->second;

            if(p <= M){
                int idx = prime_to_idx[p];
                res = res * (e_p[idx] + cnt + 1) % MOD;
                res = res * inv_e_p_plus1[idx] % MOD;
            }
            else{
                res = res * (cnt + 1) % MOD;
            }
        }

        results.push_back(res);
    }

    // Output the results
    for(int i = 0; i < N; i++) cout << results[i] << (i < N - 1 ? " " : "\n");
}
