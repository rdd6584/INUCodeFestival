#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll a[500001];
pll vec[500001];

int main() {
    memset(a, -0x3f, sizeof(a));

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%lld", &vec[i].first);
    for (int i = 0; i < n; i++) scanf("%lld", &vec[i].second);
    sort(vec, vec + n, [](pll a, pll b) {return a.second > b.second;});

    ll now = 0;

    priority_queue<ll> pq;
    for (int i = 0; i < k; i++) now -= vec[i].second, pq.push(vec[i].first + vec[i].second);

    a[0] = now;
    for (int i = 0; i < k; i++) {
        pq.push(vec[i + k].first + vec[i + k].second);
        now -= vec[i + k].second;
        now += pq.top();
        pq.pop();
        a[i + 1] = now;
    }
    while (!pq.empty()) pq.pop();
    ll ans = a[k];
    now = 0;

    for (int i = 2 * k; i < n; i++) pq.push(vec[i].first);
    for (int i = 1; i <= k; i++) {
        pq.push(vec[2 * k - i].first);
        now += pq.top();
        pq.pop();
        ans = max(ans, a[k - i] + now);
    }

    printf("%lld\n", ans);
}

// author: rdd6584
