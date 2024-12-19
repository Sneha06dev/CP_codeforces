#include <iostream>
#include <map>
using namespace std;

long long combinations(long long n) {
    return (n * (n - 1));
}

int main() {
    long long t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        map<long long, long long> x_count, y_count, diag1_count, diag2_count;
        
        for (long long i = 0; i < n; i++) {
            long long x, y;
            cin >> x >> y;
            
            x_count[x]++;
            y_count[y]++;
            diag1_count[x - y]++;
            diag2_count[x + y]++;
        }
        
        long long valid_pairs = 0;
        
        for (auto& entry : x_count) {
            valid_pairs += combinations(entry.second);
        }
        
        for (auto& entry : y_count) {
            valid_pairs += combinations(entry.second);
        }
        
        for (auto& entry : diag1_count) {
            valid_pairs += combinations(entry.second);
        }
        
        for (auto& entry : diag2_count) {
            valid_pairs += combinations(entry.second);
        }
        
        cout << valid_pairs << endl;
    }
    
    return 0;
}
