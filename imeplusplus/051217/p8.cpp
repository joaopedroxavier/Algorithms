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

vector<ll> ans;

int main(){
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll last;
	for(ll i=1;i*i<=n;++i) if(n%i == 0) ans.pb(i), last=i;
	if(last*last == n) last--;
	for(ll i=last;i>0;--i) if(n%i == 0) ans.pb(n/i);
	cout << (((int)ans.size() < k) ? -1 : ans[k-1]) << endl;
	return 0;
}

