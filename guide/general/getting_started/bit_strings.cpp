#include <iostream>
using namespace std;
int main() {
        long long num;
        cin >> num;
        long long total = 1;
        for (int i = 0; i < num; i++) {
                total *= 2;
                total %= 1000000007;
        }
        cout << total;
}