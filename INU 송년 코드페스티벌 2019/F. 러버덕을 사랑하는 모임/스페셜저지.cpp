#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int agrc, char **agrv) {
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2], "r");
	FILE *out = fopen(agrv[3], "r");

	int N, P, E;
	fscanf(in, "%d %d %d", &N, &P, &E);

	pair<int, int> arr[21];
	for (int i = 0; i < N; i++)
		fscanf(in, "%d %d", &arr[i].first, &arr[i].second);
	fclose(in);

	int solAns, sum, paCnt, tmp;
	fscanf(sol, "%d", &solAns);
	fclose(sol);
	assert(fscanf(out, "%d", &sum) == 1);

	if (solAns == -1) 
		assert(sum == -1);
	else {
		if (sum != 0) 
			assert(arr[0].first <= sum && sum <= arr[0].second);
		paCnt = (sum != 0);

		for (int i = 1; i < N; i++) {
			assert(fscanf(out, "%d", &tmp) == 1);
			if (tmp != 0)
				assert(arr[i].first <= tmp && tmp <= arr[i].second);
			paCnt += (tmp != 0);
			sum += tmp;
		}
		assert(paCnt == P);
		assert(sum == E);
	}
	assert(fscanf(out, "%d", &tmp) == -1);

	return 0;
}