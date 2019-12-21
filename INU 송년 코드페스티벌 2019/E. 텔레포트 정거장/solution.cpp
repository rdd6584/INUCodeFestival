#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec[300001];
int dist[300001];
int main() {
	int n, m, s, e, a, b;
	scanf("%d %d %d %d", &n, &m, &s, &e);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	queue<int> q;
	q.push(s);
	memset(dist, -1, sizeof(dist));
	dist[s] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur + 1 <= n && dist[cur + 1] == -1) {
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 1 && dist[cur - 1] == -1) {
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
		for (int v : vec[cur]) {
			if (dist[v] == -1) {
				dist[v] = dist[cur] + 1;
				q.push(v);
			}
		}
	}
	printf("%d", dist[e]);
}