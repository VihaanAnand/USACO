#include <iostream>
#include <vector>
using namespace std;
int main() {
        int length;
        cin >> length;
        vector<int> array;
        for (int i = 0; i < length; i++) {
                int number;
                cin >> number;
                array.push_back(number);
        }
        long long total = 0;
        for (int i = 1; i < length; i++) {
                if (array[i] < array[i - 1]) {
                        total += (array[i - 1] - array[i]);
                        array[i] += (array[i - 1] - array[i]);
                }
        }
        cout << total;
}