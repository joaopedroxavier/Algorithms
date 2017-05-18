#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=8;
const int MOD=1e9+7;
const int P=31;
const int INF=0x3f3f3f3f;

vi src, des;
unordered_map<int, ll> dist;
unordered_set<int> vis;
map<int, vi> adj;

int p[8];

void gen_pot(int p[]){
	p[0] = 1;
	for(int i=1;i<8;++i){
		p[i] = (p[i-1] * P) % MOD;
	}
}

int get_hash(vi v){
	int h = 0;
	for(int i=0;i<8;++i){
		h = (h + (v[i] * p[i]) % MOD) % MOD;
	}
	return h;
}

int main(){
	ios_base::sync_with_stdio(false);
	for(int i=0;i<8;++i){
		int u;
		cin >> u;
		src.pb(u);
	}
	for(int i=0;i<8;++i){
		int u;
		cin >> u;
		des.pb(u);
	}
	gen_pot(p);
	for(int i=0;i<8;++i){
		if(i%4 != 3) adj[i].pb(i+1);
		if(i < 4) adj[i].pb(i+4);
	}
	priority_queue<pair<ll, vi> > dij;
	dij.push(mp(0, src));
	dist[get_hash(src)] = 0;
	vis.insert(get_hash(src));
	while(!dij.empty()){
		vi u = dij.top().second;
		ll d = -dij.top().first;
		int key = get_hash(u);
		dij.pop();
		if(vis.count(key) and dist[key] < d) continue;
		for(int i=0;i<8;++i){
			for(int j : adj[i]){
				int key2 = (key + ((u[i] * (p[j] - p[i])) % MOD + u[j] * (p[i] - p[j]) % MOD) % MOD);
				swap(u[i], u[j]);
				if(!vis.count(key2) or (vis.count(key2) and dist[key2] > d + (u[i] + u[j]))){
					vis.insert(key2);
					dist[key2] = d + (u[i]+u[j]);
					dij.push(mp(-dist[key2], u));
				}
				swap(u[i], u[j]);
			}
		}
	}
	cout << dist[get_hash(des)] << endl;

	return 0;
}

