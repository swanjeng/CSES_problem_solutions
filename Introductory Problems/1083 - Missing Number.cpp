#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    long long n, input, curr = 0;
    cin >> n;
    for (int i = 1 ; i < n ; i ++) {  // n - 1 numbers
        cin >> input;
        curr += input;
    }
    // 1 + 2 + ... + n = n(n + 1) / 2
    cout << (n*(n+1)/2 - curr);
    return 0;
}
