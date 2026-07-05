#include <iostream>
#include <vector>
using namespace std;
long long ans = 1e11;
// recursive enumeration
void dfs(vector <int> &a, int n, long long sum, long long curr, int idx) {
    if (idx == n) ans = min(ans, abs(sum - curr - curr));
    else {
        // select a[idx]
        dfs(a, n, sum, curr + a[idx], idx + 1);

        // skip a[idx]
        dfs(a, n, sum, curr, idx + 1);
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    long long sum = 0;
    for (int &x : a) {
        cin >> x;
        sum += x;
    }
    dfs(a, n, sum, 0, 0);
    cout << ans << "\n";
    return 0;
}
