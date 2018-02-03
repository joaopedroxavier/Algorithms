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
const int P=29;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll norh[N], revh[N], vis[N], b[N];
map<ll, vi> hshpos;
string s[N];


void gethash(string s, int i){
	ll hash=0, p=1;
	for(char c : s) hash = (hash + (p*(c-'a'))%MOD)%MOD, p*=P;
	norh[i] = hash;
	hshpos[hash].pb(i);
	p=1, hash=0, reverse(s.begin(), s.end());
	for(char c : s) hash = (hash + (p*(c-'a'))%MOD)%MOD, p*=P;
	revh[i] = hash;
}

int main(){
	ios_base::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	for(int i=0;i<k;++i){
		cin >> s[i] >> b[i];
		gethash(s[i], i);
	}

	ll ans=0, ma=0;

	for(auto it=hshpos.begin();it!=hshpos.end();++it) sort((it->second).begin(), (it->second).end(), [](int i, int j){ return b[i] > b[j]; });
	for(auto it=hshpos.begin();it!=hshpos.end();++it) cout << b[(it->second)[0]] << endl;
	for(int i=0;i<k;++i){
		vis[i] = 1;
	}
	cout << ans + ma << endl;
	return 0;
}

