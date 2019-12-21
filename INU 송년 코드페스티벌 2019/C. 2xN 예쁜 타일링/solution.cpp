#include <cstdio>
#include <algorithm>
using namespace std;

int av[2000], bv[2000];
int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    for (int i = 0; i < a; i++)
        scanf("%d", &av[i]);
    for (int i = 0; i < b; i++)
        scanf("%d", &bv[i]);
    sort(av, av + a);
    sort(bv, bv + b);

    int ans = 0;
    if (n % 2) ans += av[--a], n--;
    for (int i = 0; i < n; i += 2) {
        int t = 0, tt = 0;

        if (a >= 2) t = av[a - 1] + av[a - 2];
        if (b) tt = bv[b - 1];

        if (t > tt) {
            ans += t;
            a -= 2;
        }
        else {
            ans += tt;
            b -= 1;
        }
    }
    printf("%d", ans);
}