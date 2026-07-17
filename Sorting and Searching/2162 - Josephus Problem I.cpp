#include <iostream>
#include <queue>
using namespace std;
int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    queue <int> q;
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size()) {
        cnt++;
        int tmp = q.front();
        q.pop();
        if (cnt & 1) q.push(tmp);
        else cout << tmp << " \n"[q.size() == 0];
    }
    return 0;
}