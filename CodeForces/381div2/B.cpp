//
// 	(B - Alyona and flowers)
//	Codeforces Round #381 Div.2
//	source: http://codeforces.com/contest/740/problem/B
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e3;

int main(){
	int n, m, mood[N], p1[N], p2[N], happ[N], ans=0;
	scanf("%d %d", &n, &m);
	memset(happ,0,m);
	for(int i=1;i<=n;++i) scanf("%d", &mood[i]);
	for(int i=0;i<m;++i)	scanf("%d %d", &p1[i], &p2[i]);
	for(int i=0;i<m;++i){
		for(int j=p1[i];j<=p2[i];++j) (happ[i]+=mood[j]);
		if(happ[i]>=0) ans+=happ[i];
	}
	printf("%d\n", ans);
	return 0;
}

