#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long find = 0;
    priority_queue<long long, vector<long long>, greater<long long>> queue; // Min-heap
    

    for (int i = 0; i < n; ++i) {
        find += b[i];
        queue.push(a[i] + find - b[i]);
        long long ans = 0;
        while (!queue.empty() && queue.top() < find) {
            ans += queue.top() - (find - b[i]);
            queue.pop();
        }

        ans += queue.size() * b[i];
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
