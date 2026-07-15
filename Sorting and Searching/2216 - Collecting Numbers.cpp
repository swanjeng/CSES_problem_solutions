#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, x;
    cin >> n;
    vector <int> index(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        index[x - 1] = i;
    }
    int round = 0;
    for (int i = 0; i < n; i++) {
        if (index[i] > index[i + 1]) round++;
    }
    cout << round;
    return 0;
}