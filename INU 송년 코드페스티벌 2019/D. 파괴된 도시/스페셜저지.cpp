//github.com/MikeMirzayanov/testlib
#include "testlib.h"
using namespace std;

vector<int> v[2000];
char visit[2000];
char li[2000];
char cnt[2000];

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    int m = inf.readInt();

    int me, op;
    me = ans.readInt(), op = ouf.readInt();
    if (me == -1 || op == -1) {
        if (!(me == op)) quitf(_wa, "");
        int k = 0;
        while (!ouf.seekEof()) {
            k++;
            ouf.readInt();
        }
        if (!k) quitf(_ok, "");
        else quitf(_wa, "");
    }

    if (!(op > 0 && op <= n)) quitf(_wa, "");
    int t, cc = 0;

    for (int i = 0; i < m; i++) {
        int a = inf.readInt();
        int b = inf.readInt();
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    while (!ouf.seekEof()) {
        cc++;
        t = ouf.readInt() - 1;
        if (!(t >= 0 && t < n && ++cnt[t] == 1)) quitf(_wa, "");
        visit[t] = 1;
        for (int j : v[t]) visit[j] = 1;
    }
    if (!(cc == op)) quitf(_wa, "");

    int k = inf.readInt();
    for (int i = 0; i < k; i++) {
        t = inf.readInt() - 1;
        li[t] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!(li[i] == visit[i])) quitf(_wa, "");
    quitf(_ok, "");
}