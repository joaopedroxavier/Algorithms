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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vi r[N];
int rec[N], n, p;

bool search(int qt, int i, int recipe){
	bool ans = false;
	if(i == n-1) return true;
	for(int i=0;i<p;++i){
		if(r[i][p]/rec[i] <= 1.1*qt*recipe and r[i][p] >= 0.9*qt*recipe){
			if(search(qt, i+1, rec[i+1])) ans = true;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q=0;q<t;++q){
		memset(rec, 0, sizeof(rec));
		for(int i=0;i<N;++i) r[i].clear();
		cin >> n >> p;
		int ans = 0;
		for(int i=0;i<n;++i) cin >> rec[i];
		for(int i=0;i<n;++i) for(int j=0;j<p;++j){
			int u;
			cin >> u;
			r[i].pb(u);
		}
		for(int i=0;i<n;++i) sort(r[i].begin(), r[i].end());
		for(int i=0;i<p;++i) search(r[0][i]/rec[0], 
	}
	return 0;
}

