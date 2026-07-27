#include <iostream>
#define MAXN 200005
using namespace std;

int n;
long long k;

// 1-indexed
// assum that alive[i] is 1 if person i is in the circle
// alive[i] is 0 if person i is out
// bit_[i] is sum(alive[i - lowbit(i) + 1], ... , alive[i])
int bit_[MAXN];

void update(int i, int delta) {
    for (; i <= n; i += i & (-i)) bit_[i] += delta;
}

int find_kth(int kth) { // both kth and return value are 1-indexed
    int pos = 0;
    int logn = 0;
    while ((1 << (logn + 1)) <= n) logn++;
    for (int pw = 1 << logn; pw > 0; pw >>= 1) {
        if (pos + pw <= n && bit_[pos + pw] < kth) {
            pos += pw;
            kth -= bit_[pos];
        }
    }
    return pos + 1;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) update(i, 1);

    long long remaining = n;
    long long cur = 0; // 0-indexed order pointer
    for (int i = 0; i < n; i++) {
        cur = (cur + k) % remaining;
        int idx = find_kth((int)cur + 1);
        cout << idx << " \n"[i == n - 1];
        update(idx, -1);
        remaining--;
        if (remaining && cur >= remaining) cur = 0;
    }
    return 0;
}