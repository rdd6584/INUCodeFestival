#include <cstdio>
using namespace std;

int A[500001], B[500001];
bool tmp[500001];
int main() {
	int n, a, b, jp = 1;
	scanf("%d %d %d", &n, &a, &b);
	A[a] = 1, B[b] = 1;
	for (int i = 2; i <= 21; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[j] == i - 1) {
				if (j - jp > 0) tmp[j - jp] = true;
				if (j + jp <= n) tmp[j + jp] = true;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (tmp[j]) A[j] = i;
			tmp[j] = false;
		}
		for (int j = 1; j <= n; j++) {
			if (B[j] == i - 1) {
				if (j - jp > 0) tmp[j - jp] = true;
				if (j + jp <= n) tmp[j + jp] = true;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (tmp[j]) {
				B[j] = i;
				if (A[j] == i) return !printf("%d", i - 1);
			}
			tmp[j] = false;
		}
		jp <<= 1;
	}
	printf("-1");
}