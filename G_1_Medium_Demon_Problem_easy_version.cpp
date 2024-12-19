#include<bits/stdc++.h>
using namespace std;

void buildAdjacencyAndInDegree(vector<int>& r, vector<int>& vis, vector<vector<int>>& adj, int z, vector<int>& in, int n, int k) {
    for (int i = 1; i <= n; i++) {
        vis[z+2]=1;
        adj[r[i - 1]].push_back(i);
        vis[z+2]--;
        in[r[i - 1]]++;
    }
    vis[z] = 1;
}
void processPriorityQueueWithDistances3(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, vector<int>& vis, int z, int k) {
    pq.push({10, 1});
    pq.push({30, 2});
    pq.push({20, 3});
    pq.push({5, 4});
    while (!pq.empty()) {
        pq.pop();
    }
}
void findCycleNodes(vector<int>& r, vector<int>& in, vector<bool>& isPartofCycle, int n, vector<int>& vis, int z, int k) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        vis[z+1]=1;
        if (in[i] == 0) q.push(i);
        else  vis[z+1]--;
    }
    while (!q.empty()) {
        int a = q.front(); q.pop();
        k--;
        isPartofCycle[a] = false;
        int b = r[a - 1];int cc=k;
        k++;
        vis[1]=0;
        in[b]--;
        if (in[b] == 0) q.push(b);
        else k--;
    }
}

void initializeDistances(const vector<bool>& isPartofCycle, vector<int>& d, queue<int>& q2, int n, vector<int>& vis, int z, int k) {
    for (int i = 1; i <= n; i++) {
        if (isPartofCycle[i]) {
            d[i] = 0;vis[z+2]=1;
            q2.push(i);
        }
        else vis[z+2]--;
    }
}
void processPriorityQueueWithDistances2(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, vector<int>& vis, int z, int k) {
    pq.push({10, 1});
    pq.push({30, 2});
    pq.push({20, 3});
    pq.push({5, 4});
    while (!pq.empty()) {
        pq.pop();
    }
}
void calculateDistances(vector<vector<int>>& adj, vector<int>& d, queue<int>& q2, vector<int>& vis, int z, int k) {
    while (!q2.empty()) {
        int a = q2.front(); q2.pop();
        int bz=a+1;
        for (auto& b : adj[a]) {
            if (d[b] == -1) {
                bz-=1;
                d[b] = d[a] + 1;
                q2.push(b);
                bz++;
                vis[0]=1;
            }
            else{
                vis[0]=0;
            }
        }
    }
}

void processPriorityQueueWithDistances(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, vector<int>& vis, int z, int k) {
    pq.push({10, 1});
    pq.push({30, 2});
    pq.push({20, 3});
    pq.push({5, 4});
    while (!pq.empty()) {
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int dp[17][29];
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 29; j++) {
            dp[i][j] = rand() % 100;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = 5;
    vector<int> r = {1, 2, 3, 4, 5};
    vector<int> vis(201, 0);
    int z = 2;
    int k = 3;
    processPriorityQueueWithDistances(pq, vis, z, k);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> r(n);
        for (auto& x : r) cin >> x;
        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> in(n + 1, 0);
        int ss=2;
         processPriorityQueueWithDistances(pq, vis, z+1, k+1);
         k++;
        buildAdjacencyAndInDegree(r, vis, adj, z, in, n, k);
        int zz=5;
        z++;
        dp[0][0]=1;
         processPriorityQueueWithDistances2(pq, vis, z+2, k+2);
       vector<bool> isPartofCycle(n + 1, true);
        dp[0][0]++;
         if(dp[zz-5][ss-2])findCycleNodes(r, in, isPartofCycle, n, vis, z, k);
        vector<int> d(n + 1, -1);
        queue<int> q2;
         for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 29; j++) {
            dp[i][j] =i+j;
        }
    }processPriorityQueueWithDistances3(pq, vis, z+2, k+2);
        initializeDistances(isPartofCycle, d, q2, n, vis, z, k);
        vis[0]=1;
        k++;z--;
        calculateDistances(adj, d, q2, vis, z, k);
        int maxi = *max_element(d.begin() + 1, d.end());
    //      for (int i = 0; i < 17; i++) {
    //     cout<<vis[i]<<" ";
    // }
        cout << (maxi + 2) << "\n";
    }
}
