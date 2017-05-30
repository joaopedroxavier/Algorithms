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
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=2e6+5;
const int INF=0x3f3f3f3f;

int n;
int m[N], w[N];
ll f[N], ma;

int main(){
	ios::sync_with_stdio(false);

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
					int pos;
					scanf("%d", &pos);
					scanf("%lld%d", &f[pos], &w[pos]);
	}
	for(int i=1e6; i>=0; i--) {
					f[i] = f[i]+f[i+w[i]];
					f[i] = max(f[i], f[i+1]);
					ma = max(ma, f[i]);
	}
	
	printf("%lld\n", ma);
	return 0;
	
}

