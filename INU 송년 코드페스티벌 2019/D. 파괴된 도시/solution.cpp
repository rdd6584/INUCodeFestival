#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec[2001], ans;
bool brk[2001];
int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        brk[a] = true;
    }
    for (int i = n; i >= 1; i--) {
        bool suc = true;
        for (int v : vec[i]) {
            if (brk[i] && !brk[v]) suc = false;
        }
        if (brk[i] && suc)
            ans.push_back(i);
    }
    for (int v : ans) {
        brk[v] = false;
        for (int j : vec[v])
            brk[j] = false;
    }
    for (int i = 1; i <= n; i++) if (brk[i]) return !printf("-1");
    printf("%d\n", ans.size());
    for (int v : ans) printf("%d ", v);
}