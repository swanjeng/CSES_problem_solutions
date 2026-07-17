#include <iostream>
#include <vector>
#include <map>
#define MOD 1000000007
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> mp;
    for (int& x : a) {
        cin >> x;
        mp[x]++;
    }
    // for each number x,
    // there are mp[x] + 1 choices in a subsequence
    long long ans = 1;
    for (auto& x : mp) {
        ans *= (x.second + 1);
        ans %= MOD;
    }
    // minus 1 for the empty subsequence
    cout << (ans + MOD - 1) % MOD << "\n";
    return 0;
}