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

bool check(ll p){
	if(p == 0) return true;
	if (p == 1) return false;
	for(ll i=2;i*i<=p;++i) if(p%i == 0) return false;
	return true;
}

vector<ll> ans;
ll n;

bool ver(ll p){
	if(check(p) and check(n-p)){
		ans.pb(p);
		if(n-p != 0) ans.pb(n-p);
		return true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll aux = n;
	while(n){
		if(check(n)){
			ans.pb(n), n = aux-n;
			break;
		}
		else n--;
	}
	for(int i=2;i<=n;++i){
		if(ver(i))
			break;
	}
	cout << ans.size() << endl;
	for(int i : ans) cout << i << ' ';
	cout << endl;
	return 0;
}

