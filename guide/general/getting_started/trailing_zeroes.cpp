#include <iostream>
using namespace std;
int main() {
        long long num;
        cin >> num;
        long long total = 0;
        for (long long divnum = num; divnum > 0; total += divnum) {
                divnum /= 5;
        }
        cout << total;
}