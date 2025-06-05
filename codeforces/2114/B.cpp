#include <iostream>
using namespace std;
bool solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int count_0 = 0;
        int count_1 = 0;
        for (char c : s) {
                if (c == '0') {
                        count_0++;
                }
                else {
                        count_1++;
                }
        }
        if (k == n / 2) {
                if (count_0 % 2 == 0) {
                        return true;
                }
                else {
                        return false;
                }
        }
        else {
                int nongood_pairs = n / 2 - k;
                if (count_0 < nongood_pairs || count_1 < nongood_pairs) {
                        return false;
                }
                int remaining_0 = count_0 - nongood_pairs;
                int remaining_1 = count_1 - nongood_pairs;
                if (remaining_0 % 2 == 0) {
                        return true;
                }
                else {
                        return false;
                }
        }
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                if (solve()) {
                        cout << "YES\n";
                }
                else {
                        cout << "NO\n";
                }
        }
}