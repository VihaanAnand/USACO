#include <iostream>
using namespace std;
int main() {
        int perbanana, dollars, bananas;
        cin >> perbanana >> dollars >> bananas;
        int total = bananas * (bananas + 1) / 2 * perbanana;
        if (total > dollars) {
                cout << (total - dollars);
        }
        else {
                cout << 0;
        }
}