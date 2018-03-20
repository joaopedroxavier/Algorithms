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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll pa[N], pb[N];
int main(){
	ios_base::sync_with_stdio(false);
	ll x, a, b, na, nb;
	char c;
	while(1){
		memset(pa, 0, sizeof(pa));
		memset(pb, 0, sizeof(pb));
		ll ans=0;
		cin >> x >> c >> a >> c >> b >> c >> na >> c >> nb;
		if(cin.eof()){
			cout << endl;
			break;
		}
		if(b > a) swap(a,b), swap(na,nb);
		for(int i=0;i<na;++i){
			for(int j=0;j<nb;++j){
				ll soma = min(min(a-pa[i], b-pb[j]), x);
				pa[i]+= soma;
				pb[j]+= soma;
				ans += soma;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

