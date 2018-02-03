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
#define _ << ",  " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int nk[N], cont;
vi od, ev, ans;
bool imp = false;

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;++i){
		int u;
		cin >> u;
		(u%2) ? od.pb(u) : ev.pb(u);
	}
	sort(od.begin(), od.end());
	sort(ev.begin(), ev.end());
//	for(int i=0;i<(int)od.size();++i) cout << od[i] << ' ';
//	cout << endl;
//	for(int i=0;i<(int)ev.size();++i) cout << ev[i] << ' ';
//	cout << endl;
	cout << cont << endl;
	if(!imp){
		for(int i=0;i<n;++i) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}

