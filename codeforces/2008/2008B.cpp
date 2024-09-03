#include <iostream>
using namespace std;
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int tests;
        cin >> tests;
        for (int i = 0; i < tests; i++) {
                int length;
                cin >> length;
                string beau;
                cin >> beau;
                if (beau == "1111") {
                        cout << "Yes\n";
                        continue;
                }
                int sidelength = 0;
                while (sidelength < beau.length() && beau[sidelength] == '1') {
                        sidelength++;
                }
                int area = (sidelength - 1) * (sidelength - 1);
                if (length != area) {
                        cout << "No\n";
                }
                else {
                        cout << "Yes\n";
                }
        }
}