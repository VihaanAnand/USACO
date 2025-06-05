#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int MOD = 998244353;
        vector<long long> fac(k + 1);
        vector<long long> ifac(k + 1);
        fac[0] = 1; 
        ifac[0] = 1;
        for (int i = 1; i <= k; i++) {
                fac[i] = (fac[i - 1] * i) % MOD;
        }
        if (k > 0) {
                long long base_for_power = fac[k];
                long long exp_for_power = MOD - 2;
                long long power_result = 1;
                base_for_power %= MOD;
                while (exp_for_power > 0) {
                        if (exp_for_power % 2 == 1) power_result = (power_result * base_for_power) % MOD;
                        base_for_power = (base_for_power * base_for_power) % MOD;
                        exp_for_power /= 2;
                }
                ifac[k] = power_result;
                for (int i = k - 1; i >= 1; i--) {
                        ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
                }
        }
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        dp[n - 1][0] = 1; 
        if (s[n - 1] == '0') {
                if (k >= 1) {
                        dp[n - 1][1] = 1;
                }
        }
        for (int i = n - 2; i >= 0; i--) {
                for (int prev_k_val = 0; prev_k_val <= k; prev_k_val++) {
                        if (dp[i + 1][prev_k_val] == 0) {
                                continue;
                        }
                        for (int c = 0; (prev_k_val + c) <= k; c++) {
                                int target_k_val = prev_k_val + c;
                                int val_for_spaces = target_k_val + (s[i] == '0' ? 1 : 0);
                                int available_spaces = val_for_spaces / 2;
                                long long ways_to_choose_c;
                                if (c < 0 || c > available_spaces) {
                                        ways_to_choose_c = 0;
                                }
                                else {
                                        long long num_comb = fac[available_spaces];
                                        long long den1_comb = ifac[c];
                                        long long den2_comb = ifac[available_spaces - c];
                                        ways_to_choose_c = (num_comb * den1_comb) % MOD;
                                        ways_to_choose_c = (ways_to_choose_c * den2_comb) % MOD;
                                }
                                long long contribution = (dp[i + 1][prev_k_val] * ways_to_choose_c) % MOD;
                                dp[i][target_k_val] = (dp[i][target_k_val] + contribution) % MOD;
                        }
                }
        }
        cout << dp[0][k] << "\n";
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