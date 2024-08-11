#include <iostream>
#include <vector>
using namespace std;
int main() {
        long long n;
        cin >> n;
        long long total_sum = n * (n + 1) / 2;
        if (total_sum % 2 != 0) {
                cout << "NO";
        }
        else {
                cout << "YES\n";
                vector<int> set1, set2;
                long long target_sum = total_sum / 2;
                for (int i = n; i > 0; i--) {
                        if (target_sum >= i) {
                                set1.push_back(i);
                                target_sum -= i;
                        }
                        else {
                                set2.push_back(i);
                        }
                }
                cout << set1.size() << "\n";
                for (int x : set1) {
                        cout << x << " ";
                }
                cout << "\n" << set2.size() << "\n";
                for (int x : set2) {
                        cout << x << " ";
                }
        }
}