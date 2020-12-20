#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef pair<int, int> pii;
int n, s, e;
vector<int> v[200000];
int dd[200000];
int ldp[200000], rdp[200000];
vector<int> vv;
int lm = 0, rm = 0;

int go(int o, int le, int ri) {
    int ret;
    if (o & 1 ^ 1) {
        ret = -1e8;
        if (le + 1 != ri) ret = go(o + 1, le + 1, ri);
        rm = max(rm, rdp[ri]);
        lm = max(lm, ldp[ri]);
        ret = max(ret, ldp[le] - rm);
    }
    else {
        ret = 1e8;
        if (le + 1 != ri) ret = go(o + 1, le, ri - 1);
        lm = max(lm, ldp[le]);
        rm = max(rm, rdp[le]);
        ret = min(ret, lm - rdp[ri]);
    }
    return ret;
}

pii pre(int o, int pa) {
    pii ret = {0, 0};
    for (int i : v[o]) {
        if (i == pa) continue;
        pii tv = pre(i, o);
        ret.second |= tv.second;
        tv.first++;
        if (tv.second == 0) ret.first = max(ret.first, tv.first);
    }

    if (o == e) ret.second = 1;
    dd[o] = ret.first;

    if (ret.second) vv.push_back(o);
    return ret;
}

int main() {
    scanf("%d %d %d", &n ,&s, &e);
    s--; e--;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    pre(s, s);
    reverse(all(vv));

    n = sz(vv);
    for (int i = 0; i < n; i++) {
        ldp[i] = dd[vv[i]] + i;
        rdp[i] = dd[vv[i]] + n - i - 1;
    }
    printf("%d", go(0, 0, n - 1));
}

// author : rdd6584