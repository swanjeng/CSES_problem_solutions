#include <iostream>
#include <vector>
using namespace std;
int used[9], ans = 0;
vector <int> d;
vector <string> a(8);

// Recursive enumeration
void dfs(int idx) {
    if (idx == 8) {
        ans ++;
        return;
    }
    for (int i = 0 ; i < 8 ; i ++) {
        if (a[i][idx] == '*' || used[i]) continue;
        int f = 1;
        for (int j = 0 ; j < idx ; j ++) {
            if (abs(d[j] - i) == abs(j - idx)) { // check if there is a queen in the same diagonal
                f = 0;
                break;
            }
        }
        if (f) {
            d.push_back(i);
            used[i] = 1;
            dfs(idx + 1);
            used[i] = 0;
            d.pop_back();
        }
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    for (string& s : a) cin >> s;
    dfs(0);
    cout << ans << "\n";
    return 0;
}
