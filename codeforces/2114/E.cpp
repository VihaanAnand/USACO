#include <iostream>
#include <vector>
using namespace std;
void adjust(long long v, long long p, vector<long long> &res, vector<long long> &arr, long long mini, long long maxi, vector<vector<long long>> &gr) {
        res[v] = max(arr[v], mini * -1 + arr[v]);
        mini = min(arr[v], maxi * -1 + arr[v]);
        for (long long i = 0; i < gr[v].size(); i++) {
                long long u = gr[v][i];
                if (u == p) {
                        continue;
                }
                adjust(u, v, res, arr, mini, res[v], gr);
        }
}
void solve() {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; ++i) {
                cin >> arr[i];
        }
        vector<vector<long long>> gr(n);
        for (long long j = 0; j < n - 1; ++j) {
                long long v, u;
                cin >> v >> u;
                gr[v - 1].push_back(u - 1);
                gr[u - 1].push_back(v - 1);
        }
        vector<long long> res(n, 0);
        adjust(0, -1, res, arr, 0, 0, gr);
        for (long long i = 0; i < n; ++i) {
                cout << res[i] << " ";
        }
        cout << "\n";
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