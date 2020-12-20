#include <bits/stdc++.h>
using namespace std;

char mat[2][200001];
int dp[2][200001], fl[200001];
int ans[2][200001], bns[2][200001];
int n;

void solve(int ret[2][200001]) {
    memset(dp, 0, sizeof(dp));
    memset(fl, 0, sizeof(fl));
    memset(ret, 0x3f, sizeof(ans));

    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int now = flag;
            if (mat[j ^ 1][i]) {
                now += 1;
                if (i) now += dp[j ^ 1][i - 1];
            }
            else if (i) now += dp[j][i - 1];
            dp[j][i] = now;
        }

        flag |= mat[0][i];
        flag |= mat[1][i];
        fl[i] = flag;
    }

    flag = 0;
    int far = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (mat[0][i]) flag |= 1, far = max(far, i);
        if (mat[1][i]) flag |= 2, far = max(far, i);

        if (far == -1) {
            ret[0][i] = dp[0][i - 1] + 1;
            ret[1][i] = dp[1][i - 1] + 1;
            continue;
        }

        for (int j = 0; j < 2; j++) {
            int op = j ^ 1;
            int now = (far - i) * 2;

            if (flag & 1 << op) {
                now += 1;
                if (i && fl[i - 1]) now += 1 + dp[op][i - 1];
            }
            else {
                if (i && fl[i - 1]) now += 1 + dp[j][i - 1];
            }
            ret[j][i] = now;
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s %s", mat[0], mat[1]);

    int flag = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = mat[i][j] == '#', flag |= mat[i][j];

    if (!flag) {
        for (int i = 0; i < n; i++) printf("0 ");
        printf("\n");
        for (int i = 0; i < n; i++) printf("0 ");
        return 0;
    }

    solve(ans);
    reverse(mat[0], mat[0] + n);
    reverse(mat[1], mat[1] + n);
    solve(bns);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", min(ans[i][j], bns[i][n - j - 1]));
        printf("\n");
    }
}

// author : rdd6584