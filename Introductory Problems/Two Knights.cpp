#include <iostream>
#define LL long long
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int row_number = 1 ; row_number <= n ; row_number ++) {
        LL cell_count = row_number * row_number;

        // all combinations equals to C(cell_count, 2)
        LL all_combinations = cell_count * (cell_count-1) / 2;

        // 4 relative positions are invalid
        // these invalid patterns form 2x3 squares.
        // they have (row_number - 1) * (row_numer - 2) probable positions
        LL invalid_combinations = 4 * (row_number - 1) * (row_number - 2);
        cout << all_combinations - invalid_combinations << "\n";
    }
    return 0;
}
