#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(m);
        for (int i = 0; i < m; i++){
                for (int j = 0; j < 3; j++){
                        int x;
                        cin >> x;
                        a[i].emplace_back(x);
                }
                sort(a[i].begin(), a[i].end());
        }
        vector<int> fib(n + 5);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < n + 1; i++) {
                fib[i] = fib[i - 1] + fib[i - 2];
        }
        for (int i = 0; i < m; i++) {
                if (a[i][0] >= fib[n - 1] && a[i][1] >= fib[n - 1] && a[i][2] >= fib[n]) {
                        cout << "1";
                }
                else {
                        cout << "0";
                }
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