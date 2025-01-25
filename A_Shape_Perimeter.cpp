#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t;  // Reading the number of test cases
    while(t--) {
        int n, m; 
        cin >> n >> m;  // Reading the number of operations and the size of the square
        int totalX = 0, totalY = 0;
        
        // Reading n operations and calculating the sum of x and y values excluding the first one
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;  // Reading x and y
            if (i != 0) {
                totalX += x;  // Sum x values excluding the first operation
                totalY += y;  // Sum y values excluding the first operation
            }
        }

        // Calculate the final result
        int result = 2 * (totalX + totalY + 2 * m);  // Add 2*m and multiply by 2

        // Output the result
        cout << result << "\n";
    }
    return 0;
}
