#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;
bool cmp(pair <LL, LL> a, pair <LL, LL> b) {
    return a.second < b.second;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    LL n, x;
    cin >> n >> x;
    vector <pair <LL, LL>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].first = i + 1;
        cin >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    bool possible = 0;
    for (int i = 0; i < n; i++) {
        pair <LL, LL> rem = { 0, x - a[i].second };
        pair <LL, LL> candidate = *lower_bound(a.begin(), a.end(), rem, cmp);
        if (candidate.first != a[i].first && candidate.second == rem.second) {
            possible = 1;
            cout << a[i].first << " " << candidate.first << "\n";
            break;
        }
    }
    if (!possible) cout << "IMPOSSIBLE\n";
    return 0;
}