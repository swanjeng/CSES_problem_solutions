#include <iostream>
#include <vector>
using namespace std;
int cnt[26] = {0};
vector <string> ans;
string ss = "";
// recursive enumeration
void dfs(int idx, int n) {
    if (idx == n) ans.push_back(ss); // when idx equals to n, ss.length() is also equal to n.
    else {
        for (int i = 0 ; i < 26 ; i ++) {
            if (cnt[i]) {
                ss.push_back((char) (i + 'a'));
                cnt[i] --;
                dfs(idx + 1, n);
                // back tracking
                cnt[i] ++;
                ss.pop_back();
            }
        }
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string s;
    cin >> s;
    for (char c : s) cnt[c - 'a'] ++;
    dfs(0, s.length());
    cout << ans.size() << "\n";
    for (string s1 : ans) cout << s1 << "\n";
    return 0;
}
