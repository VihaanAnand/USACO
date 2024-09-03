#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        long long tests;
        cin >> tests;
        for (long long i = 0; i < tests; i++) {
                vector<long long> array;
                long long length;
                cin >> length;
                for (long long i = 0; i < length; i++) {
                        long long element;
                        cin >> element;
                        array.push_back(element);
                }
                double answer = 0;
                for (long long i = 0; i < length; i++) {
                        for (long long j = 0; j < length; j++) {
                                if (i == j) {
                                        continue;
                                }
                                answer += array[i] * array[j];
                        }
                }
                answer /= 2;
                answer /= (length * (length - 1) / 2);
                const long long precision = 1e9;
                long long q = precision;
                long long p = static_cast<long long>(answer * precision);
                long long a = p, b = q;
                while (b != 0) {
                        long long temp = b;
                        b = a % b;
                        a = temp;
                }
                long long gcd = a;
                p /= gcd;
                q /= gcd;
                long long base = q;
                long long exponent = 1000000007 - q;
                long long mod = 1000000007;
                long long result = 1;
                while (exponent > 0) {
                        if (exponent % 2 == 1) {
                                result = (result * base) % mod;
                        }
                        base = (base * base) % mod;
                        exponent /= 2;
                }
                q = result;
                long long final = p * q;
                final %= 1000000007;
                cout << final << "\n";
        }
}