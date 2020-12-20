#include <bits/stdc++.h>
using namespace std;

map<string, int> ma;

int main() {
    int n;
    string ans;
    cin >> n >> ans;

    int ret = 0;
    for (int i = 0; i < n; i++) {
        string now, me;
        cin >> now >> me;
        if (now == ans) ret = ma[me];
        ma[me]++;
    }

    printf("%d", ret);
}

// author: rdd6584
