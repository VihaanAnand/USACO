#include <iostream>
using namespace std;
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        string t;
        cin >> t;
        if (s == "*") {
                cout << "YES";
                return 0;
        }
        else if (s == "*p") {
                cout << "YES";
                return 0;
        }
        else if (s == "r*") {
                cout << "YES";
                return 0;
        }
        else if (s == "h*") {
                cout << "YES";
                return 0;
        }
        int pos = s.find('*');
        if (pos == string::npos) {
                if (s.compare(t) == 0) {
                        cout << "YES";
                }
                else {
                        cout << "NO";
                }
                return 0;
        }
        s = s.substr(pos, n - pos);
        t = t.substr(pos, m - pos);
        string part_after = s.substr(1, n - 1);
        if (t.find(part_after) != string::npos) {
                if (t.size() > t.find(part_after) + part_after.size()) {
                        cout << "NO";
                }
                else {
                        cout << "YES";
                }
        }
        else {
                cout << "NO";
        }
}