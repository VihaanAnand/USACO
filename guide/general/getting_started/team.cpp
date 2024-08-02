#include <iostream>
using namespace std;
int main() {
        int tests;
        cin >> tests;
        int total = 0;
        for (int i = 0; i < tests; i++) {
                int a, b, c;
                cin >> a >> b >> c;
                if ((a + b + c) >= 2) {
                        total++;
                }
        }
        cout << total;
}