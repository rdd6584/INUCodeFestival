#include <bits/stdc++.h>
using namespace std;

int vec[600];

int main() {
    int n;
    scanf("%d", &n);

    int ans = 2e9;
    for (int i = 0; i < n; i++) scanf("%d", &vec[i]);
    sort(vec, vec + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l = j + 2;
            for (int k = j + 1; k < n - 1; k++) {
                while (l <= k || l < n - 1 && vec[i] + vec[l] < vec[j] + vec[k]) l++;
                ans = min(ans, abs((vec[i] + vec[l]) - (vec[j] + vec[k])));
                if (l != k + 1) ans = min(ans, abs((vec[i] + vec[l - 1]) - (vec[j] + vec[k])));
            }
        }
    }

    printf("%d", ans);
}

// author: rdd6584