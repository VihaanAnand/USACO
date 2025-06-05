#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int>> ans(n, vector<int> (6));
        for (int i = 0; i < n; i += 2) {
                if (i + 1 == n) {
                        for (int j = 0; j < 6; j++) {
                                if (j % 2 == 0) {
                                        ans[i][j] = a[i / 2];
                                }
                                else {
                                        ans[i][j] = a[m - i / 2 - 1];
                                }
                        }
                }
                else {
                        for (int j = 0; j < 6; j++) {
                                if (j % 2 == 0) {
                                        ans[i][j] = a[i / 2];
                                        ans[i + 1][j] = a[m - i / 2 - 1];
                                }
                                else {
                                        ans[i][j] = a[m - i / 2 - 1];
                                        ans[i + 1][j] = a[i / 2];
                                }
                        }
                }
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < 6; j++) {
                        cout << ans[i][j] << " ";
                }
                cout << "\n";
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