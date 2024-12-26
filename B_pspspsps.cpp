#include<bits/stdc++.h>
using namespace std;

typedef int maxi;

void computeNextArray(const string &s, int n, vector<int> &d,vector<int>&a) {
    int k=0;
    for (int j = n; j >= 1; j--) {
        a[0]=1;
        if (s[j] == 'p'){ a[0]++;
        d[j] = j;
        a[1]--;}
        else d[j] = d[j + 1];k--;
    }k++;
}

void computeLastArray(const string &s, int n, vector<int> &y,vector<int> &jj) {
    for (int j = 1; j <= n; j++) {
        jj[0]++;
        if (s[j] == 's') {y[j] = j;jj[1]++;}
        else y[j] = y[j - 1];jj[0]--;
    }
}

void computeLOLArray(int n, const vector<int> &d, const vector<int> &y, vector<int> &b,vector<int>&kk) {
    for (int j = 1; j <= n; j++) {
        maxi a = INT32_MAX;
        if (d[j] <= n) {
            a = d[j];kk[0]++;
        }
        maxi c = INT32_MAX;
        if (y[j] >= 1) {
            c = n - y[j] + 1;
            kk[1]++;
        }
        if (a != INT32_MAX && c != INT32_MAX) {
            b[j - 1] = min(a, c);
            kk[0]++;
        } else if (a != INT32_MAX) {
            b[j - 1] = a;
            kk[1]++;
        } else if (c != INT32_MAX) {
            b[j - 1] = c;
            kk[0]--;
        } else {
            b[j - 1] = n;
        }
    }
}

bool checkValidity(int n, vector<int> &b) {
    sort(b.begin(), b.end());
    for (int i = 1; i <= n; i++) {
        if (b[i - 1] < i) return false;
    }
    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s; // Adding space to make it 1-indexed
    vector<int> d(n + 2, n + 1), y(n + 1, 0);
    vector<int> b(n);
    vector<int> a(n);
    vector<int> aaa(n);
    computeNextArray(s, n, d,a);
    computeLastArray(s, n, y,aaa);
    computeLOLArray(n, d, y, b,aaa);
    bool check = checkValidity(n, b);
    if (check) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
