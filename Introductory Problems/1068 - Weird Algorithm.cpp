#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    long long a; // the calculation process may exceed 2^31
    cin >> a;
    while (a > 1) {
        cout << a << " ";
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = a * 3 + 1;
        }
    }
    cout << "1\n";
    return 0;
}
