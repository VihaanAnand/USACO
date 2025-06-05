#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n;
        cin >> n;
        vector<vector<int>> monsters(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
                cin >> monsters[i][0] >> monsters[i][1];
        }
        if (n == 1) {
                cout << "1\n";
                return;
        }
        if (n == 2) {
                cout << "2\n";
                return;
        }
        long long mincost = 1000000002000000001;
        vector<int> topleft, bottomright;
        long long cost, height, width;
        for (int i = 0; i < n; i++) {
                topleft = {1000000001, 1000000001};
                for (int j = 0; j < n; j++) {
                        if (monsters[j] == monsters[i]) {
                                continue;
                        }
                        if (monsters[j][0] < topleft[0]) {
                                topleft[0] = monsters[j][0];
                        }
                        if (monsters[j][1] < topleft[1]) {
                                topleft[1] = monsters[j][1];
                        }
                }
                bottomright = {-1000000001, -1000000001};
                for (int j = 0; j < n; j++) {
                        if (monsters[j] == monsters[i]) {
                                continue;
                        }
                        if (monsters[j][0] > bottomright[0]) {
                                bottomright[0] = monsters[j][0];
                        }
                        if (monsters[j][1] > bottomright[1]) {
                                bottomright[1] = monsters[j][1];
                        }
                }
                width = bottomright[0] - topleft[0] + 1;
                height = bottomright[1] - topleft[1] + 1;
                cost = (long long) width * height;
                if (cost == n - 1) {
                        if (width < height) {
                                cost += width;
                        }
                        else {
                                cost += height;
                        }
                }
                if (cost < mincost) {
                        mincost = cost;
                }
        }
        cout << mincost << "\n";
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