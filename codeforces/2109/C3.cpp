#include <iostream>
using namespace std;
int issue_command(string command) {
        cout << command << "\n";
        cout.flush();
        int a;
        cin >> a;
        return a;
}
void solve() {
        int n;
        cin >> n;
        int a;
        a = issue_command("mul 999999999");
        a = issue_command("digit");
        if (n != 81) {
                a = issue_command("add " + to_string(n - 81));
        }
        a = issue_command("!");
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