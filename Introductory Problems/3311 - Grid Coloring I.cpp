#include <iostream>
#include <vector>
using namespace std;
char a[502][502], b[502][502];
bool valid(int i, int j, char c) {
    if (a[i][j] == c) return 0;
    if (i > 0 && b[i - 1][j] == c) return 0;
    if (j > 0 && b[i][j - 1] == c) return 0;
    return 1;
}

// Recursive enumeration
void dfs(int i, int j, int n, int m) {
    if (i == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    if (j == m) {
        dfs(i + 1, 0, n, m);
        return;
    }
    for (char c = 'A'; c <= 'D'; c++) {
        if (valid(i, j, c)) {
            b[i][j] = c;
            dfs(i, j + 1, n, m);
            b[i][j] = ' ';
        }
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = ' ';
        }
    }
    dfs(0, 0, n, m);
    cout << "IMPOSSIBLE\n";
    return 0;
}