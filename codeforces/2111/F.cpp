#include <iostream>
using namespace std;
void solve() {
        int p, s;
        cin >> p >> s;
        if (p > 4 * s) {
                cout << "-1\n";
                return;
        }
        if (p > 2 * s) {
                for (int i = 1; i <= 50000; i++) {
                        if (p * i == (2 + 2 * i) * s) {
                                cout << i << "\n";
                                for (int j = 0; j < i; j++) {
                                        cout << "0 " << j << "\n";
                                }
                                return;
                        }
                }
                cout << "-1\n";
                return;
        }
        int k = 0;
        while (p > 2) {
                p -= 2;
                s -= 1;
                k++;
        }
        if (p == 2) {
                cout << 4 * s * s + 4 * s * k << "\n";
                for (int i = 0; i < 2 * s; i++) {
                        for (int j = 0; j < 2 * s; j++) {
                                cout << i << " " << j << "\n";
                        }
                }
                for (int i = 0; i < 4 * s * k; i++) {
                        cout << 0 << " " << 2 * s + i << "\n";
                }
        }
        else {
                cout << 16 * s * s + 16 * s * k << "\n";
                for (int i = 0; i < 4 * s; i++) {
                        for (int j = 0; j < 4 * s; j++) {
                                cout << i << " " << j << "\n";
                        }
                }
                for (int i = 0; i < 16 * s * k; i++) {
                        cout << 0 << " " << 4 * s + i << "\n";
                }
        }
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