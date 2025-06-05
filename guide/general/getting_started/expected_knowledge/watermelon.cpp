#include <iostream>
using namespace std;
int main() {
        int mass;
        cin >> mass;
        if (mass % 2 == 0 && mass >= 4) {
                cout << "YES";
        }
        else {
                cout << "NO";
        }
}