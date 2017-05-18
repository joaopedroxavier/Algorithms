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
const int N=5e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll nprimo[N], ultimodiv[N], dp[N], sum[N];

int main(){
	
	for(ll i=2;i*i<N;++i){
		if(!nprimo[i]){
			for(ll j=i*i;j<N;j+=i)	nprimo[j] = 1, ultimodiv[j] = i;
		}
	}
	
	dp[1] = 1;
	for(int i=2;i<N;++i){
		if(!nprimo[i]) dp[i] = 1;
		else dp[i] = dp[i/ultimodiv[i]] + 1;
	}

	for(int i=2;i<N;++i) sum[i] = sum[i-1] + dp[i];

	int t;
	scanf("%d", &t);
	for(int i=0;i<t;++i){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", sum[a]-sum[b]);
	}

	return 0;
}

