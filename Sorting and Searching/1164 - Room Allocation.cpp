#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair <int, int> a, pair <int, int> b) {
    if (abs(a.second) != abs(b.second)) return abs(a.second) < abs(b.second);
    else return a.second > b.second;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    vector <int> ans(n), free_rooms;
    vector <pair <int, int>> events;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        events.push_back({ i, a });
        events.push_back({ i, -b });
    }
    sort(events.begin(), events.end(), cmp);

    int curr = 0, k = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (events[i].second > 0) {
            curr++;
            if (free_rooms.size()) {
                ans[events[i].first] = free_rooms.back();
                free_rooms.pop_back();
            } else {
                ans[events[i].first] = curr;
            }
        } else {
            curr--;
            free_rooms.push_back(ans[events[i].first]);
        }
        k = max(k, curr);
    }

    cout << k << "\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
    return 0;
}
