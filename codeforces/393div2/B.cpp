//
// B - Frodo and Pillows
// CodeForces Round #393 Div.2
// Source: http://codeforces.com/contest/760
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

ll sumap(ll p, ll n){
	ll first=p, last=max(p-n+1, (ll)1), qtd=((last==1) ? p : n);
	return (first+last)*qtd/2;
}

bool verify(ll n, ll m, ll k, ll p){
	ll sum = p + sumap(p-1, k-1) + sumap(p-1, n-k);
	return sum <= m;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	
	m = m-n;
	ll l=0, r=m;
	while(l < r){
		ll mid = (l+r+1)/2;
		if(verify(n, m, k, mid)) l=mid;
		else r=mid-1;
	}

	cout << l+1 << endl;

	return 0;
}

