#include <iostream>
#include <vector>
using namespace std;
struct edge {
        int t, w;
        edge(int t, int w) : t(t), w(w) {}
};
bool check(int maxW, int n, vector<int>& b, vector<vector<edge>>& graph) {
        vector<int> best(n, 0);
        for (int i = 0; i < n; i++) {
                if (i > 0 && best[i] == 0) {
                        continue;
                }
                best[i] += b[i];
                best[i] = min(best[i], maxW);
                for (int j = 0; j < graph[i].size(); j++) {
                        edge p = graph[i][j];
                        if (p.w <= best[i]) {
                                best[p.t] = max(best[p.t], best[i]);
                        }
                }
        }
        return (best.back() > 0);
}
void solve() {
        int n, m;
        cin >> n >> m;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
                cin >> b[i];
        }
        vector<vector<edge>> graph(n);
        for (int i = 0; i < m; i++) {
                int s, t, w;
                cin >> s >> t >> w;
                s--;
                t--;
                graph[s].push_back(edge(t, w));
        }
        if (!check(1000000011, n, b, graph)) {
                cout << -1 << "\n";
                return;
        }
        int l = 0, r = 1000000011;
        while (r - l > 1) {
                int mid = (l + r) / 2;
                if (check(mid, n, b, graph)) {
                        r = mid;
                }
                else {
                        l = mid;
                }
        }
        cout << r << "\n";
}
int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                solve();
        }
        return 0;
}