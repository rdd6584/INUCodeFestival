#include <bits/stdc++.h>
using namespace std;

int ball[200001];

int main() {
    int n, x, k;
    scanf("%d %d %d", &n, &x, &k);
    ball[x] = 1;

    int ans = x;
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        swap(ball[a], ball[b]);
        if (ball[a]) ans = a;
        if (ball[b]) ans = b;
    }
    printf("%d", ans);
}

// author: rdd6584