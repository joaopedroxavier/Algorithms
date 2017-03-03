//
//	(C - Tennis Championship)
//	CodeForces Round #382 Div.2
//	source: http://codeforces.com/contest/735/problem/C
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

ll f[N];
int main(){
	ll n;
	int i=1;
	f[1] = 2;
	f[0] = 1;
	cin >> n;
	while(f[i]<=n){
		f[i+1] = f[i] + f[i-1];
		i++;
	}
	cout << i-1 << endl;
	return 0;
}
