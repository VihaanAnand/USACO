#include <iostream>
#include <vector>
using namespace std;
struct min_max {
        long long mx1, mx2, mn1, mn2;
        void fix_mx() {
                if (mx1 < mx2) {
                        swap(mx1, mx2);
                }
        }
        void fix_mn() {
                if (mn1 > mn2) {
                        swap(mn1, mn2);
                }
        }
        min_max(long long a, long long b) {
                mx1 = mn1 = a;
                mx2 = mn2 = b;
                fix_mx();
                fix_mn();
        }
        void add(long long first) {
                mx2 = max(mx2, first);
                mn2 = min(mn2, first);
                fix_mx();
                fix_mn();
        }
        long long get_seg(long long first) {
                pair<long long, long long> res = {mn1, mx1};
                if (first == mn1) {
                        res.first = mn2;
                }
                if (first == mx1) {
                        res.second = mx2;
                }
                return res.second - res.first + 1;
        }
};
void solve() {
        long long n;
        cin >> n;
        vector<pair<long long, long long>> coord(n);
        for (long long i = 0; i < n; i++) {
                cin >> coord[i].first >> coord[i].second;
        }
        if (n <= 2) {
                cout << n << "\n";
                return;
        }
        min_max xc(coord[0].first, coord[1].first), yc(coord[0].second, coord[1].second);
        for (long long i = 2; i < n; ++i) {
                xc.add(coord[i].first);
                yc.add(coord[i].second);
        }
        long long ans = xc.get_seg(-1) * yc.get_seg(-1);
        for (long long i = 0; i < n; ++i) {
                long long first = xc.get_seg(coord[i].first);
                long long second = yc.get_seg(coord[i].second);
                if (first * second == n - 1) {
                        ans = min(ans, min((first + 1) * second, first * (second + 1)));
                }
                else {
                        ans = min(ans, first * second);
                }
        }
        cout << ans << "\n";
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long t;
        cin >> t;
        while (t--) {
                solve();
        }
}