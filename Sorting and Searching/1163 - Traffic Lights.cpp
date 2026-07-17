#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m, x;
    cin >> n >> m;
    set <int> st{ 0, n };
    multiset <int> di{ n };
    for (int i = 0; i < m; i++) {
        cin >> x;
        auto it = st.insert(x).first; // .first is the iterator of the inserted x
        di.erase(di.find(*next(it) - *prev(it)));
        di.insert(*next(it) - x);
        di.insert(x - *prev(it));
        cout << *(prev(di.end())) << " ";
    }
    return 0;
}