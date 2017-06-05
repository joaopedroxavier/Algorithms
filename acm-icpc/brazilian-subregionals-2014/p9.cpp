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

ll n, e, c, d, q, p, fi;
ll sieve[N];
vector<ll> primes;

map<int, int> factor(int n){
	map<int, int> fact;
	for(int i=0; primes[i]*primes[i] <=n; ++i){
		if(n % primes[i]) continue;
		while(n % primes[i] == 0) fact[primes[i]]++, n/=primes[i];
	}
	if(n > 1) fact[n]++;
	return fact;
}

int phi(int n){
	map<int, int> fact = factor(n);
	for(auto p : fact) n -= n / p.first;
	return n;
}

ll fastexp(ll a, ll ex, ll mod){
	ll ans = 1;
	while(ex) {
		if(ex&1) ans = ans*a % mod;
		a = a*a % mod;
		ex /= 2;
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> e >> c;

	for(int i=2;i*i<=n;++i) if(!(n%i)) q = i, p = n/i;

	for(ll i=2;i<N;++i) if(!sieve[i]){
		primes.pb(i);
		for(ll j=2*i;j<N;j+=i) sieve[j] = 1;
	}

	fi = (p-1)*(q-1);
	d = fastexp(e, phi(fi)-1, fi);

	cout << fastexp(c, d, n) << endl;
	return 0;
}
