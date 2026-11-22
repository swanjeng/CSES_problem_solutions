#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair <int, int> a, pair <int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    long long t = 0, ans = 0;
    cin >> n;
    vector <pair <int, int>> arr(n);
    for (auto &p : arr) cin >> p.first >> p.second;
    sort(arr.begin(), arr.end(), cmp);
    for (auto p : arr) {
        t += p.first;
        ans += (p.second - t);
    }
    cout << ans;
    return 0;
}