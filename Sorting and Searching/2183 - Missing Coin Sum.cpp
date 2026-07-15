#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <long long> a(n);
    for (long long& x : a) cin >> x;
    sort(a.begin(), a.end());
    long long al = 0;
    bool found = 0;
    for (long long coin : a) {
        // if the coin is greater than the current sum + 1
        // then the coin value al + 1 is impossible
        if (coin > al + 1) {
            found = 1;
            cout << al + 1 << "\n";
            break;
        } else al += coin;
    }
    if (!found) cout << al + 1 << "\n";
    return 0;
}