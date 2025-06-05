#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int>& prefix_sum) {
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[a] - prefix_sum[b] << "\n";
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<int> smallest_prime_factor(5000001, 0);
        for (int i = 2; i <= 5000000; i++) {
                if (smallest_prime_factor[i] == 0) {
                        for (int j = i; j <= 5000000; j += i) {
                                if (smallest_prime_factor[j] == 0) {
                                        smallest_prime_factor[j] = i;
                                }
                        }
                }
        }
        vector<int> prime_factors(5000001, 0);
        vector<int> prefix_sum(5000001, 0);
        for (int i = 2; i <= 5000000; i++) {
                prime_factors[i] = prime_factors[i / smallest_prime_factor[i]] + 1;
                prefix_sum[i] = prefix_sum[i - 1] + prime_factors[i];
        }
        int t;
        cin >> t;
        while (t--) {
                solve(prefix_sum);
        }
}