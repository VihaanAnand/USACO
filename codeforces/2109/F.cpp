#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool in(int i, int j, int n) {
        return (0 <= i && i < n && 0 <= j && j < n);
}
void run(int i, int j, array<int, 8> &dx, array<int, 8> &dy, int n, vector<vector<int>> &dont, vector<vector<int>> &a, int mouf) {
        for (int dir = 0; dir < 8; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (in(ni, nj, n) && dont[ni][nj] == 0) {
                        dont[ni][nj] = 1;
                        if (a[ni][nj] > mouf) {
                                run(ni, nj, dx, dy, n, dont, a, mouf);
                        }
                }
        }
}
void solve() {
        array<int, 8> dx{0, 0, 1, -1, 1, 1, -1, -1};
        array<int, 8> dy{1, -1, 0, 0, -1, 1, -1, 1};
        int n, r, k;
        cin >> n >> r >> k;
        r--;
        vector a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }
        vector b(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
                string s;
                cin >> s;
                for (int j = 0; j < n; j++) {
                        b[i][j] = s[j] - '0';
                }
        }
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({a[0][0], 0, 0});
        vector dis(n, vector<int>(n, 1000000000));
        dis[0][0] = a[0][0];
        while (pq.size()) {
                array<int, 3> top = pq.top();
                int mx = top[0];
                int i = top[1];
                int j = top[2];
                pq.pop();
                if (dis[i][j] != mx) {
                        continue;
                }
                for (int dir = 0; dir < 4; dir++) {
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if (in(ni, nj, n) && dis[ni][nj] > max(mx, a[ni][nj])) {
                                int nmx = max(mx, a[ni][nj]);
                                dis[ni][nj] = nmx;
                                pq.push({nmx, ni, nj});
                        }
                }
        }
        int mouf = dis[r][n - 1];
        vector dont(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
                dont[0][j] = 1;
                if (a[0][j] > mouf) {
                        run(0, j, dx, dy, n, dont, a, mouf);
                }
        }
        for (int i = 0; i <= r; i++) {
                dont[i][n - 1] = 1;
                if (a[i][n - 1] > mouf) {
                        run(i, n - 1, dx, dy, n, dont, a, mouf);
                }
        }
        int L = 1, R = 2000000;
        while (L <= R) {
                int mid = (L + R) / 2;
                for (int j = 0; j < n; j++) {
                        if ((mid > mouf && dont[n - 1][j]) || (mid > a[n - 1][j] && b[n - 1][j] == 0)) {
                                continue;
                        }
                        pq.push({max(0, mid - a[n - 1][j]), n - 1, j});
                }
                for (int i = r; i < n; i++) {
                        if ((mid > mouf && dont[i][n - 1]) || (mid > a[i][n - 1] && b[i][n - 1] == 0)) {
                                continue;
                        }
                        pq.push({max(0, mid - a[i][n - 1]), i, n - 1});
                }
                fill(dis.begin(), dis.end(), vector<int>(n, 1000000000));
                while (pq.size()) {
                        array<int, 3> top = pq.top();
                        int cost = top[0];
                        int i = top[1];
                        int j = top[2];
                        pq.pop();
                        dis[i][j] = min(dis[i][j], cost);
                        if (dis[i][j] != cost) {
                                continue;
                        }
                        for (int dir = 0; dir < 8; dir++) {
                                int ni = i + dx[dir];
                                int nj = j + dy[dir];
                                if (in(ni, nj, n)) {
                                        if ((mid > mouf && dont[ni][nj]) || (mid > a[ni][nj] && b[ni][nj] == 0)) {
                                                continue;
                                        }
                                        if (dis[ni][nj] > cost + max(0, mid - a[ni][nj])) {
                                                int ncost = cost + max(0, mid - a[ni][nj]);
                                                dis[ni][nj] = ncost;
                                                pq.push({ncost, ni, nj});
                                        }
                                }
                        }
                }
                int minCost = 1000000000;
                if (mid <= mouf) {
                        for (int j = 0; j < n; j++) {
                                minCost = min(minCost, dis[0][j]);
                        }
                        for (int i = 0; i <= r; i++) {
                                minCost = min(minCost, dis[i][n - 1]);
                        }
                }
                for (int i = 1; i < n; i++) {
                        minCost = min(minCost, dis[i][0]);
                }
                if (minCost <= k) {
                        L = mid + 1;
                }
                else {
                        R = mid - 1;
                }
        }
        cout << mouf << " " << R << "\n";
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