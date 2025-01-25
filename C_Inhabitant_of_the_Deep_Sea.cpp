#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

using ll = signed long long int;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    deque<ll> dq(n);

    for (int i = 0; i < n; ++i) {
        cin >> dq[i];
    }

    while (dq.size() > 1 && k > 0) {
        ll mn = min(dq.front(), dq.back());

        if (k < 2 * mn) {
            dq.front() -= k / 2 + k % 2;
            dq.back() -= k / 2;
            k = 0;
        } else {
            dq.front() -= mn;
            dq.back() -= mn;
            k -= 2 * mn;
        }

        if (dq.front() == 0) {
            dq.pop_front();
        }

        if (dq.back() == 0) {
            dq.pop_back();
        }
    }

    int ans = n - dq.size();

    if (dq.size() && dq.front() <= k) {
        ans++;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
