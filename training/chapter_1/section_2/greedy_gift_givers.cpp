/*
ID: macos141
TASK: gift1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int personid(string person, vector<string> ppl) {
        int id = 0;
        for (string i : ppl) {
                if (i.compare(person) == 0) {
                        return id;
                }
                id++;
        }
        return 0;
}
int main() {
        ifstream fin ("gift1.in");
        ofstream fout ("gift1.out");
        int np;
        fin >> np;
        vector<string> ppl;
        for (int i = 0; i < np; i++) {
                string name;
                fin >> name;
                ppl.push_back(name);
        }
        vector<int> money;
        for (int i = 0; i < np; i++) {
                money.push_back(0);
        }
        for (int i = 0; i < np; i++) {
                string person;
                fin >> person;
                int id = personid(person, ppl);
                int gift, noppl;
                fin >> gift >> noppl;
                money[id] -= gift;
                if (noppl == 0) {
                        continue;
                }
                int giftpp = gift / noppl;
                int rem = gift % noppl;
                money[id] += rem;
                for (int j = 0; j < noppl; j++) {
                        fin >> person;
                        id = personid(person, ppl);
                        money[id] += giftpp;
                }
        }
        for (int i = 0; i < np; i++) {
                fout << ppl[i] << " " << money[i] << "\n";
        }
}