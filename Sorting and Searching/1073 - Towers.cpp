#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, x;
    cin >> n;
    multiset <int> a;
    for (int i = 0; i < n; i++) {
        cin >> x;
        // find the smallest cube bigger than x
        auto it = a.upper_bound(x);
        a.insert(x);
        // if found, remove the cube since x is stacked on it
        if (it != a.end()) a.erase(it);
    }
    cout << a.size();
    return 0;
}