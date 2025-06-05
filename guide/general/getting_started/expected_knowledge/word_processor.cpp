#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main() {
        ifstream fin("word.in");
        ofstream fout("word.out");
        int words, maxlength;
        fin >> words >> maxlength;
        vector<string> text;
        for (int i = 0; i < words; i++) {
                string word;
                fin >> word;
                text.push_back(word);
        }
        int len = 0;
        for (int i = 0; i < words; i++) {
                if (len + text[i].size() <= maxlength) {
                        if (len != 0) {
                                fout << " ";
                        }
                        fout << text[i];
                        len += text[i].size();
                }
                else {
                        fout << "\n" << text[i];
                        len = text[i].size();
                }
        }
}