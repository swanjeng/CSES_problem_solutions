#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200002;
int weights[MAXN];
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    int ans = 0, left = 0, right = n - 1;
    for (int i = 0; i < n; i++) cin >> weights[i];
    sort(weights, weights + n);
    while (left <= right) {
        if (left == right) {
            ans++;
            break;
        }
        if (weights[left] + weights[right] <= x) {
            ans++;
            left++;
            right--;
        } else {
            ans++;
            right--;
        }
    }
    cout << ans << "\n";
    return 0;
}