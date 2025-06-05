#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<pair<int, int>> rec({
                make_pair(a, m), make_pair(n - a + 1, m),
                make_pair(n, b), make_pair(n, m - b + 1)
        });
        int ans = n + m;
        for (auto [n1, m1] : rec) {
                int res = 0;
                while (n1 > 1) {
                        res++;
                        n1 = (n1 + 1) / 2;
                }
                while (m1 > 1) {
                        res++;
                        m1 = (m1 + 1) / 2;
                }
                ans = min(ans, res);
        }
        cout << ans + 1 << "\n";
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