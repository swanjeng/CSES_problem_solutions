#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m, num;
    cin >> n >> m;
    vector <int> a(n + 1), index(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i + 1] = num;
        index[num] = i + 1;
    }

    int round = 1;
    for (int i = 2; i <= n; i++) {
        if (index[i - 1] > index[i]) round++;
    }

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (a[x] > 1) round -= (index[a[x] - 1] > index[a[x]]);
        if (a[y] > 1) round -= (index[a[y] - 1] > index[a[y]]);
        // if a[x] + 1 == a[y] or a[y] + 1 == a[x]
        // it is duplication of the two ifs above
        if (a[x] < n && a[x] + 1 != a[y]) round -= (index[a[x]] > index[a[x] + 1]);
        if (a[y] < n && a[y] + 1 != a[x]) round -= (index[a[y]] > index[a[y] + 1]);
        swap(index[a[x]], index[a[y]]);
        swap(a[x], a[y]);
        if (a[x] > 1) round += (index[a[x] - 1] > index[a[x]]);
        if (a[y] > 1) round += (index[a[y] - 1] > index[a[y]]);
        if (a[x] < n && a[x] + 1 != a[y]) round += (index[a[x]] > index[a[x] + 1]);
        if (a[y] < n && a[y] + 1 != a[x]) round += (index[a[y]] > index[a[y] + 1]);
        cout << round << "\n";
    }
    return 0;
}