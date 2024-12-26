#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read number of test cases
    
    while (t--) {
        long long a, b;
        cin >> a >> b;  // Read a and b
        
        long long d = abs(a - b);  // Calculate the absolute difference
        if(d==0){cout<<0<<endl;}
        else{
        long long n = 1;  // Start checking triangular numbers from n = 1
        long long triangular = 1;  // First triangular number is 1
        
        // Incrementally calculate triangular numbers and check the conditions
        while (triangular < d || (triangular - d) % 2 != 0) {
            n++;
            triangular = n * (n + 1) / 2;  // Calculate the n-th triangular number
        }
        
        cout << n << endl;  // Output the result for this test case
    }
    }
    
    return 0;
}
