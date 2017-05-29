#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=10;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vi adj[N], src(8), des(8); 
map<vi, ll> dist, vis;
int x;

int main(){
	ios_base::sync_with_stdio(false);

	for(int i=0;i<8;++i) cin >> src[i];

	for(int i=0;i<8;++i) cin >> des[i];

	for(int i=0;i<8;++i){
		if(i<4) adj[i].pb(i+4);
		if((i%4)!=3) adj[i].pb(i+1);
	}

	priority_queue<pair<ll, vi>> dij;
	dij.push(mp(0, src));
	dist[src] = 0, vis[src]=1;
	while(!dij.empty()){
		vi u = (dij.top()).second;
		ll w = -(dij.top()).first;
		dij.pop();
		for(int i=0;i<8;++i) for(int j=0;j<(int)adj[i].size();++j){
			vi v = u;
			ll wt = v[i] + v[adj[i][j]];
			swap(v[i], v[adj[i][j]]);
			if(dist[v] > w + wt or !vis[v]) dist[v] = w + wt, dij.push(mp(-(w+wt), v));
			vis[v] = 1;
		}
	}
	cout << dist[des] << endl;
	return 0;
}

