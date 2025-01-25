#include <iostream>
#include <vector>
using namespace std;

bool isStable(const vector<int>& a) {
    int n = a.size();
    // Check each consecutive pair
    bool flag=false;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            if (a[i] < 2 * a[i + 1]) {
                flag= true;
                break;
            }
        } else {
            if (a[i + 1] < 2 * a[i]) {
               flag= true;
               break;
            }
        }
    }
    if(flag)return true;
    else return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        if (isStable(a)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
