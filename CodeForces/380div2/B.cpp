//
//	(B - Spotlights)
//	CodeForces Round #380 Div.2 (Based on Technocup 2017 - Elimination Round 2)
//	source:	http://codeforces.com/contest/738/problem/B
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

const int N=2e3;

int field[N][N], cond[N][N];
int main(){
	int n, m;
	ll sum=0;
	scanf("%d %d ", &n, &m);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) scanf("%d", &field[i][j]);
	//left direction
	for(int k=1;k<=n;k++) (cond[k][0]=0);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) (field[i][j]==0) ? cond[i][j] = max(cond[i][j-1],field[i][j-1]) : (cond[i][j]=1 , sum--);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(cond[i][j]==1) sum++, cond[i][j]=0;
	//right direction
	for(int k=1;k<=n;k++) (cond[k][m+1]=0);
	for(int i=1;i<=n;++i) for(int j=m;j>=1;--j) (field[i][j]==0) ? cond[i][j] = max(cond[i][j+1],field[i][j+1]) : (cond[i][j]=1 , sum--);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(cond[i][j]==1) sum++, cond[i][j]=0;
	//up direction
	for(int k=1;k<=m;k++) (cond[0][k]=0);
	for(int j=1;j<=m;++j) for(int i=1;i<=n;++i) (field[i][j]==0) ? cond[i][j] = max(cond[i-1][j],field[i-1][j]) : (cond[i][j]=1 , sum--);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(cond[i][j]==1) sum++, cond[i][j]=0;
	//down direction
	for(int k=1;k<=m;k++) (cond[n+1][k]=0);
	for(int j=1;j<=m;++j) for(int i=n;i>=1;--i) (field[i][j]==0) ? cond[i][j] = max(cond[i+1][j],field[i+1][j]) : (cond[i][j]=1 , sum--);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(cond[i][j]==1) sum++, cond[i][j]=0;


	printf("%lli\n", sum);
	return 0;
}

