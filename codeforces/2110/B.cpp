#include <iostream>
using namespace std;
bool solve() {
        string s;
        cin >> s;
        int n = s.size();
        int bal = 0;
        for (int i = 1; i + 1 < n; i++) {
                if (s[i] == '(') {
                        bal++;
                }
                else {
                        bal--;
                }
                if (bal < 0) {
                        return true;
                }
        }
        return bal != 0;
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                if (solve()) {
                        cout << "YES\n";
                }
                else {
                        cout << "NO\n";
                }
        }
}