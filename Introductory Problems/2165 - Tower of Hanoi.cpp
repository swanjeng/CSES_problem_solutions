#include <iostream>
#include <vector>
using namespace std;
vector <pair <int, int>> ans;
void move(int n, int from, int to) {
    if (n == 1) {
        ans.push_back({from, to});
        return;
    }
    // 6-from-to is the stick other than 'from' and 'to'
    move(n - 1, from, 6 - from - to);
    ans.push_back({from, to});
    move(n - 1, 6 - from - to, to);
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    move(n, 1, 3);
    cout << ans.size() << "\n";
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
    return 0;
}
