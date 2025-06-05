#include <iostream>
#include <vector>
using namespace std;
vector<int> connects(vector<vector<int>> edges, int vertnum) {
        vector<int> result;
        for (int i = 0; i < edges.size(); i++) {
                if (edges[i][0] == vertnum) {
                        result.push_back(edges[i][1]);
                }
                else if (edges[i][1] == vertnum) {
                        result.push_back(edges[i][0]);
                }
        }
        return result;
}
void solve() {
        int n;
        cin >> n;
        vector<int> dangers(n);
        for (int i = 0; i < n; i++) {
                cin >> dangers[i];
        }
        vector<vector<int>> edges(n - 1, vector<int>(n - 1, 2));
        for (int i = 0; i < n - 1; i++) {
                cin >> edges[i][0] >> edges[i][1];
        }
        // je ne sais pas comment résoudre ce problème (je parle aussi anglais)
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