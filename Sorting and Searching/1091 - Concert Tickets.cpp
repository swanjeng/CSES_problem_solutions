#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    multiset <int> prices;
    int price;
    for (int i = 0; i < n; i++) {
        cin >> price;
        prices.insert(price);
    }

    int expected;
    for (int i = 0; i < m; i++) {
        cin >> expected;
        auto it = prices.upper_bound(expected);
        if (it == prices.begin()) {
            cout << "-1\n";
            continue;
        } else {
            it--;
            cout << *it << "\n";
            prices.erase(it);
        }
    }
    return 0;
}