#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
        ifstream fin("buckets.in");
        ofstream fout("buckets.out");
        int bx, by, lx, ly, rx, ry;
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        char letter;
                        fin >> letter;
                        if (letter == 'B') {
                                bx = j;
                                by = i;
                        }
                        else if (letter == 'L') {
                                lx = j;
                                ly = i;
                        }
                        else if (letter == 'R') {
                                rx = j;
                                ry = i;
                        }
                }
        }
        int answer = abs(bx - lx) + abs(by - ly) - 1;
        if ((by == ly && ly == ry && rx > min(bx, lx) && rx < max(bx, lx)) || (bx == lx && lx == rx && ry > min(by, ly) && ry < max(by, ly))) {
                answer += 2;
        }
        fout << answer;
}