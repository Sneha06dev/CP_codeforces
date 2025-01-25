#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    map<int, int> freqMap;
    multiset<int> freqSet;

    // Reading the array and populating the frequency map
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freqMap[a[i]]++;
    }

    // Initially populate the multiset with frequencies
    for (const auto& p : freqMap) {
        freqSet.insert(p.second);
    }

    int q;
    cin >> q;

    vector<char> sign(q);
    vector<int> d(q);

    // Reading the signs and the respective values
    for (int i = 0; i < q; ++i) {
        cin >> sign[i] >> d[i];
    }

    // Processing each query and checking conditions after updates
    for (int i = 0; i < q; ++i) {
        // Update the frequency map based on the operation
        if (sign[i] == '+') {
            // Remove the old frequency of d[i]
            if (freqMap[d[i]] > 0) {
                freqSet.erase(freqSet.find(freqMap[d[i]]));
            }
            freqMap[d[i]]++;
            freqSet.insert(freqMap[d[i]]);
        } else if (sign[i] == '-') {
            // Remove the old frequency of d[i]
            if (freqMap[d[i]] > 0) {
                freqSet.erase(freqSet.find(freqMap[d[i]]));
                freqMap[d[i]]--;
                if (freqMap[d[i]] > 0) {
                    freqSet.insert(freqMap[d[i]]);
                }
            }
        }

        // Get the top 3 frequencies directly from the multiset
        auto it = freqSet.rbegin();  // Reverse iterator for largest frequency
        int a = it != freqSet.rend() ? *it : 0;
        int b = (++it != freqSet.rend()) ? *it : 0;
        int c = (++it != freqSet.rend()) ? *it : 0;

        if (a >= 8)
            cout << "YES\n";
        else if (a >= 6 && b >= 2)
            cout << "YES\n";
        else if (a >= 4 && b >= 4)
            cout << "YES\n";
        else if (a >= 4 && b >= 2 && c >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
