#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, cnt = 0;
    cin >> n;
    while (n > 0) {
        // calculate how many factor '5's are in n! .
        // 10 = 2 * 5, factor 2s are always more than factor 5s.
        cnt += n / 5;
        n /= 5;
    }
    cout << cnt;
}
