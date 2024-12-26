#include <iostream>
#include <string>
using namespace std;

bool canObtain(string s, string t) {
    int i = s.length() - 1; // Pointer for s
    int j = t.length() - 1; // Pointer for t

    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            // Characters match, move both pointers
            i--;
            j--;
        } else {
            // Characters don't match, simulate a backspace
            i -= 2; // Skip the current character and delete one more
        }
    }

    // If t is fully matched, j should be -1
    return j == -1;
}

int main() {
    int q; // Number of test cases
    cin >> q;

    while (q--) {
        string s, t;
        cin >> s >> t;

        if (canObtain(s, t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
