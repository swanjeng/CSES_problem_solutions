#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, a, b, curr = 0, ans = 0;
    cin >> n;
    vector <pair <int, int>> events;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        events.push_back({ a, 1 });
        events.push_back({ b, -1 });
    }
    sort(events.begin(), events.end());
    for (auto e : events) {
        curr += e.second;
        ans = max(ans, curr);
    }
    cout << ans;
    return 0;
}