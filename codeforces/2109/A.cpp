#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        bool all_reports_are_one = true;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (a[i] == 0) {
                        all_reports_are_one = false;
                }
        }
        bool adjacent_zeros_exist = false;
        if (n > 1) {
                for (int i = 0; i < n - 1; ++i) {
                        if (a[i] == 0 && a[i + 1] == 0) {
                                adjacent_zeros_exist = true;
                                break;
                        }
                }
        }
        if (adjacent_zeros_exist || all_reports_are_one) {
                cout << "YES\n";
                return;
        }
        cout << "NO\n";
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