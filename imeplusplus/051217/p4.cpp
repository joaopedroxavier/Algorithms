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
const int N=3e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int sieve[N], dp[N];
vi divs[N];

int main(){
	ios_base::sync_with_stdio(false);

	for(int i=2;i<N;++i){
		if(!sieve[i]) for(int j=2*i;j<N;j+=i) sieve[j] = 1, divs[j].pb(i);
	}

	int n, ans=0;
	cin >> n;
	for(int i=2;i<=n;++i) if(divs[i].size() == 2) ans++;

	cout << ans << endl;
	return 0;
}

