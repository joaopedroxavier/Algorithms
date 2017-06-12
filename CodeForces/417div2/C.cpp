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

vector<ll> souv;

int main(){
	ios_base::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	for(int i=1;i<=n;++i){
		ll u;
		cin >> u;
		souv.pb(u);
	}

	ll l=1, r=n, ans=0;
	while(l<=r){
		ll m = (l+r)/2, sum=0;
		vector<ll> aux = souv;

		for(int i=0;i<n;++i) aux[i] += (i+1)*m;
		sort(aux.begin(), aux.end());

		for(int i=0;i<m;++i)	sum += aux[i];
		if(sum <= s) l=m+1, ans=sum;
		else r=m-1;
	}

	cout << l-1 _ ans << endl;

	return 0;
}

