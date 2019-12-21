#include <cstdio>

int sum[100];
int mat[100][100];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            sum[j] += mat[j][i];
            if (sum[j] >= k) return !printf("%d %d", j + 1, i + 1);
        }
}