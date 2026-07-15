#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int& x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    long long ans = 0;
    int median = arr[n / 2];
    for (int x : arr) ans += abs(x - median);
    cout << ans;
    return 0;
}