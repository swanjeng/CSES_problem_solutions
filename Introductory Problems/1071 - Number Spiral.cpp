#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T --) {
        long long y, x;
        cin >> y >> x;
        // a number with position (x, x)
        // equals to (x ^ 2 - x + 1)
        long long y1 = y * y - y + 1;
        long long x1 = x * x - x + 1;
        if (y == x) {
            cout << y1;
        } else if (y > x) {
            // the bottom-left triangle
            if (y % 2 == 0) {
                cout << y1 + (y - x);
            } else {
                cout << y1 - (y - x);
            }
        } else {
            // the upper-right triangle
            if (x % 2 == 0) {
                cout << x1 - (x - y);
            } else {
                cout << x1 + (x - y);
            }
        }
        cout << "\n";
    }
    return 0;
}
