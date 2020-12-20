#include <bits/stdc++.h>
using namespace std;

int vis[1<<20];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);

        int tt = t;
        int flag = 0;

        while (t) {
            if (vis[t]) flag = t;
            t /= 2;
        }

        if (flag) printf("%d\n", flag);
        else printf("0\n"), vis[tt] = 1;
    }
}

// author: rdd6584