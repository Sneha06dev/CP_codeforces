#include <bits/stdc++.h>
using namespace std;

string bestAns;
int minDiff = INT_MAX;

void solve(vector<int>& a, int x, int y, int i, string ans) {
    if (i >= a.size()) {
        if (abs(x - y) < minDiff) {
            minDiff = abs(x - y);
            bestAns = ans;
        }
        return;
    }

    solve(a, x + a[i], y, i + 1, ans + 'A');
    solve(a, x, y + 1000-a[i], i + 1, ans + 'G');
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cin >> b[i];
    }

    string ans="";
    solve(a, 0, 0, 0, ans);

    cout << bestAns << endl;

    return 0;
}
