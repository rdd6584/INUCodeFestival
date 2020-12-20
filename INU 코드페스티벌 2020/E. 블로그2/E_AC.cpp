#include <bits/stdc++.h>
using namespace std;
char s[500001];
int main() {
    int n;
    scanf("%d %s", &n, s);
    printf("%d", (unique(s, s + n) - s)/2 + 1);
}

// author : rdd6584