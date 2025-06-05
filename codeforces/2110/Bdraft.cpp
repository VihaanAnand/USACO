#include <iostream>
using namespace std;
bool solve() {
        string s;
        cin >> s;
        int n = s.length();
        if (n == 0) {
                return false;
        }
        int k = n / 2;
        bool symmetrical = true;
        for (int i = 0; i < k; i++) {
                if (s[i] != '(') {
                        symmetrical = false;
                        break;
                }
        }
        for (int i = k; i < n; i++) {
                if (s[i] != ')') {
                        symmetrical = false;
                        break;
                }
        }
        if (symmetrical) {
                return false;
        }
        else {
                
        }
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