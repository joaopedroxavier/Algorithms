//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e3+5;
const int INF=0x3f3f3f3f;

int n;
int x[N], y[N], r[N], vis[N];
vi adj[N];
int nok;

void dfs(int u, int val) {
				vis[u] = val;
				for(int v: adj[u]) {
								if(vis[v] == val) {
												nok = 1;
												return;
								};
								if(!vis[v]) dfs(v, (val%2) +1);
				}
}
int mdc(int a, int b) { return b? mdc(b, a%b) : a; }

int main(){
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d%d%d", &x[i], &y[i], &r[i]);

	for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) {
					int d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
					if(d == (r[i]+r[j])*(r[i]+r[j])) {
									adj[i].pb(j);
									adj[j].pb(i);
					}
	}

	dfs(0, 1);
	if(nok) printf("The input gear cannot move.\n");
	else if(vis[n-1] == 0) printf("The input gear is not connected to the output gear.\n");
	else {
					int d = mdc(max(r[0], r[n-1]), min(r[0], r[n-1]));
					r[0]/=d;
					r[n-1]/=d;
					if(vis[0] != vis[n-1]) r[0]*=-1;
					printf("%d:%d\n", r[0], r[n-1]);
	}

}

