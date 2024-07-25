/*
ID: macos141
TASK: ride
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
        ofstream fout ("ride.out");
        ifstream fin ("ride.in");
        string comet;
        string group;
        fin >> comet;
        fin >> group;
        long long cometval = 1, groupval = 1;
        for (int i = 0; i < comet.size(); i++) {
                int letter = comet[i];
                letter -= 64;
                cometval *= letter;
        }
        for (int i = 0; i < group.size(); i++) {
                int letter = group[i];
                letter -= 64;
                groupval *= letter;
        }
        cometval %= 47;
        groupval %= 47;
        if (cometval == groupval) {
                fout << "GO\n";
        }
        else {
                fout << "STAY\n";
        }
        return 0;
}