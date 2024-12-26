#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

void processTestCase() {
    ll n, operations = 0; 
    cin >> n;
    string s; 
    cin >> s;

    if (is_sorted(all(s))) {
        cout << 0 << endl;
        return;
    }

    map<char, ll> charCount;
    set<char> uniqueChars;

    for (ll i = 0; i < n; i++) {
        charCount[s[i]]++;
        uniqueChars.insert(s[i]);
    }

    vector<ll> subsequenceIndices;
    string largestSubsequence = "";

    for (ll i = 0; i < n; i++) {
        if (s[i] == *(--uniqueChars.end())) {
            subsequenceIndices.pb(i); 
            largestSubsequence += s[i];
        }
        charCount[s[i]]--;
        if (charCount[s[i]] == 0) uniqueChars.erase(s[i]);
    }

    ll prefixCount = 1;
    for (ll i = 1; i < largestSubsequence.size(); i++) {
        if (largestSubsequence[i] == largestSubsequence[0]) prefixCount++;
        else break;
    }

    sort(all(largestSubsequence));
    operations = largestSubsequence.size();

    for (ll i = 0; i < subsequenceIndices.size(); i++) {
        s[subsequenceIndices[i]] = largestSubsequence[i];
    }

    if (is_sorted(all(s))) {
        cout << operations - prefixCount << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll testCases;
    cin >> testCases;

    while (testCases--) {
        processTestCase();
    }

    return 0;
}
