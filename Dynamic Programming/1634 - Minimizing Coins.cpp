#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 3e6
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    int n, money;
    cin >> n >> money;

    vector <int> coins(n);
    vector <int> dp(money + 1, MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());

    for (int i = 1; i <= money; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coins[j]) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    cout << (dp[money] == MAX ? -1 : dp[money]) << "\n";
    return 0;
}