#include <iostream>
#include <vector>
using namespace std;
vector<int> primes(int n) {
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p <= n; p++) {
                if (prime[p]) {
                        for (int i = p * p; i <= n; i += p) {
                                prime[i] = false;
                        }
                }
        }
        vector<int> result;
        for (int p = 2; p <= n; p++) {
                if (prime[p]) {
                        result.push_back(p);
                }
        }
        return result;
}
vector<int> factors(int n) {
        vector<int> primenums = primes(n);
        vector<int> result;
        for (int i = 0; i < primenums.size(); i++) {
                if (n % primenums[i] == 0) {
                        result.push_back(primenums[i]);
                }
        }
        return result;
}
void solve() {
        int x, y, k;
        cin >> x >> y >> k;
        vector<int> factors_x = factors(x);
        vector<int> factors_y = factors(y);
        vector<int> factors_needed;
        for (int i = 0; i < factors_y.size(); i++) {
                bool found = false;
                for (int j = 0; j < factors_x.size(); j++) {
                        if (factors_y[i] == factors_x[j]) {
                                found = true;
                                break;
                        }
                }
                if (!found) {
                        factors_needed.push_back(factors_y[i]);
                }
        }
        vector<int> factors_not_needed = factors_x;
        for (int i = 0; i < factors_x.size(); i++) {
                bool found = false;
                for (int j = 0; j < factors_y.size(); j++) {
                        if (factors_x[i] == factors_y[j]) {
                                found = true;
                                break;
                        }
                }
                if (!found) {
                        factors_not_needed.push_back(factors_x[i]);
                }
        }
        for (int i = 0; i < factors_needed.size(); i++) {
                if (factors_needed[i] > k) {
                        cout << "-1\n";
                        return;
                }
        }
        for (int i = 0; i < factors_not_needed.size(); i++) {
                if (factors_not_needed[i] > k) {
                        cout << "-1\n";
                        return;
                }
        }
        for (int i = 0; i < k; i++) {
                for (int i = 0; i < factors_needed.size(); i++) {
                        for (int j = i + 1; j < factors_needed.size(); j++) {
                                if (factors_needed[i] * factors_needed[j] <= k) {
                                        factors_needed[i] = factors_needed[i] * factors_needed[j];
                                        factors_needed.erase(factors_needed.begin() + j);
                                        j--;
                                }
                        }
                }
                for (int i = 0; i < factors_not_needed.size(); i++) {
                        for (int j = i + 1; j < factors_not_needed.size(); j++) {
                                if (factors_not_needed[i] * factors_not_needed[j] <= k) {
                                        factors_not_needed[i] = factors_not_needed[i] * factors_not_needed[j];
                                        factors_not_needed.erase(factors_not_needed.begin() + j);
                                        j--;
                                }
                        }
                }
        }
        //if there are any elements in both factors_needed and factors_not_needed, we can delete them both
        for (int i = 0; i < factors_needed.size(); i++) {
                for (int j = 0; j < factors_not_needed.size(); j++) {
                        if (factors_needed[i] == factors_not_needed[j]) {
                                factors_needed.erase(factors_needed.begin() + i);
                                factors_not_needed.erase(factors_not_needed.begin() + j);
                                i--;
                        }
                }
        }
        cout << factors_needed.size() + factors_not_needed.size() << "\n";
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