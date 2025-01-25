#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(vector<int>& a, int i, int y) {
    if (y <= a[i]) return 0;
    if (i == a.size() - 1) return LLONG_MAX;
    ll nextCost = f(a, i + 1, y - 1);
    if (nextCost == LLONG_MAX) return LLONG_MAX;
    return y - a[i] + nextCost;
}

bool canAchieveMax(vector<int>& a, int n, int k, int x) {
    for (int i = 0; i < n; i++) {
        if (f(a, i, x) <= k) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int low = *max_element(a.begin(), a.end());
        int high = low + k;
        int answer = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAchieveMax(a, n, k, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << high << endl;
    }

    return 0;
}
