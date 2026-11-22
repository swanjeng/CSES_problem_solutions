#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    long long n, x, max_time = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        max_time = max(max_time, x);
    }
    cout << max(max_time * 2, sum) << "\n";
}