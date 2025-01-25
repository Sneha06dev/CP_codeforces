#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        // Input health (a[i]) and explosion damage (b[i])
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }

        // Step 1: Calculate `a[i+1] - b[i]` for all monsters and find the maximum
        ll max_surplus = 0;
        int k = 0;

        for (int i = 0; i < n; ++i) {
            ll next_health = a[(i + 1) % n];
            ll explosion_damage = b[i];
            ll surplus = next_health - explosion_damage;

            if (surplus > max_surplus) {
                max_surplus = surplus;
               k = (i+1) % n; // Start from monster (i+1)
            }
        }
cout<<"start index" <<" "<<k<<endl;
        // Step 2: Calculate the minimum bullets needed, starting from the chosen monster
        ll sum = 0;
        int f;
        for (int i = 0; i < n; ++i) {
            f=0;
            int c = (k + i) % n;  // Traverse circularly
            int prev = (c == 0) ? n - 1 : c - 1;
            if(a[c]>b[prev])f=1;
            ll z = max(0LL, a[c] - b[prev]);
            if(f)z=a[c];
            
            cout<< z<<endl;
            sum += z;
        }

        // Output the result for this test case
        cout << sum << "\n";
    }

    return 0;
}
