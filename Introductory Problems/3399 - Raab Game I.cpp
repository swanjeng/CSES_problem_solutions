#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a + b > n || ((a != 0) ^ (b != 0))) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
            int tie = n - a - b;
            for (int i = 1; i <= tie; i++) cout << i << " ";
            for (int i = tie + a + 1; i <= n; i++) cout << i << " ";
            for (int i = tie + 1; i <= tie + a; i++) cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}