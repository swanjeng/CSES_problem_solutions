#include <iostream>
#include <algorithm>
using namespace std;
int cnt[26] = { 0 };
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int len = s.length();
    for (char c : s) {
        cnt[c - 'A']++;
        if (cnt[c - 'A'] > (len + 1) / 2) {
            cout << -1 << "\n";
            return 0;
        }
    }
    
    int _ = 0;
    char lastCh = ' ';
    while (_ < len) {
        int rem = len - _;
        if (rem & 1) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == (rem + 1) / 2) {
                    cout << (char)(i + 'A');
                    cnt[i]--;
                    lastCh = (char)(i + 'A');
                    _++;
                    break;
                }
            }
            if (_ == len) break;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] && lastCh != (char)(i + 'A')) {
                cout << (char)(i + 'A');
                cnt[i]--;
                lastCh = (char)(i + 'A');
                _++;
                break;
            }
        }
    }
    cout << "\n";
    return 0;
}