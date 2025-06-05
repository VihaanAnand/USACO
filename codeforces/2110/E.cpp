#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
void dfs(int v, vector<set<int>>& graph, vector<int>& ans) {
        while (!graph[v].empty()) {
                int u = *graph[v].begin();
                graph[u].erase(v);
                graph[v].erase(u);
                dfs(u, graph, ans);
        }
        ans.push_back(v);
}
bool solve() {
        vector<set<int>> graph;
        vector<int> ans;
        graph.clear();
        ans.clear();
        int n;
        cin >> n;
        map<int, int> p, v;
        map<pair<int, int>, int> toIndex;
        vector<pair<int, int>> part;
        for (int i = 1; i <= n; i++) {
                int volume, pitch;
                cin >> volume >> pitch;
                toIndex[make_pair(volume, pitch)] = i;
                if (p.count(pitch) == 0) {
                        p[pitch] = graph.size();
                        graph.push_back(set<int>());
                        part.push_back(make_pair(0, pitch));
                }
                if (v.count(volume) == 0) {
                        v[volume] = graph.size();
                        graph.push_back(set<int>());
                        part.push_back(make_pair(volume, 0));
                }
                graph[v[volume]].insert(p[pitch]);
                graph[p[pitch]].insert(v[volume]);
        }
        int root = 0;
        int cnt = 0;
        for (int i = 0; i < graph.size(); i++) {
                if (graph[i].size() % 2 == 1) {
                        cnt++;
                        root = i;
                }
        }
        dfs(root, graph, ans);
        if (ans.size() != n + 1 || cnt > 2) {
                return false;
        }
        vector<int> out;
        for (int i = 0; i < n; i++) {
                pair<int, int> p1 = part[ans[i]];
                pair<int, int> p2 = part[ans[i + 1]];
                out.push_back(toIndex[make_pair(p1.first + p2.first, p1.second + p2.second)]);
                if (out[i] == 0) {
                        out.clear();
                        break;
                }
        }
        if (out.empty()) {
                return false;
        }
        else {
                cout << "YES" << "\n";
                for (int i = 0; i < n; i++) {
                        cout << out[i] << " ";
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
                if (!solve()) {
                        cout << "NO" << "\n";
                }
        }
}