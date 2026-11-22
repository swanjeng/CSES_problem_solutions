#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct Range {
    int l, r, id;
};

bool cmp(Range a, Range b) {
    if (a.l != b.l) return a.l < b.l;
    else return a.r > b.r;
}

bool cmp2(int a, int b) {
    return a > b;
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

    map <int, vector <int>> mp;
    vector <int> ls;
    for (int i = 0 ; i < n ; i ++) {
        if (!mp.count(a[i].l)) ls.push_back(a[i].l);
        mp[a[i].l].push_back(a[i].r);
    }

    vector <int> ans1(n, 0), ans2(n, 0);
    for (int i = 0 ; i < n - 1 ; i ++) {
        auto it = lower_bound(ls.begin(), ls.end(), a[i].l);
        if (mp[a[i].l].size() == 1) it ++;
        else if (a[i].l == a[i + 1].l) {
            ans1[a[i].id] += (mp[a[i].l].size() - (lower_bound(mp[a[i].l].begin(), mp[a[i].l].end(), a[i].r, cmp2) - mp[a[i].l].begin()) - 1);
            it ++;
        }
        while (it != ls.end()) {
            ans1[a[i].id] += (mp[*it].size() - (lower_bound(mp[*it].begin(), mp[*it].end(), a[i].r, cmp2) - mp[*it].begin()));
            it ++;
        }
    }

    for (int i = n - 1 ; i > 0 ; i --) {
        auto it = lower_bound(ls.begin(), ls.end(), a[i].l);
        if (it == ls.begin() && mp[a[i].l].size() == 1) continue;
        if (mp[a[i].l].size() == 1) it--;
        else if (a[i].l == a[i - 1].l) {
            ans2[a[i].id] += (lower_bound(mp[a[i].l].begin(), mp[a[i].l].end(), a[i].r, cmp2) - mp[a[i].l].begin());
            if (it != ls.begin()) it --;
        }
        while (1) {
            auto it2 = lower_bound(mp[*it].begin(), mp[*it].end(), a[i].r, cmp2);
            ans2[a[i].id] += it2 - mp[*it].begin();
            if (it2 != mp[*it].end() && *it2 == a[i].r) ans2[a[i].id] ++;
            if (it != ls.begin()) it --;
            else break;
        }
    }

    for (int i = 0 ; i < n ; i ++) cout << ans1[i] << " \n"[i == n - 1];
    for (int i = 0 ; i < n ; i ++) cout << ans2[i] << " \n"[i == n - 1];
    return 0;
}