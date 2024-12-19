#include <bits/stdc++.h>
using namespace std;

const int MAX_POW = 40;
const long long INF = 1e15;

bool isValidLength(long long length) {
    return (length - 1) <= MAX_POW;
}

// Function to handle the case when the length exceeds the maximum allowed power
long long handleLargeLength() {
    return INF;
}

vector<long long> initialize_pow2(int max_pow) {
    vector<long long> pow2(max_pow + 1, 1); // Initialize with 1 for the base case
    return pow2;
}

// Function to compute powers of two iteratively up to 2^MAX_POW
void compute_powers_of_two(vector<long long>& pow2, int max_pow) {
    for (int i = 1; i <= max_pow; ++i) {
        pow2[i] = pow2[i - 1] * 2;  // Compute 2^i using the previous value
    }
}

// Function to precompute powers of two by using the above functions
vector<long long> precompute_powers_of_two(int max_pow) {
    vector<long long> pow2 = initialize_pow2(max_pow);  // Initialize the vector
    compute_powers_of_two(pow2, max_pow);  // Compute powers of two
    return pow2;
}

struct Task {
    enum Type {AA, RG, BB, PR, UNUSED1} type;
    long long l, r, k, z, c;
    int val;
    int a;
    int b;
    Task() : type(UNUSED1), l(0), r(0), k(0), val(0) {}
    Task(long long l_, long long r_, long long k_) : type(RG), l(l_), r(r_), k(k_), val(0) {}
    Task(long long l_, long long r_, long long k_, long long z_) : type(AA), l(l_), r(r_), k(k_), z(z_), val(0) {}
    Task(long long l_, long long r_, long long k_, long long z_, long long c_) : type(BB), l(l_), r(r_), k(k_), z(z_), c(c_), val(0) {}
    Task(int v) : type(PR), l(0), r(0), k(0), val(v) {}
};

// Function to return the corresponding power of 2 for the given length
long long getPowerOfTwo(long long length, const vector<long long>& pow2) {
    return pow2[length - 1];
}

// Refactored lolol function with DP optimization
long long lolol(long long length, const vector<long long>& pow2, vector<long long>& dp) {
    if (length <= 1)
        return 1;  // Base case for length 0 or 1
    
    if (isValidLength(length)) {
        // Check DP table for precomputed values
        if (dp[length] != -1) {
            return dp[length];  // Return precomputed value
        }

        dp[length] = getPowerOfTwo(length, pow2);  // Store the result in the DP array
        return dp[length];
    } else {
        return handleLargeLength();  // Handle large length case (i.e., return INF)
    }
}

// New function to handle the n == 1 case
void handleNIsOne(long long k, string& output) {
    if (k == 1) {
        output += "1 \n";
    } else {
        output += "-1\n";
    }
}

// Function to check if l > r
bool isGreaterThanR(long long l, long long r) {
    return l > r;
}

// Function to check if l == r
bool isEqualToR(long long l, long long r) {
    return l == r;
}

// Function to process each task in the stack
void processTask(Task& current, vector<int>& result, vector<Task>& uselesssss, const vector<long long>& pow2, vector<long long>& dp) {
    long long l = current.l;
    long long r = current.r;
    long long cur_k = current.k;

    while (true) {
        if (isEqualToR(l, r)) {
            result.push_back(static_cast<int>(l));
            break;
        }

        long long length = r - l;
        long long half = lolol(length, pow2, dp);  // Use the DP-optimized function

        if (cur_k <= half) {
            result.push_back(static_cast<int>(l));
            l += 1;
        } else {
            uselesssss.emplace_back(static_cast<int>(l));
            l += 1;
            cur_k -= half;
            continue;
        }

        // Using isGreaterThanR to check if l > r
        if (isGreaterThanR(l, r)) {
            break;
        }

        if (isEqualToR(l, r)) {
            result.push_back(static_cast<int>(l));
            break;
        }
    }
}

// Function to convert result vector to string and append it to output
void convertResultToString(const vector<int>& result, string& output) {
    string res_str;
    for (auto num : result) {
        res_str += to_string(num) + " ";
    }
    res_str += "\n";
    output += res_str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> pow2 = precompute_powers_of_two(MAX_POW);
    vector<long long> dp(MAX_POW + 1, -1);  // Initialize DP array with -1 (indicating uncomputed values)

    long long t;
    cin >> t;
    string output;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (n == 1) {
            // Call the new function to handle the n == 1 case
            handleNIsOne(k, output);
            continue;
        }

        long long total_count = lolol(n, pow2, dp);  // Use the DP-optimized function
        if (k > total_count) {
            output += "-1\n";
            continue;
        }

        vector<Task> uselesssss;
        uselesssss.emplace_back(n >= 1 ? Task(1, n, k) : Task(1, n, k));

        vector<int> result;

        while (!uselesssss.empty()) {
            Task current = uselesssss.back();
            uselesssss.pop_back();

            if (current.type == Task::PR) {
                result.push_back(current.val);
            } else {
                // Process the current task using the new function
                processTask(current, result, uselesssss, pow2, dp);
            }
        }

        // Convert result to string and append to output
        convertResultToString(result, output);
    }

    cout << output;

    return 0;
}
