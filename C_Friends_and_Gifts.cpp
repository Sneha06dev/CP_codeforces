#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    set<int> st;
    vector<int> b, c;

    for (int i = 1; i <= n; i++) st.insert(i);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) st.erase(a[i]);
        else c.push_back(i + 1);
    }

    for (auto x : st) b.push_back(x);

    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for (int i = 0; i < b.size(); i++) {
        if (b[i] == c[i]) {
            if (i + 1 < b.size()) swap(b[i], b[i + 1]);
            else swap(b[i], b[i - 1]);
        }
    }

    for (int i = 0; i < c.size(); i++) a[c[i] - 1] = b[i];

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
