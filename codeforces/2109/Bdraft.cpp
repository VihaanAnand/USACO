#include <iostream>
#include <vector>
using namespace std;
vector<int> mouf(int n, int m, int a, int b) {
        float n_mid = (n + 1) / 2.0;
        float m_mid = (m + 1) / 2.0;
        int squares;
        vector<int> result(4);
        if (a <= n_mid) {
                result = {a, m, a, b};
                squares = a * m;
        }
        else {
                result = {n - a + 1, m, 1, b};
                squares = (n - a + 1) * m;
        }
        if (b <= m_mid) {
                if (n * b < squares) {
                        result = {n, b, a, b};
                }
        }
        else {
                if (n * (m - b + 1) < squares) {
                        result = {n, m - b + 1, a, 1};
                }
        }
        return result;
}
vector<int> fouad(int n, int m, int a, int b) {
        int n_mid = (n + 1) / 2;
        int m_mid = (m + 1) / 2;
        vector<int> result(4);
        result = {n, m, n_mid, m_mid};
        return result;
}
void solve() {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        float ans = 0;
        bool turn = true;
        while (n >= 2 || m >= 2) {
                vector<int> result;
                if (turn) {
                        result = mouf(n, m, a, b);
                }
                else {
                        result = fouad(n, m, a, b);
                }
                ans += 0.5;
                n = result[0];
                m = result[1];
                a = result[2];
                b = result[3];
                turn = !turn;
        }
        int answer = (int) ans;
        answer++;
        cout << answer << "\n";
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