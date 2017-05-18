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

ll maxm(ll a, ll b){ return ((a > b) ? a : b); }

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	if(n == 1) cout << 1 << endl;
	else if(n == 2) cout << 2 << endl;
	else if(n%2 == 1) cout << n*(n-1)*(n-2) << endl;
	else if(n > 6) cout << ((n%3) ? maxm((n-1)*(n-2)*(n-3), n*(n-1)*(n-3)) : (n-1)*(n-2)*(n-3)) << endl;
	else cout << n*(n-1)*(n-2)/2 << endl;
	return 0;
}

