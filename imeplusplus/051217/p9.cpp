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

int main(){
	ios_base::sync_with_stdio(false);
	ll n, primo=1, m2primo=1;
	cin >> n;
	for(ll i=2;i*i<=n;++i){
		if(n%i==0) primo=0;
		else if(n > 2 and ((n-2)%i) == 0) m2primo=0;
	}
	if(primo) cout << 1 << endl;
	else if(m2primo) cout << 2 << endl;
	else if(n%2 == 0) cout << 2 << endl;
	else cout << 3 << endl;
	return 0;
}

