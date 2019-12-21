#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int ans = 0, miv = 2e9, t;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t == -1) {
            ans += miv;
            miv = 2e9;
        }
        else miv = min(miv, t);
    }
    printf("%d", ans + miv);
}