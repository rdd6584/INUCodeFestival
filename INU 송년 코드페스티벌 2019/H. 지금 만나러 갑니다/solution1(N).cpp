#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct info {
	int a, b, jp;
};
queue<info> q;
int main() {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	if ((int)abs(a - b) % 2) return !printf("-1");
	q.push({ a,b,0 });
	while (!q.empty()) {
		info cur = q.front();
		if (cur.a == cur.b) return !printf("%d", cur.jp);
		q.pop();
		int jp = 1 << cur.jp;
		int dist = abs(cur.a - cur.b);
		if (dist % (jp * 4) == 0) {
			if (cur.a - jp > 0 && cur.b - jp > 0)
				q.push({ cur.a - jp, cur.b - jp, cur.jp + 1 });
			if (cur.a + jp <= n && cur.b + jp <= n)
				q.push({ cur.a + jp, cur.b + jp, cur.jp + 1 });
		}
		else {
			if (cur.a - jp > 0 && cur.b + jp <= n)
				q.push({ cur.a - jp, cur.b + jp, cur.jp + 1 });
			if (cur.a + jp <= n && cur.b - jp > 0)
				q.push({ cur.a + jp, cur.b - jp, cur.jp + 1 });
		}
	}
	printf("-1");
}