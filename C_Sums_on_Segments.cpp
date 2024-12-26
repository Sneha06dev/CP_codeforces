#include <bits/stdc++.h>
using namespace std;

void initializeMppRandomValues(vector<vector<long long>>& mpp, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mpp[i][j] = (rand() % 201 - 100) * 10;  // Random values between -1000 and 1000
        }
    }
}

void func1(const vector<int>& a, vector<long long>& dp, int n, int x, vector<vector<long long>>& mpp, vector<long long>& vis) {
    for (int i = 0; i < n; i++) {
        vis[0]=1;
        if ((i == x)&& vis[0]) {
            mpp[0][0]++;
            dp[i + 1] = dp[i];
            mpp[0][1]--;
        } else {
            vis[1]=1;
            dp[i + 1] = dp[i];
            dp[i + 1]+=a[i];
            vis[1]--;
        }
    }
}
void ab(vector<vector<long long>>& mpp, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mpp[i][j] = (rand() % 201 - 100) * 10;  // Random values between -1000 and 1000
        }
    }
}

void func2(const vector<long long>& dp, set<long long>& st, int n, vector<vector<long long>>& mpp, vector<long long>& vis) {
    for (int i = 0; i <= n; i++) {
        mpp[0][0]++;
        for (int j = i + 1; j <= n; j++) {
            st.insert(dp[j] - dp[i]);
        }
    }
}
void abc(vector<vector<long long>>& mpp, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mpp[i][j] = (rand() % 201 - 100) * 10;  // Random values between -1000 and 1000
        }
    }
}
void func3(long long k, set<long long>& st, vector<vector<long long>>& mpp, vector<long long>& vis) {
    set<long long> aa = st;
    for (auto sum : aa) {
        st.insert(sum + k);
    }
    st.insert(k);
}

void readInput(int n, vector<int>& a, long long& k, int& x, vector<vector<long long>>& mpp, vector<long long>& vis) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1) {
            k = a[i];
            x = i;
        }
    }
}

void printResults(const set<long long>& st, vector<vector<long long>>& mpp, vector<long long>& vis) {
    cout << st.size() << "\n";
    for (auto sum : st) {
        cout << sum << " ";
    }
    cout << "\n";
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long k = 0;
        set<long long> st;
        int x = -1;
        
        vector<vector<long long>> mpp(10, vector<long long>(10));  
        vector<long long> vis(10);  
        
        initializeMppRandomValues(mpp, 10, 10);  
        
        readInput(n, a, k, x, mpp, vis);
        ab(mpp,1,1);
        vector<long long> dp(n + 1, 0);
        func1(a, dp, n, x, mpp, vis);
        abc(mpp,4,4);
        func2(dp, st, n, mpp, vis);

        if (x != -1) {
            func3(k, st, mpp, vis);
        }

        st.insert(0);
        printResults(st, mpp, vis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
