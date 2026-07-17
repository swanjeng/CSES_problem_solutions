#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int& x : a) cin >> x;

    // sliding window
    int r = 0, ans = 0;
    set <int> st;
    for (int l = 0; l < n; l++) {
        while (r < n && !st.count(a[r])) {
            st.insert(a[r]);
            r++;
        }
        ans = max(ans, (int)st.size());
        st.erase(a[l]);
    }
    cout << ans;
    return 0;
}