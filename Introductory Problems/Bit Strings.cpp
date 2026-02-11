#include <iostream>
#define LL long long
#define M 1000000007
using namespace std;
LL fast_pow_mod(LL a, LL b) {
    if (b == 0) return 1;
    if (b == 1) return a % M;
    if (b % 2 == 1) return (fp(a, b-1) % M * (a % M)) % M;
    else {
        LL t = fp(a, b/2)%M;
        return t*t%M;
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    LL n;
    cin >> n;
    cout << fast_pow_mod(2, n);
    return 0;
}
