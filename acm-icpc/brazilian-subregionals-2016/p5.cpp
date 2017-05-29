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
const int N=1e6+5;
const ll MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

int n;
ll s[100], snp[N], ansmi[N], ansma[N], anssum, f[20];

ll red(ll h, int mask){
	ll p=1, sum=0;
	for(;h;h>>=4){
		ll r=h%16;
		if(mask&(1<<r)) continue;
		else sum+=r*p, p*=16;
	}
	return sum;
}

int main(){
	scanf("%x", &n);
	f[0] = 1;
	for(int i=1;i<20;++i) f[i] = (f[i-1]*i) % MOD;
	memset(ansmi, 63, sizeof(ansmi));

	ansmi[0] = 0;

	for(int i=0;i<n;++i) scanf("%llx ", &s[i]);

	for(int i=1;i<(1<<16);++i){
		for(int j=0;j<n;++j){
			snp[i] += red(s[j], i);
		}
		ll q = __builtin_popcount(i);
		q = (f[q]*f[16-q]) % MOD;
		anssum = (anssum + ((snp[i] % MOD)*q) % MOD) % MOD;
	}

	for(int i=1;i<(1<<16);++i){
		for(int j=0;j<16;++j) if(i&(1<<j)){
			ansmi[i] = min(ansmi[i], ansmi[i-(1<<j)] + snp[i]);
			ansma[i] = max(ansma[i], ansma[i-(1<<j)] + snp[i]);
		}
	}

	printf("%llx %llx %llx\n", ansmi[(1<<16)-1], ansma[(1<<16)-1], anssum%MOD);
	return 0;
}

