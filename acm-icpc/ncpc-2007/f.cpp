#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e3+5;
const int C = 1e2+5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f; 

int n, m, q;
vector<int> adj[N];
int dist[N][C], p[N], wt[N][N];

int qry(int u, int v, int c) {
	memset(dist, 63, sizeof dist);

	priority_queue<pair<int, ii>> pq;
	dist[u][0] = 0; pq.push({0, {u,0}});
	for(int i=1; i<=c; i++) {
		dist[u][i] = i * p[u];
		pq.push({-dist[u][i], {u,i}});
	}

	while(!pq.empty()) {
		pair<int, ii> t = pq.top();
		int dd = -t.first;
		int cc = t.second.second;
		int uu = t.second.first;
		//printf("%d %d\n", uu, cc);

		if(uu == v) return dd;
		pq.pop();

		if(dist[uu][cc] < dd) continue;

		for(int i=cc+1; i<=c; i++) {
			if(dist[uu][i] > dd + p[uu] * (i-cc)) {
				dist[uu][i] = dd + p[uu] * (i-cc);
				pq.push({-dist[uu][i], {uu, i}});
			}
		}

		for(int vv : adj[uu]) {
			if(cc >= wt[uu][vv]) {
				int nc = cc - wt[uu][vv];
				if(dist[vv][nc] > dd) {
					dist[vv][nc] = dd;
					pq.push({-dist[vv][nc], {vv, nc}});
				}
			}
		}
	}
	return INF;
	
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", &p[i]);
	memset(wt, 63, sizeof wt);
	for(int i=0; i<m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if(u != v) {
			u++; v++;
			wt[u][v] = wt[v][u] = min(wt[u][v], w);

			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	scanf("%d", &q);
	for(int i=0; i<q; i++) {
		int u, v, c;
		scanf("%d %d %d", &c, &u, &v);
		u++; v++;
		int qr = qry(u,v,c);
		if(qr == INF) printf("impossible\n");
		else printf("%d\n", qr);
	}

	return 0;
}
