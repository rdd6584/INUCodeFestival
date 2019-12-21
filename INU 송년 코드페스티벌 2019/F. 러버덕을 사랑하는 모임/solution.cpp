#include <cstdio>
#include <algorithm>
using namespace std;

int n, e, mnV;
bool use[21];
pair<int, int> arr[21];
bool dfs(int w, int cur, int mn, int mx) {
	if (w == 0) {
		mnV = mn;
		if (mn <= e && e <= mx) return true;
		return false;
	}
	if (cur >= n) return false;
	use[cur] = true;
	if (dfs(w - 1, cur + 1, mn + arr[cur].first, mx + arr[cur].second))
		return true;
	use[cur] = false;
	if (dfs(w, cur + 1, mn, mx))
		return true;
	return false;
}
int main() {
	int p;
	scanf("%d %d %d", &n, &p, &e);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	if (!dfs(p, 0, 0, 0)) return !printf("-1");
	e -= mnV;
	for (int i = 0; i < n; i++) {
		if (!use[i]) printf("0 ");
		else {
			int prt = min(arr[i].first + e, arr[i].second);
			printf("%d ", prt);
			e -= prt - arr[i].first;
		}
	}
}