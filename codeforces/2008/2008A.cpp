#include <iostream>
using namespace std;
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int tests;
        cin >> tests;
        for (int i = 0; i < tests; i++) {
                int a, b;
                cin >> a >> b;
                int total_sum = a + 2 * b;
                if (total_sum % 2 != 0) {
                        cout << "NO\n";
                }
                else {
                        int target = total_sum / 2;
                        if (target % 2 == 0 || (target % 2 == 1 && a > 0)) {
                                cout << "YES\n";
                        }
                        else {
                                cout << "NO\n";
                        }
                }
        }
        return 0;
}