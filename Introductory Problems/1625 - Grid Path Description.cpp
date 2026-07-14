#include <iostream>
using namespace std;
int ans = 0;
int grid[9][9] = { {1, 1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 1, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 1, 1, 1, 1, 1, 1, 1, 1} };

int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dfs(string& s, int idx, int x, int y) {
    if (x == 7 && y == 1) {
        if (idx == 48) ans++;
        return;
    } else {
        if (s[idx] == '?') {
            for (int i = 0; i < 4; i++) {
                int x1 = x + d[i][0];
                int y1 = y + d[i][1];
                // Prune branches where
                // "there are paths in front and behind
                // but no paths to the left or right"
                // or "there are paths to the left and right
                // but no paths in front and behind".
                // Only these two cases will result in an XOR value of 2.
                if (grid[x1][y1] == 0 && ((grid[x1 + 1][y1] + grid[x1 - 1][y1]) ^ (grid[x1][y1 - 1] + grid[x1][y1 + 1])) != 2) {
                    grid[x1][y1] = 1;
                    dfs(s, idx + 1, x1, y1);
                    grid[x1][y1] = 0;
                }
            }
        } else if (s[idx] == 'U' && grid[x - 1][y] == 0) {
            grid[x - 1][y] = 1;
            dfs(s, idx + 1, x - 1, y);
            grid[x - 1][y] = 0;
        } else if (s[idx] == 'D' && grid[x + 1][y] == 0) {
            grid[x + 1][y] = 1;
            dfs(s, idx + 1, x + 1, y);
            grid[x + 1][y] = 0;
        } else if (s[idx] == 'L' && grid[x][y - 1] == 0) {
            grid[x][y - 1] = 1;
            dfs(s, idx + 1, x, y - 1);
            grid[x][y - 1] = 0;
        } else if (s[idx] == 'R' && grid[x][y + 1] == 0) {
            grid[x][y + 1] = 1;
            dfs(s, idx + 1, x, y + 1);
            grid[x][y + 1] = 0;
        }
    }
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    string s;
    cin >> s;
    dfs(s, 0, 1, 1);
    cout << ans << "\n";
    return 0;
}