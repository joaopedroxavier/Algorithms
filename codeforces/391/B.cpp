//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int sieve[N], group[N];
vi divisors[N];
set<int> primes;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, ans=0;
	bool only_1 = true;
	cin >> n;

	for(int i=2;i<=N;++i){
		for(int j=2*i;j<=N;j+=i){
			sieve[j] = 1;
			if(!sieve[i])	divisors[j].pb(i);
		}
	}

	for(int i=2;i<=N;++i) if(!sieve[i]) divisors[i].pb(i), primes.insert(i);

	for(int i=0;i<n;++i){
		int u;
		cin >> u;
		if(u != 1) only_1 = false;
		for(int k : divisors[u])	group[k]++;
	}

	for(auto it=primes.begin(); it!=primes.end(); ++it) ans = max(ans, group[*it]);

	cout << ((only_1) ? 1 : ans) << endl;
	return 0;
}

