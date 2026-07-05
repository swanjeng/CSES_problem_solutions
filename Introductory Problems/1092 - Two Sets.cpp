#include <iostream>
#include <vector>
#define LL long long
using namespace std;
void print(vector <LL> a) {
    // print the length of the array and the content of it
    LL len = a.size();
    cout << len << "\n";
    for (LL i = 0 ; i < len ; i ++) cout << a[i] << " \n"[i+1 == len];
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    LL n;
    cin >> n;
    LL s = n * (n + 1) / 2;
    if (s & 1) cout << "NO\n"; // odd sums are impossible
    else {
        vector <long long> a1, a2;
        LL curr = 0, s1 = s/2;
        for (LL x = n ; x >= 1 ; x --) { // add from the biggest
            if (curr + x <= s1) {
                a1.push_back(x);
                curr += x;
            } else {
                a2.push_back(x);
            }
        }
        cout << "YES\n";
        print(a1);
        print(a2);
    }
    return 0;
}
