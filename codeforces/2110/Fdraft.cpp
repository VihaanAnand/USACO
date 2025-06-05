#include <algorithm>
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
        int max_beauty = 0;
        for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                        max_beauty = max(max_beauty, f(a[i], a[j]));
                }
                cout << max_beauty << " ";
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