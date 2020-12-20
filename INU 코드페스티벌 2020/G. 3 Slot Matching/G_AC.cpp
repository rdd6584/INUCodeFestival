#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[3001][3001];
ll vec[3001];
int n;

ll go(int o, int k) {
    if (o == n) return vec[n - 1] * vec[k];
    if (o == n + 1) return 0;
    if (dp[o][k] != -1) return dp[o][k];

    ll mav = 0;
    mav = max(mav, go(o + 2, k) + vec[o - 1] * vec[o]);
    mav = max(mav, go(o + 2, o - 1) + vec[k] * vec[o]);
    mav = max(mav, go(o + 2, o) + vec[k] * vec[o - 1]);
    return dp[o][k] = mav;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &vec[i]);
    printf("%lld", go(2, 0));
}

// author : rdd6584