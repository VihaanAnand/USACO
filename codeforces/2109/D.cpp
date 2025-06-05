#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void solve() {
        int n, m, l;
        cin >> n >> m >> l;
        int const inf = 2e9 + 1;
        int sum = 0, min_odd = inf;
        vector<int> a(l);
        for (int i = 0; i < l; i++) {
                cin >> a[i];
                sum += a[i];
                if (a[i] % 2) {
                        min_odd = min(min_odd, a[i]);
                }
        }
        vector adj(n, vector<int>());
        for (int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                u--;
                v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        vector<array<int, 2>> dist(n, {inf, inf});
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        while (q.size()) {
                auto [u, p] = q.front();
                q.pop();
                for (auto v : adj[u]) {
                        if (dist[v][!p] > dist[u][p] + 1) {
                                dist[v][!p] = dist[u][p] + 1;
                                q.push({v, !p});
                        }
                }
        }
        for (int i = 0; i < n; i++) {
                bool found = 0;
                for (int p = 0; p < 2; p++) {
                        int s = sum - (p == sum % 2 ? 0 : min_odd);
                        if (dist[i][p] <= s) {
                                found = 1;
                        }
                }
                cout << found;
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