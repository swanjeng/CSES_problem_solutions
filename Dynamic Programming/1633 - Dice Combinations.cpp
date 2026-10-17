#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int x;
    cin >> x;
    vector <long long> dp(x + 1, 0);
    for (int i = 1; i <= x; i++) {
        // When the number is smaller than 6
        // dp[i] is sum(dp[1 ... i - 1]) + 1
        // +1 is for the dice with value i
        if (i <= 6) {
            for (int j = 1; j < i; j++) dp[i] += dp[j];
            dp[i]++;
        } else {
            for (int j = 1; j <= 6; j++) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << "\n";
    return 0;
}