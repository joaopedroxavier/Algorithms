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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int sieve[N];

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, ans=0;
	cin >> n;

	for(int i=2;i<=n;++i){
		if(!sieve[i]){
			int p = i;
			while(p <= n) ans++, p*=i;
			for(int j=2*i;j<=n;j+=i) sieve[j] = 1;
		}
	}
	
	cout << ans << endl;

	for(int i=2;i<=n;++i) if(!sieve[i]){
		int p = i;
		while(p <= n){
			cout << p << ' ';
			p*=i;
		}
	}
	cout << endl;
	return 0;
}
