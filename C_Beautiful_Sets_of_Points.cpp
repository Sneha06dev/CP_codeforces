#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // The size of the beautiful set is the minimum of n+1 and m+1.
    int k = min(n, m) + 1;
    cout << k << endl;

    // Generate the beautiful set of points.
    for (int i = 0; i < k; ++i) {
        cout << i << " " << (k - 1 - i) << endl;
    }

    return 0;
}
