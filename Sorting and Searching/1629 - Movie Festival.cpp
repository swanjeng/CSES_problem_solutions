#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, t = 0, ans = 0;
    cin >> n;
    vector <pair <int, int>> arr(n);
    for (auto& p : arr) cin >> p.first >> p.second;
    // Sort by end time
    sort(arr.begin(), arr.end(), cmp);
    for (auto p : arr) {
        if (t <= p.first) {
            ans++;
            t = p.second;
        }
    }
    cout << ans;
    return 0;
}