#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, miv = 1e9;
void go(int now, int t, int l, int r) {
	if (l == r) {
		miv = min(miv, now - 1);
		return;
	}

	int dif = abs(r - l);
	int tt = t * 2;
	if (l - t > 0) {
		if (dif % (tt * 2) == 0 && r - t > 0) go(now + 1, t * 2, l - t, r - t);
		if (dif % (tt * 2) == tt && r + t <= n) go(now + 1, t * 2, l - t, r + t);
	}
	if (l + t <= n) {
		if (dif % (tt * 2) == tt && r - t > 0) go(now + 1, t * 2, l + t, r - t);
		if (dif % (tt * 2) == 0 && r + t <= n) go(now + 1, t * 2, l + t, r + t);
	}
}

int main() {
	int a, b;
	scanf("%d %d %d", &n, &a, &b);
	go(1, 1, a, b);

	if (miv > 1e8) printf("-1");
	else printf("%d", miv);
}