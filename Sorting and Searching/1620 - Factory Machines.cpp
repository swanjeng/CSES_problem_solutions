#include <iostream>
#include <vector>
using namespace std;
bool valid(long long mid, vector <int> &a, int t) {
    long long sum = 0; // how many product can be made in time mid
    for (int x : a) {
        sum += mid / x;
        if (sum >= t) return 1;
    }
    return sum >= t;
}
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    long long low = 0, high = 1e+18, mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (valid(mid, a, t)) high = mid;
        else low = mid + 1;
    }
    cout << low << "\n";
    return 0;
}