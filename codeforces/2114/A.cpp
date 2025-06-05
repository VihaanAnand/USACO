#include <iostream>
using namespace std;
void solve() {
        int number;
        cin >> number;
        if (number == 0) {
                cout << "0 0\n";
                return;
        }
        int root = (int) sqrt(number);
        if (root * root == number) {
                cout << "1 " << root - 1 << "\n";
        }
        else {
                cout << "-1\n";
        }
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--) {
                solve();
        }
}