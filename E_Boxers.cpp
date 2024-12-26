#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the weights to process them in increasing order
    sort(a.begin(), a.end());

    set<int> unique_weights;

    for (int weight : a) {
        // Try to decrease the weight if possible
        if (weight - 1 > 0 && unique_weights.find(weight - 1) == unique_weights.end()) {
            unique_weights.insert(weight - 1);
        } 
        // Otherwise, use the current weight if it's not taken
        else if (unique_weights.find(weight) == unique_weights.end()) {
            unique_weights.insert(weight);
        } 
        // Otherwise, increase the weight
        else if (unique_weights.find(weight + 1) == unique_weights.end()) {
            unique_weights.insert(weight + 1);
        }
    }

    // The size of the set gives the maximum number of unique weights
    cout << unique_weights.size() << endl;

    return 0;
}
