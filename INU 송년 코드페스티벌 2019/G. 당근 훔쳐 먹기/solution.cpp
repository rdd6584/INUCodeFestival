#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int p[200001];
int main() {
	int n, w;
	ll t, ans = 0;
	scanf("%d %lld", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w, &p[i]);
		ans += w;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		ans += p[i] * (t - n + i);
	printf("%lld", ans);

	return 0;
}