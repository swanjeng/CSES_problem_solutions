#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int len = s.length(), ans = 1, curr = 1; // the answer is at least 1
    for (int i = 1 ; i < len ; i ++) {
        if (s[i] == s[i - 1]) curr ++;
        else curr = 1;
        ans = max(ans, curr);
    }
    cout << ans << "\n";
    return 0;
}
