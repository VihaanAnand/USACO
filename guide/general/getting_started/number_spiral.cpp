#include <iostream>
using namespace std;
int main() {
        long long tests;
        cin >> tests;
        for (long long i = 0; i < tests; i++) {
                long long x, y;
                cin >> y >> x;
                long long answer;
                if (x > y) {
                        answer = (x - 1) * (x - 1);
                        if (x % 2 == 0) {
                                answer += y;
                        }
                        else {
                                answer += (2 * x - y);
                        }
                }
                else {
                        answer = (y - 1) * (y - 1);
                        if (y % 2 == 0) {
                                answer += (2 * y - x);
                        }
                        else {
                                answer += x;
                        }
                }
                cout << answer << "\n";
        }
}