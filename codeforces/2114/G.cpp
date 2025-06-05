#include <iostream>
#include <vector>
using namespace std;
long long max_op(long long a, long long b) {
        long long min_part = a;
        while (min_part % 2 == 0 && min_part / 2 != b) {
                min_part /= 2;
        }
        if (min_part % 2 == 1) {
                return a / min_part;
        }
        long long true_min = min_part;
        while (true_min % 2 == 0) {
                true_min /= 2;
        }
        return 1 + (a - min_part) / true_min;
}
bool solve() {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long &e: a) cin >> e;
        vector<long long> pre(n, 0);
        for (long long j = 1; j < n; j++) {
                pre[j] = pre[j - 1] + max_op(a[j - 1], a[j]);
        }
        vector<long long> suf(n, 0);
        for (long long j = n - 2; j >= 0; j--) {
                suf[j] = suf[j + 1] + max_op(a[j + 1], a[j]);
        }
        for (long long i = 0; i < n; i++) {
                long long res = max_op(a[i], 0) + pre[i] + suf[i];
                if (res >= k) {
                        return true;
                }
        }
        return false;
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long t;
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