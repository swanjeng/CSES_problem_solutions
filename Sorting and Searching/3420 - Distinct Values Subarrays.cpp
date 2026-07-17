#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    
    set <int> st;
    int r = 0;
    long long ans = 0;
    for (int l = 0 ; l < n ; l ++) {
        while (r < n && !st.count(a[r])) {
            st.insert(a[r]);
            r++;
        }
        // there are r - l subarrays whose left bound is l
        // and all of them have distinct values
        ans += r - l;
        st.erase(a[l]);
    }
    cout << ans << "\n";
    return 0;
}