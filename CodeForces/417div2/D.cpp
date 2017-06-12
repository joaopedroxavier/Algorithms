//
//
//
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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int toy[N], last[N], first[N];
int tin[N], tout[N], numsub[N], ct;vi adj[N];

void eulerwalk(int u){
	tin[u] = ++ct;
	numsub[u] = 1;
	for(int v : adj[u]){
		eulerwalk(v);
		numsub[u]+=numsub[v];
	}
	tout[u] = ++ct;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k, q;
	cin >> n >> m >> k >> q;

	for(int i=0;i<k;++i){
		int a, b;
		cin >> a >> b;
		if(!toy[b]) toy[b] = a, last[b] = a, first[a] = 1;
		else adj[last[b]].pb(a), last[b] = a, first[a] = 0;
	}

	for(int i=1;i<=n;++i) if(first[i]) eulerwalk(i); 

	for(int i=0;i<q;++i){
		int a, b;
		cin >> a >> b;
		cout << ((tin[a] <= tin[toy[b]] and tout[a] >= tout[toy[b]]) ? numsub[a] : 0) << endl;
	}

	return 0;
}

