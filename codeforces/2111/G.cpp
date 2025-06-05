#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct solver {
        int n;
        vector<int> p;
        solver(const vector<int> &p_in) {
                p = p_in;
                n = p.size();
                build();
        }
        vector<int> nxtmn, nxtmx;
        vector<vector<int>> up;
        vector<vector<int>> mx;
        void build() {
                nxtmx.resize(n);
                vector<int> stmn, stmx;
                for (int i = n - 1; i >= 0; i--) {
                        while (!stmx.empty() && p[stmx.back()] < p[i]) {
                                stmx.pop_back();
                        }
                        if (stmx.empty()) {
                                nxtmx[i] = n;
                        }
                        else {
                                nxtmx[i] = stmx.back();
                        }
                        stmx.push_back(i);
                }
                vector<vector<int>> qr(n + 1);
                for (int i = 0; i < n; i++) qr[nxtmx[i]].push_back(i);
                nxtmn.assign(n, n);
                for (int i = n - 1; i >= 0; i--) {
                        while (!stmn.empty() && p[stmn.back()] > p[i]) {
                                stmn.pop_back();
                        }
                        stmn.push_back(i);
                        for (int var = 0; var < qr[i].size(); var++) {
                                int j = qr[i][var];
                                int l = 0, r = int(stmn.size()) - 1;
                                while (l <= r) {
                                        int m = (l + r) / 2;
                                        if (p[stmn[m]] < p[j]) {
                                                nxtmn[j] = stmn[m];
                                                l = m + 1;
                                        }
                                        else {
                                                r = m - 1;
                                        }
                                }
                        }
                }
                up.assign(n + 1, vector<int>(18));
                mx.assign(n + 1, vector<int>(18));
                for (int i = 0; i < n; i++) {
                        up[i][0] = nxtmx[i];
                        mx[i][0] = nxtmn[i];
                }
                up[n][0] = n;
                mx[n][0] = 0;
                for (int j = 1; j < 18; j++) for (int i = 0; i < n + 1; i++) {
                        up[i][j] = up[up[i][j - 1]][j - 1];
                        mx[i][j] = max(mx[i][j - 1], mx[up[i][j - 1]][j - 1]);
                }
        }
        bool query(int l, int r) {
                int v = l;
                for (int i = 17; i >= 0; i--) {
                        if (up[v][i] >= r) {
                                continue;
                        }
                        if (mx[v][i] >= r) {
                                return true;
                        }
                        v = up[v][i];
                }
                return false;
        }
};
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        vector<vector<int>> p(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
                cin >> p[0][i];
                p[0][i]--;
        }
        p[1] = p[0];
        reverse(p[1].begin(), p[1].end());
        solver p0(p[0]);
        solver p1(p[1]);
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
                if (i % 10 == 0) {
                        cout.flush();
                }
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                if (p0.query(l, r + 1) || p1.query(n - r - 1, n - l)) {
                        cout << "YES\n";
                }
                else {
                        cout << "NO\n";
                }
        }
        cout.flush();
}