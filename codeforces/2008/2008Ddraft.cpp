#include <iostream>
#include <vector>
using namespace std;
bool is_reachable(int a, int b, const vector<int> &permutation) {
        int a_orig = a;
        while (a != b) {
                a = permutation[a - 1];
                if (a == a_orig) {
                        return false;
                }
                if (a == b) {
                        return true;
                }
        }
        return true;
}
int F(int i, const vector<int> &permutation, const vector<char> &blacks) {
        int answer = 0;
        for (int j = 0; j < permutation.size(); j++) {
                if (blacks[j] == '0' && is_reachable(i, j + 1, permutation)) {
                        answer++;
                }
        }
        return answer;
}
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int tests;
        cin >> tests;
        for (int i = 0; i < tests; i++) {
                int length;
                cin >> length;
                vector<int> permutation(length);
                for (int i = 0; i < length; i++) {
                        cin >> permutation[i];
                }
                vector<char> blacks(length);
                for (int i = 0; i < length; i++) {
                        cin >> blacks[i];
                }
                for (int i = 1; i <= length; i++) {
                        cout << F(i, permutation, blacks) << " ";
                }
                cout << "\n";
        }
}