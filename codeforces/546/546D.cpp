#include <iostream>
using namespace std;
int main() {
        // ios_base::sync_with_stdio(false);
        // cin.tie(0);
        int tests;
        cin >> tests;
        for (int i = 0; i < tests; i++) {
                long long a, b;
                cin >> a >> b;
                int score = 0;
                for (long long n = a; n > b; n--) {
                        long long temp = n;
                        while (n > 1) {
                                int div;
                                for (div = 2; div <= n; div++) {
                                        if (n % div == 0) {
                                                break;
                                        }
                                }
                                n /= div;
                                score++;
                        }
                        n = temp;
                }
                cout << score << "\n";
        }
}