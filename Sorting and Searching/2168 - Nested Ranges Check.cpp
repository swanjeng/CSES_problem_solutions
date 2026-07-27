#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Range {
    int l, r, id;
};

bool cmp(Range a, Range b) {
    if (a.l != b.l) return a.l < b.l;
    else return a.r > b.r;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <Range> a(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a.begin(), a.end(), cmp);

    vector <int> ans1(n, 0), ans2(n, 0);
    int min_r = 2e9, max_r = 0;
    for (int i = n - 1 ; i >= 0 ; i --) {
        if (a[i].r >= min_r) ans1[a[i].id] = 1;
        if (a[i].r <= min_r) min_r = a[i].r;
    }
    for (int i = 0 ; i < n ; i ++) {
        if (a[i].r <= max_r) ans2[a[i].id] = 1;
        if (a[i].r >= max_r) max_r = a[i].r;
    }

    for (int i = 0 ; i < n ; i ++) cout << ans1[i] << " \n"[i == n - 1];
    for (int i = 0 ; i < n ; i ++) cout << ans2[i] << " \n"[i == n - 1];
    return 0;
}