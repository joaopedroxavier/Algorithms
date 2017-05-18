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
const int N=1e6+5;
const int MOD=1<<30;
const int INF=0x3f3f3f3f;

int sieve[N], last[N], ndiv[N];
map<int, int> pf[N];
ll ans;

int main(){
	ios_base::sync_with_stdio(false);
	for(int i=0;i<N;++i) last[i] = i, ndiv[i] = 1;
	for(int i=2;i*i<N;++i){
		if(!sieve[i]){
			for(int j=i*i;j<N;j+=i){
				sieve[j] = 1;
				while(last[j]%i == 0) pf[j][i]++, last[j]/=i;
			}
		}
	}
	for(int i=2;i<N;++i) if(last[i] > 1) pf[i][last[i]]++;

	int a, b, c;
	cin >> a >> b >> c;

	for(int i=2;i<N;++i){
		for(auto it=pf[i].begin(); it!=pf[i].end(); ++it){
			ndiv[i]*=((it->second)+1);
		}
	}
	for(int i=1;i<=a;++i) for(int j=1;j<=b;++j) for(int k=1;k<=c;++k) ans = (ans + ndiv[i*j*k] % MOD ) % MOD;
	cout << ans << endl;
	return 0;
}

