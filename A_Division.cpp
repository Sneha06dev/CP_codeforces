#include <bits/stdc++.h>
using namespace std;

void prime(int n,map<int, int>&mp;) {
    while (n % 2 == 0) {
        mp[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        mp[n]++;
    }
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >>a>>b;
        map<int, int>mpa;
        map<int, int>mpb;
        prime(a,mpa);
        prime(b,mpb);
        for(auto& x:mpa){
            x.first
        }
        

       
    }

    return 0;
}
