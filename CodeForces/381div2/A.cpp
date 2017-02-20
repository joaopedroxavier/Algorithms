//
//	(A - Alyona and copybooks)
//	Codeforces Round #381 Div.2
//	source: http://codeforces.com/contest/740/problem/A
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

int main(){
	ll n, a, b, c;
	scanf("%lli %lli %lli %lli", &n, &a, &b, &c);
	if(n%4==0) printf("0\n");
	else if(n%4==1) printf("%lli\n", min(min(3*a,(a+b)),min(c,(2*b+c))));
	else if(n%4==2) printf("%lli\n", min(min(a,c)*2,b));
	else printf("%lli\n", min(a,min(3*c,(b+c))));
	return 0;
}

