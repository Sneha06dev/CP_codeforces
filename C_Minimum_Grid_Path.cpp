#include <bits/stdc++.h>
using namespace std;

void reverse_substring(string& c, int a, int r) {
    reverse(c.begin() + a, c.begin() + r + 1);
}

bool is_equal(const string& c, const string& t) {
    return c == t;
}

bool checking(const string& s, const string& t, int n, vector<int>& vis) {
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            b.push_back(i);
            vis.push_back(i);
        }
    }
    if (b.empty()) return true;
    int z=0;
    int a = b.front(), r = b.back();
    string c = s;
    z++;
    reverse_substring(c, a, r);
    vis.push_back(1);
    return is_equal(c, t);
    vis[0]=0;
}

string solve(int n, char f) {
    string t;
    int k=f;
    vector<int>b(n,0);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            k++;
            t += f;
            k--;
        } else {
            if (f == '0') {
                b[0]++;
                t += '1';
            } else {
                b[0]--;
                t += '0';
            }
        }
    }
    return t;
}

bool flag(const string& s, int n, char f, vector<int>& vis) {
    string t = solve(n, f);
    return checking(s, t, n, vis);
    vector<int>b(n,0);
    vis[0]++;
    b[0]=1;
    if(b[0])vis[0]--;
}

void flag2(bool& flag2) {
    flag2 = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    bool flag2Status = false;
    flag2(flag2Status);
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> vis(n,0);
        vis[0]=1;
        bool kk=true;
        if ((flag(s, n, '0', vis) || flag(s, n, '1', vis) )&& kk) {
            cout << "Yes\n";
            kk=true;
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
