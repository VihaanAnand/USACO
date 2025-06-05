#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n, ops;
        cin >> n >> ops;
        string s;
        cin >> s;
        vector<vector<char>> operations(ops, vector<char>(2));
        for (int i = 0; i < ops; ++i) {
                cin >> operations[i][0] >> operations[i][1];
        }
        for (int i = 0; i < ops; ++i) {
                char start = operations[i][0];
                char end = operations[i][1];
                if (end < start) {
                        for (int j = 0; j < n; ++j) {
                                if (s[j] == start) {
                                        s[j] = end;
                                        break;
                                }
                        }
                }
        }
        cout << s << "\n";
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