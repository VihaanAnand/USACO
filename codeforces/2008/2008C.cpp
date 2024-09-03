#include <iostream>
using namespace std;
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int tests;
        cin >> tests;
        for (int i = 0; i < tests; i++) {
                int min, max;
                cin >> min >> max;
                int curnum = min, length = 1;
                while ((curnum + length) <= max) {
                        curnum += length;
                        length++;
                }
                cout << length << "\n";
        }
}