/*
ID: macos141
TASK: beads
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main() {
        ifstream fin ("beads.in");
        ofstream fout ("beads.out");
        int length;
        fin >> length;
        vector<char> necklace(length);
        for (int i = 0; i < length; i++) {
                fin >> necklace[i];
        }
        int answer = 0;
        for (int i = 0; i < length; i++) {
                int cur_test = 0;
                int left = (i - 1 + length) % length;
                char colour_left = necklace[left];
                while (cur_test < length && (necklace[left] == colour_left || necklace[left] == 'w' || colour_left == 'w')) {
                        cur_test++;
                        if (colour_left == 'w' && necklace[left] != 'w') {
                                colour_left = necklace[left];
                        }
                        left = (left - 1 + length) % length;
                }
                int right = i;
                char colour_right = necklace[right];
                while (cur_test < length && (necklace[right] == colour_right || necklace[right] == 'w' || colour_right == 'w')) {
                        cur_test++;
                        if (colour_right == 'w' && necklace[right] != 'w') {
                                colour_right = necklace[right];
                        }
                        right = (right + 1) % length;
                }
                answer = max(answer, cur_test);
        }
        fout << min(answer, length) << "\n";
        return 0;
}