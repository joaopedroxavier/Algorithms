#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n, m, k, t, p[N], v[N], ans, c;

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &t);
	for(int i=0; i<n; ++i) scanf("%d", p+i);
	for(int i=0; i<m; ++i) scanf("%d", v+i);
	sort(p, p+n);
	sort(v, v+m);

	for(int i=0, j=0; i<n; ++i) {
		while(j < m and (c == k or p[i]-v[j] > t)) c = 0, j++;
		if (j < m and c < k and abs(p[i]-v[j]) <= t) ans++, c++;
	}

	printf("%d\n", ans);
	return 0;
}
