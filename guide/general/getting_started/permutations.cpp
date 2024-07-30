#include <iostream>
using namespace std;
int main() {
        int n;
        cin >> n;
        if (n == 2 || n == 3) {
                cout << "NO SOLUTION";
                return 0;
        }
        else if (n == 1) {
                cout << 1;
        }
        else if (n == 4) {
                cout << "2 4 1 3";
        }
        else if (n % 2 == 1) {
                for (int i = 1; i <= n; i += 2) {
                        cout << i << " ";
                }
                for (int i = 2; i <= (n - 3); i += 2) {
                        cout << i << " ";
                }
                cout << n - 1;
        }
        else {
                for (int i = 1; i <= (n - 1); i += 2) {
                        cout << i << " ";
                }
                for (int i = 2; i <= (n - 2); i += 2) {
                        cout << i << " ";
                }
                cout << n;
        }
}