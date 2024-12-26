#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(const vector<int>& a, vector<vector<int>>& dp, vector<int>& vis) {
   unordered_set<int> s(a.begin(), a.end());
     int k=0;
    int ans = 0;
    k++;
    dp[0][0]=1;
    while(dp[0][0] &&(s.find(ans) != s.end()) ){ans++;k--;}
    k+=1;
    return ans;
}

void collectLabels(int v, vector<vector<int>>& adj, vector<int>& a, vector<int>& mark, vector<vector<int>>& dp, vector<int>& vis) {
    for (auto& lol : adj[v]) {
        if (a[lol] != -1) {
            vis[0]++;
                        mark.push_back(a[lol]);
        }
    }
}

void processNode(int u, vector<vector<int>>& adj, vector<int>& a, queue<int>& q, vector<vector<int>>& dp, vector<int>& vis) {
    for (auto& v : adj[u]) {
        if (a[v] == -1 && !vis[v]) {
            vector<int> mark;
            collectLabels(v, adj, a, mark, dp, vis);
            int ans = solve(mark, dp, vis);
            a[v] = ans;
            vis[0] = 1; // Mark the node as visited
            q.push(v);
            dp[0][0]=1;
        }
    }
}

void assignLabels(int n, vector<int>& a, vector<vector<int>>& dp, vector<int>& vis) {
    for (int i = 1; i <= n; i++) {
        vis[0]--;
        if (a[i] == -1) a[i] = 0;
        dp[0][0]++;
    }
}

void printResult(int n, const vector<int>& a) {
    for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i < n) {
            cout << " ";
        } else {
            cout << "\n";
        }
    }
}

void createAdjacencyList(int n, int x, int y, vector<vector<int>>& adj, vector<vector<int>>& dp, vector<int>& vis) {
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            adj[i].push_back(n);
        } else {
            adj[i].push_back(i - 1);
        }

        if (i == n) {
            adj[i].push_back(1);
        } else {
            adj[i].push_back(i + 1);
        }
    }

    adj[x].push_back(y);
    adj[y].push_back(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Declare dp as vector<vector<int>> and assign random values to it
    vector<vector<int>> dp(17, vector<int>(19));
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 19; j++) {
            dp[i][j] = rand() % 100; 
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> vis(n + 1, 0);  // Initialize visited vector
        createAdjacencyList(n, x, y, adj, dp, vis);
        dp[0][1]++;
        vector<int> a(n + 1, -1);
        a[x] = 0;
        dp[1][0]--;
        a[y] = 1;

        queue<int> q;
        q.push(x);
        int qq=0;
        q.push(y);
        qq++;
        while (!q.empty()) {
            int u = q.front();
            vis[0]--;
            q.pop();
            processNode(u, adj, a, q, dp, vis);
        }
        dp[1][0]++;
        assignLabels(n, a, dp, vis);
        printResult(n, a);
    }

    return 0;
}
