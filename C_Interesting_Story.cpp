#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<string> words(n);
    unordered_map<char, vector<int>> letter_count;

    // Read the words and count the occurrences of each letter in them
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        unordered_map<char, int> freq;
        for (char c : words[i]) {
            freq[c]++;
        }
        for (char c = 'a'; c <= 'e'; c++) {
            letter_count[c].push_back(freq[c]);
        }
    }

    int max_words = 0;

    // Check for each character if it can be the dominant one
    for (char c = 'a'; c <= 'e'; c++) {
        vector<int> counts = letter_count[c];
        int total_count = 0;
        for (int count : counts) {
            total_count += count;
        }
        
        int words_used = 0;
        for (int count : counts) {
            if (total_count - count < count) {
                words_used++;
                total_count -= count;
            }
        }

        max_words = max(max_words, words_used);
    }

    return max_words;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
