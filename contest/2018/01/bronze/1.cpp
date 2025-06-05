#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
        ifstream fin("teleport.in");
        ofstream fout("teleport.out");
        int a, b, x, y;
        fin >> a >> b >> x >> y;
        int difference1 = abs(a - b);
        int difference2 = abs(a - x) + abs(b - y);
        int difference3 = abs(a - y) + abs(b - x);
        if (difference1 <= difference2 && difference1 <= difference3) {
                fout << difference1;
        }
        else if (difference2 <= difference1 && difference2 <= difference3) {
                fout << difference2;
        }
        else if (difference3 <= difference1 && difference3 <= difference2) {
                fout << difference3;
        }
        else {
                fout << difference1;
        }
}