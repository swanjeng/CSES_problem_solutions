#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n --) {
        long long a, b;
        cin >> a >> b;
      
        // Krama's formula
        // 2x + y = b
        // x + 2y = a
        long long d = 3, dx = 2 * b - a, dy = 2 * a - b;
        if (dx >= 0 && dx % d == 0 && dy >= 0 && dy % d == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
