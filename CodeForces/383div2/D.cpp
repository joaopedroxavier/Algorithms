//
//	(D - Arpa's weak amphitheater and Mehrdad's valuable Hoses)
//	CodeForces Round #383 Div.2
//	source: http://codeforces.com/contest/742/problem/D
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=2e3;

ll K[N][N];
int dad[N], h[N], dad_help[N], b[N], w[N];
vector<ll> helpb[N], helpw[N];
int find_dad(int u){
	if(!dad[u]) return u;
	else return find_dad(dad[u]);
}

void dsu(int u, int v){
	int pu = find_dad(u), pv = find_dad(v);
	if(pu!=pv){
		if(h[pu]>h[pv]) dad[pv] = pu, h[pv] = max(h[pu]+1,h[pv]);
		else dad[pu] = pv, h[pu] = max(h[pv]+1,h[pu]);
	}
}

int main(){
	int n, m, tw, u, v, aux;
	ll cont=1, sumw=0, sumb=0, tmp;
	vi help[N];
	cin >> n >> m >> tw;
	for(int i=1;i<=n;++i) cin >> w[i];
	for(int i=1;i<=n;++i) cin >> b[i];
	for(int i=1;i<=m;++i){
		cin >> u >> v;
		dsu(u,v);
	}
	for(int i=1;i<=n;++i) dad_help[i] = find_dad(i);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			if(dad_help[i] == find_dad(j)) dad_help[i] = min(j, dad_help[j]);
		}
	}
	for(int i=1;i<=n;++i) if(dad_help[i] >= cont) dad_help[i] = cont, cont++;
	for(int i=1;i<=n;++i) help[dad_help[i]].pb(i);
	for(int i=1;i<cont;++i){
		sumw = 0;
		sumb = 0;
		for(unsigned j=0;j<help[i].size();++j){
			aux = help[i].at(j);
			helpw[i].pb(w[aux]);
			helpb[i].pb(b[aux]);
			sumw+=w[aux];
			sumb+=b[aux];
		}
		helpw[i].pb(sumw);
		helpb[i].pb(sumb);
	}
	for(int i=0;i<cont;++i){
		for(int p=0;p<=tw;++p){
			if(i==0 or p==0) K[i][p] = 0;
			else{
				for(unsigned k=0;k<helpw[i].size();++k){
					if(helpw[i].at(k) <= p){
						tmp = max(helpb[i].at(k)+K[i-1][p-helpw[i].at(k)], K[i-1][p]);
					}
					else{
						tmp = K[i-1][p];
					}
					if(tmp>K[i][p]) K[i][p] = tmp;
				}
			}
		}
	}
	cout << K[cont-1][tw] << endl;
	return 0;
}

