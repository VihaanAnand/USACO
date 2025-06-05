#include <iostream>
#include <vector>
using namespace std;
int f(int x, int y) {
        return (x % y) + (y % x);
}
void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        int ans = 0;
        int mx = a[0];
        for (int i = 0; i < n; i++) {
                ans = max(ans, f(mx, a[i]));
                if (a[i] > mx) {
                        if (a[i] >= mx * 2) {
                                mx = a[i];
                                for (int j = 0; j < i; j++) {
                                        ans = max(ans, f(a[i], a[j]));
                                }
                        }
                        else {
                                mx = a[i];
                                ans = mx;
                        }
                }
                cout << ans << " ";
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