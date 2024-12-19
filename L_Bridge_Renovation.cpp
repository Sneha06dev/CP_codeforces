#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Total required planks
    int total_planks = 0;

    // Handle planks for width 25
    total_planks += n / 2; // Full pairs of 25 + 25
    if (n % 2 != 0) {
        total_planks += 1; // Additional plank for leftover 25
    }

    // Handle planks for width 21
    int planks_21 = n / 3; // Groups of 21 + 21 + 18
    total_planks += planks_21 * 2; // Two planks for every group of 3
    if (n % 3 != 0) {
        total_planks += 1; // Additional plank for leftovers
    }
    if(n==2)cout <<3<< endl;
    else cout << total_planks << endl;

    return 0;
}
