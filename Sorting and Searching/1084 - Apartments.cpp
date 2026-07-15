#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    // applCnt: the number of applicants
    // aparCnt: the number of apartments
    // tole: the tolerance
    int applCnt, aparCnt, tole, ans = 0;
    cin >> applCnt >> aparCnt >> tole;
    vector <int> desiredSizes(applCnt), aparSizes(aparCnt);
    for (int& sz : desiredSizes) cin >> sz;
    sort(desiredSizes.begin(), desiredSizes.end());
    for (int& sz : aparSizes) cin >> sz;
    sort(aparSizes.begin(), aparSizes.end());
    int apar = 0;
    // Greedy: take the smallest apartment that is big enough
    for (int appl = 0; appl < applCnt; appl++) {
        while (apar < aparCnt && desiredSizes[appl] - aparSizes[apar] > tole) apar++;
        if (apar != aparCnt && abs(desiredSizes[appl] - aparSizes[apar]) <= tole) {
            ans++;
            apar++;
        }
    }
    cout << ans;
    return 0;
}