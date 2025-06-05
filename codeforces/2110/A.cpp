#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        int minimum = a[0];
        int maximum = a[0];
        for (int val : a) {
                minimum = min(minimum, val);
                maximum = max(maximum, val);
        }
        if ((minimum + maximum) % 2 == 0) {
                cout << 0 << endl;
                return;
        }
        int min_ops = n - 1; 
        for (int i = 0; i < n; i++) { 
                for (int j = 0; j < n; j++) { 
                        int min_cand = a[i];
                        int max_cand = a[j];
                        if (min_cand > max_cand) {
                                continue;
                        }
                        if ((min_cand + max_cand) % 2 != 0) {
                                continue;
                        }
                        int current_ops = 0;
                        for (int k = 0; k < n; k++) {
                                if (a[k] < min_cand || a[k] > max_cand) {
                                        current_ops++;
                                }
                        }
                        min_ops = min(min_ops, current_ops);
                }
        }
        cout << min_ops << "\n";
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