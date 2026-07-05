#include <iostream>
using namespace std;
char valid(int cnt[26]) {
    // '.' means that all letters appear an even number of times..
    // '-' means invalid string.
    // 'A' ~ 'Z' means The only letter that appears an odd number of times
    char ch = '.';
    for (int i = 0 ; i < 26 ; i ++) {
        if (cnt[i] & 1) {
            if (ch != '.') return '-';
            ch = i + 'A';
        }
    }
    return ch;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int cnt[26] = {0};
    string a;
    cin >> a;
    for (char c : a) cnt[c - 'A'] ++;
    
    char ch = valid(cnt);
    if (ch == '-') cout << "NO SOLUTION\n";
    else {
        if (ch != '.') cnt[ch - 'A'] --;
    
        for (int i = 0 ; i < 26 ; i ++) {
            int x = cnt[i];
            for (int j = 0 ; j < x/2 ; j ++) {
                cout << (char) (i + 'A');
            }
            cnt[i] -= x / 2;
        }
        if (ch != '.') cout << ch;    
        for (int i = 25 ; i >= 0 ; i --) {
            int x = cnt[i];
            for (int j = 0 ; j < x ; j ++) {
                cout << (char) (i + 'A');
            }
        }
    }
    return 0;
}
