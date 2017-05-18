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

ll ans;
void euclides(ll a, ll b){ 
	if(b == 0) return;
	ans+=a/b;
	euclides(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;
	if(a < b) swap(a,b);
	euclides(a,b);
	cout << ans << endl;	
	return 0;
}

