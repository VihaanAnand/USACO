#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
        int num;
        cin >> num;
        vector<bool> missing(num, true); 
        for (int i = 0; i < num; i++) {
                int number;
                cin >> number;
                missing[number - 1] = false;
        }
        for (int i = 0; i < num; i++) {
                if (missing[i] == true) {
                        cout << i + 1;
                        return 0;
                }
        }
}