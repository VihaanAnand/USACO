#include <iostream>
#include <vector>
using namespace std;
void solve() {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; i++) {
                cin >> array[i];
        }
        vector<int> newarr;
        newarr.push_back(array[0]);
        int elem;
        int index = 1;
        for (int i = 1; i < n; i++) {
                if (array[i] > newarr[index - 1] + 1) {
                        newarr.push_back(array[i]);
                        index++;
                }
        }
        cout << index << "\n";
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