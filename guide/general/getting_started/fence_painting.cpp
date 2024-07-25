#include <fstream>
#include <iostream>
using namespace std;
int main() {
        ifstream fin("paint.in");
        ofstream fout("paint.out");
        int a, b, c, d;
        fin >> a >> b;
        fin >> c >> d;
        int sum;
        if (c > b || d < a) {
                sum = (b - a) + (d - c);
        }
        else {
                int start = min(a, c);
                int end = max(b, d);
                sum = end - start;
        }
        fout << sum;
        return 0;
}