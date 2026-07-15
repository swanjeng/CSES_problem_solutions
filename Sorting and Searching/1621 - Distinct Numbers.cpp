#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    
    // Use `set` to remove repeated numbers.
    set <int> s; int n, x;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
    return 0;
}
