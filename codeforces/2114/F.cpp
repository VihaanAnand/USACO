#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
        if (b == 0) {
                return a;
        }
        return gcd(b, a % b);
}
int get_ans(int first, int k) {
        if (first == 1) {
                return 0;
        }
        vector<int> divs;
        for (int i = 1; i * i <= first; i++) {
                if (first % i == 0) {
                        divs.push_back(i);
                        divs.push_back(first / i);
                }
        }
        sort(divs.begin(), divs.end());
        int n = divs.size();
        vector<int> dp(n, 100);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
                for (int j = i - 1; j >= 0; j--) {
                        if (divs[i] / divs[j] > k) {
                                break;
                        }
                        if(divs[i] % divs[j] == 0) {
                                dp[i] = min(dp[i], dp[j] + 1);
                        }
                }
        }
        if (dp[n - 1] == 100) {
                return -1;
        }
        return dp[n - 1];
}
void solve() {
        int first, second, k;
        cin >> first >> second >> k;
        int g = gcd(first, second);
        first /= g;
        second /= g;
        int ax = get_ans(first, k);
        int ay = get_ans(second, k);
        if (ax == -1 || ay == -1) {
                cout << "-1\n";
        }
        else {
                cout << ax + ay << "\n";
        }
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