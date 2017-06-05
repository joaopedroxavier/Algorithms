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

map<vi, ll> ans;
ll reg[N][4], pl[N][3], n, m, r;

void gen_orbit(int x, int y, int z){
	vi v;
	for(int i=0;i<m;++i){
		ll s = reg[i][0]*x + reg[i][1]*y + reg[i][2]*z;
		if(s >= reg[i][3]) v.pb(1);
		else v.pb(0);
	}
	ans[v]++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> m >> n;
	for(int i=0;i<m;++i) cin >> reg[i][0] >> reg[i][1] >> reg[i][2] >> reg[i][3];
	for(int i=0;i<n;++i){
		cin >> pl[i][0] >> pl[i][1] >> pl[i][2];
		gen_orbit(pl[i][0], pl[i][1], pl[i][2]);
	}

	for(auto it=ans.begin();it!=ans.end();++it){
		r = max(r, it->second);
	}

	cout << r << endl;

	return 0;
}

