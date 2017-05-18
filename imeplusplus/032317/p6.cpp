//
//	(Promotion)
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/PRO/
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

multiset<int> m;
int ma, mi;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	ll ans=0;
	cin >> t;
	for(int i=0;i<t;++i){
		int n;
		cin >> n;
		for(int j=0;j<n;++j){
			int u;
			cin >> u;
			m.insert(u);
		}
		ma = *(prev(m.end())), mi = *(m.begin());
		ans += ma - mi;
		m.erase(prev(m.end()));
		m.erase(m.begin());
	}
	cout << ans << endl;
	return 0;
}
