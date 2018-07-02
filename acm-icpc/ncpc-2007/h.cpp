#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+5;
const int INF = 0x3f3f3f3f;

int n, t;
ll v[N];

int main() {
	scanf("%d", &t);
	while(t--) {
		memset(v, 0, sizeof v);
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%lld", &v[i]);
		}
		sort(v, v+n, [](int a, int b) { return a > b; });
		ll ans = 0;
		for(int i=0; i<n; i++) if(i % 3 == 2) ans += v[i];
		printf("%lld\n", ans);
	}
	return 0;
}
