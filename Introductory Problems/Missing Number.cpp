#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    long long a, t, s = 0;
    cin >> a;
    for (int i = 1 ; i < a ; i ++) {
        cin >> t;
        s += t;
    }
    cout << (a*(a+1)/2 - s);
    return 0;
}
