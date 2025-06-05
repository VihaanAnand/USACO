// #include <iostream>
// #include <vector>
// using namespace std;
// bool equal(vector<long long> a) {
//         if (a.empty() || a.size() == 1) {
//                 return true;
//         }
//         for (int i = 1; i < a.size(); ++i) {
//                 if (a[i] != a[0]) {
//                         return false;
//                 }
//         }
//         return true;
// }
// void solve() {
//         int n;
//         cin >> n;
//         vector<long long> a(n);
//         for (int i = 0; i < n; ++i) {
//                 cin >> a[i];
//         }
//         if (equal(a)) {
//                 cout << "0\n";
//                 return;
//         }
//         long long cost = 5000000001;
//         for (int i = 0; i < n; i++) {
//                 int left_index = i;
//                 long long val = a[i];
//                 int right_index;
//                 for (int j = n - 1; j >= i; j--) {
//                         if (a[j] == val) {
//                                 right_index = j;
//                                 break;
//                         }
//                 }
//                 long long current_cost = (left_index + n - right_index - 1) * val;
//                 if (current_cost < cost) {
//                         cost = current_cost;
//                 }
//         }
//         cout << cost << "\n";
// }
// int main() {
//         ios_base::sync_with_stdio(false);
//         cin.tie(0);
//         int t;
//         cin >> t;
//         while (t--) {
//                 solve();
//         }
// }

#include <iostream>
#include <vector>
#include <algorithm> // For std::min
#include <limits>    // For std::numeric_limits

// Function to check if all elements in a vector are equal
bool all_elements_equal(const std::vector<long long>& a) {
    if (a.empty() || a.size() == 1) {
        return true;
    }
    for (size_t i = 1; i < a.size(); ++i) {
        if (a[i] != a[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        if (all_elements_equal(a)) {
            std::cout << 0 << std::endl;
            continue;
        }

        long long min_total_cost = std::numeric_limits<long long>::max();

        int i = 0; // Current index to start searching for a block
        while (i < n) {
            int L_idx_0based = i; // Start index of current block (0-based)
            long long current_val = a[i];
            
            int j = i; // End index of current block (0-based), initially same as start
            // Extend block to the right as long as values are same
            while (j + 1 < n && a[j + 1] == current_val) {
                j++;
            }
            int R_idx_0based = j; // Final end index of current block

            // Calculate cost for this block
            // Cost = (elements to left of L_idx_0based) * current_val + (elements to right of R_idx_0based) * current_val
            long long cost_for_this_block = (long long)L_idx_0based * current_val + 
                                            (long long)(n - 1 - R_idx_0based) * current_val;
            
            min_total_cost = std::min(min_total_cost, cost_for_this_block);
            
            i = j + 1; // Move to the start of the next potential block
        }
        std::cout << min_total_cost << std::endl;
    }
    return 0;
}