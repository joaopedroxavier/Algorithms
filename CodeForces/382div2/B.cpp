//
// (B - Urbanization)
//	CodeForces Round #382 Div.2
//	source: http://codeforces.com/contest/735/problem/B
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

const int N=1e6;

double a[N];
int main(){
	int n;
	double n1, n2, m, sum1=0, sum2=0, ans;
	cin >> n >> n1 >> n2;
	for(int i=0;i<n;++i) cin >> a[i];
	sort(a,a+n);
	m = min(n1,n2);
	for(int i=1;i<=n1+n2;++i){
		if(i>m) sum2 += a[n-i];
		else sum1+=a[n-i];
	}
	sum1 = sum1/m;
	sum2 = sum2/(n1+n2-m);
	ans = sum1+sum2;
	printf("%.6lf\n", ans);
	return 0;
}

