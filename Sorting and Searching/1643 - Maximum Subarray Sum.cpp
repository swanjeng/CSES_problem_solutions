#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <long long> a(n);
    for (long long &x : a) cin >> x;
    long long ans = (long long) -1e15, curr = 0;
    for (int i = 0; i < n; i++) {
        curr = max(curr + a[i], a[i]);
        ans = max(ans, curr);
    }
    cout << ans;
    return 0;
}