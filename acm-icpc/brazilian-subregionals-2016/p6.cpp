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

int canl[N], canc[N], desc[N], desr[N], visc[N], visd[N];
int maxc, maxd;

int getcentd(int i){
	visd[i] = 1;
	if(desc[i] == 0) return 1;
	else{
		return getcentd(desc[i]) + 1;
	}
}

int getcentc(int i){
	visc[i] = 1;
	if(canc[i] == 0) return 1;
	else{
		return getcentc(canc[i]) + 1;
	}
}


int main(){
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	for(int i=1;i<=n;++i){
		int u, v, w;
		cin >> u >> v >> w;
		canl[u] = v, canc[u] = w;
	}
	cin >> m;
	for(int i=1;i<=m;++i){
		int u, v, w;
		cin >> u >> v >> w;
		desc[u] = v, desr[u] = w;
	}
	for(int i=1;i<=n;++i) if(!visc[i]){
		maxc = max(maxc, getcentc(i));
	}
	for(int i=1;i<=m;++i) if(!visd[i]){
		maxd = max(maxd, getcentd(i));
	}
	cout << n+m - max(min(getcentc(1), maxd), min(getcentd(1), maxc)) << endl;

	return 0;
}

