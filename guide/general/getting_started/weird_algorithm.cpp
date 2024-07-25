#include <iostream>
using namespace std;
int main() {
        long long num;
        cin >> num;
        while (num != 1) {
                cout << num << " ";
                if (num % 2 == 0) {
                        num /= 2;
                }
                else {
                        num *= 3;
                        num += 1;
                }
        }
        cout << 1;
}