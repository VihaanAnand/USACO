#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
void solve() {
        long long x;
        cin >> x;
        double log2_val = log2((double) (x));
        long long k = (long long) (floor(log2_val));
        long long result = 2 * k + 3;
        cout << result << "\n";
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