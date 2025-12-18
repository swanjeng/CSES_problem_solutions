#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    long long n, ans = 0;
    cin >> n;
    vector <long long> arr(n);
    cin >> arr[0];
    for (int i = 1 ; i < n ; i ++) {
        cin >> arr[i];
        if (arr[i] < arr[i-1]) {
            ans += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout << ans << "\n";
    return 0;
}
