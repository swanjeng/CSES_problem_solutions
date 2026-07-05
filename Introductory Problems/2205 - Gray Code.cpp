#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector <string>& a) {
    for (string s : a) cout << s << "\n";
}
void grayCode(vector <string>& a, int n) {
    if (n == 1) print(a);
    else {
        // create a reverse vector
        vector <string> b;
        for (string s : a) b.push_back(s);
        reverse(b.begin(), b.end());

        // add 0 to the original vector and 1 to the reversed
        for (string& s : a) s += "0";
        for (string& s : b) s += "1";

        // conbine the two vectors and enter recursion
        for (string s : b) a.push_back(s);
        grayCode(a, n - 1);
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <string> a{ "0", "1" };
    grayCode(a, n);
    return 0;
}
