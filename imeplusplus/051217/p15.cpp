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

ll p, ans;

ll fastexp(ll n, ll e){
	ll ans = 1;
	while(e){
		if(e%2 == 1) ans = ans*n % p;
		n = n*n % p;
		e/=2;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> p;
	for(ll i=1;i<p;++i){
		bool primitive = true;
		for(ll j=1;j<p-1;++j) if(fastexp(i, j)%p == 1) primitive = false;
		if(primitive) ans++;
	}
	cout << ans << endl;
	return 0;
}

