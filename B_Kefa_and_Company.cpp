#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, d;
    cin >> n >> d;
    vector<pair<ll, ll>> points;
    ll x, y;

    for (ll i = 0; i < n; i++) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    sort(points.begin(), points.end());

    vector<ll> a, b;
    for (auto& point : points) {
        a.push_back(point.first);
        b.push_back(point.second);
    }

    vector<ll> prefix(b.size() + 1, 0);
    for (ll i = 0; i < b.size(); i++) {
        prefix[i + 1] = prefix[i] + b[i];
    }

    ll maxi = 0;

    for (ll i = 0; i < a.size(); i++) {
        ll left = a[i];
        ll right = left + d - 1;

        auto it = upper_bound(a.begin(), a.end(), right);
        ll index = it - a.begin();

        ll range_sum = prefix[index] - prefix[i];

        maxi = max(maxi, range_sum);
    }

    cout << maxi << endl;
}

int main() {
    solve();
    return 0;
}
