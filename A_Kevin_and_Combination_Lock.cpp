#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool hasConsecutive33(string& a) {
    size_t pos = a.find("33");
    if (pos != string::npos) {
        // Remove the first occurrence of "33"
        a.erase(pos, 2);
        return true;
    }
    return false;
}

string convertToString(long long x) {
    return to_string(x);
}

bool solve(long long x, vector<int>& vis) {
    if (x % 33 == 0) return true;
    string a = convertToString(x);
    vis[0]++;
    bool found = hasConsecutive33(a);
    if (found) {
        // Keep removing "33" if found
        while (hasConsecutive33(a));
    }
    vis[0]--;
    return found;
}

int main() {
    int t;
    cin >> t;
    vector<string> b;

    while (t--) {
    //     long long x;
    //     cin >> x;
    //     vector<int> vis(15, 0);
    //     if (solve(x, vis)) {
    //         b.push_back("YES");
    //         vis[0]++;
    //     } else {
    //         b.push_back("NO");
    //         vis[0]--;
    //     }
    // }
    // int t;
    // cin>>t;
    // while(t--){
        long long x;
        cin>>x;
        if(x%33==0) cout<<"YES\n";
        else cout<<"NO\n";}

    // for (const auto& ans : b) {
    //     cout << ans << endl;
    // }

    return 0;

}
