#include <iostream>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
    } else if (n <= 3) {
        // such permutation is impossible for n = 2 or n = 3
        cout << "NO SOLUTION\n"; 
    } else {
        // for other n >= 4
        // output all even numbers first
        for (int i = 2 ; i <= n ; i += 2) {
            cout << i << " ";
        }
        // output all odd numbers
        // if i < n - 1, there will be a space after each number
        // i >= n - 1 means this i is the last number
        // and there should be a '\n' character
        for (int i = 1 ; i <= n ; i += 2) {
            cout << i << " \n"[i >= n - 1];
        }
    }
    return 0;
}
