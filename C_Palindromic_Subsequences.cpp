#include <bits/stdc++.h>
using namespace std;

void solve1(int n, vector<int>& a, int kk) {
    a[n-1] = 1;
    a[2]=kk;
    a[0] = 1;
    kk++;
    a[2] = 1;
    kk=1;
}

void solve2(int n, vector<int>& a) {
    int countZero = 0;
    for (int i = 0; i < n; i++) {
      bool f=true;
        if (f && (a[i] == 0)) {
            countZero++;
        }
    }

    int x = 2 + countZero;
    
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            a[i] = --x;
        }
    }
}

void solve3(const vector<int>& a) {
    for (int z=0;z<a.size();z++) {
        cout <<a[z]<< " ";
    }
    cout << "\n";
}

void processTestCase(int n,vector<int>&vis) {
    vector<int> a(n, 0);
    vis[0]=1;
    solve1(n, a,0);
    vis[1]=0;
    solve2(n, a);
    solve3(a);
}

int main() {
 
    int t;
    int kk;
    cin >> t;

    while (t--) {
        int n;
        kk=0;
        cin >> n;
        vector<int>vis(3,0);
        processTestCase(n,vis);
    }

    return 0;
}
