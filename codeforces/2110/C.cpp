#include <algorithm>
#include <iostream>
#include <vector> 
using namespace std;
void solve() {
        int n;
        cin >> n;
        vector<int> d_input(n); 
        for (int i = 0; i < n; i++) {
                cin >> d_input[i];
        }
        vector<int> l_constraints(n), r_constraints(n); 
        for (int i = 0; i < n; i++) {
                cin >> l_constraints[i] >> r_constraints[i];
        }
        vector<long long> min_h(n + 1);
        vector<long long> max_h(n + 1);
        min_h[0] = 0;
        max_h[0] = 0;
        for (int i = 0; i < n; i++) {
                long long prev_min = min_h[i]; 
                long long prev_max = max_h[i]; 
                long long next_min_cand, next_max_cand; 
                if (d_input[i] == 0) { 
                        next_min_cand = prev_min + 0;
                        next_max_cand = prev_max + 0;
                }
                else if (d_input[i] == 1) { 
                        next_min_cand = prev_min + 1;
                        next_max_cand = prev_max + 1;
                }
                else { 
                        next_min_cand = prev_min + 0; 
                        next_max_cand = prev_max + 1; 
                }
                min_h[i + 1] = max((long long) l_constraints[i], next_min_cand);
                max_h[i + 1] = min((long long) r_constraints[i], next_max_cand);
                if (min_h[i+1] > max_h[i + 1]) {
                        cout << "-1\n";
                        return;
                }
        }
        vector<long long> actual_h(n + 1); 
        vector<int> d_final(n);  
        actual_h[n] = min_h[n]; 
        for (int i = n - 1; i >= 0; i--) {
                long long chosen_h_next = actual_h[i+1]; 
                long long h_if_d0 = chosen_h_next - 0; 
                long long h_if_d1 = chosen_h_next - 1; 
                bool possible_to_choose_d0 = (h_if_d0 >= min_h[i] && h_if_d0 <= max_h[i]);
                bool possible_to_choose_d1 = (h_if_d1 >= min_h[i] && h_if_d1 <= max_h[i]);
                if (d_input[i] == 0) { 
                        if (!possible_to_choose_d0) {
                                cout << "-1\n";
                                return;
                        }
                        d_final[i] = 0;
                        actual_h[i] = h_if_d0;
                }
                else if (d_input[i] == 1) { 
                        if (!possible_to_choose_d1) {
                                cout << "-1\n";
                                return;
                        }
                        d_final[i] = 1;
                        actual_h[i] = h_if_d1;
                }
                else { 
                        if (possible_to_choose_d1) {
                                d_final[i] = 1;
                                actual_h[i] = h_if_d1;
                        }
                        else if (possible_to_choose_d0) {
                                d_final[i] = 0;
                                actual_h[i] = h_if_d0;
                        }
                        else {
                                cout << "-1\n";
                                return;
                        }
                }
        }
        if (actual_h[0] != 0) {
                cout << "-1\n";
                return;
        }
        for (int k = 0; k < n; k++) {
                cout << d_final[k] << (k == n - 1 ? "" : " ");
        }
        cout << "\n";
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                solve();
        }
}