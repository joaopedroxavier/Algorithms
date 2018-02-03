//
//	(D - Taxes)
//	CodeForces Round #382 Div.2
//	source: http://codeforces.com/contest/735/problem/D
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
	ll n, ok=0, ok2=0;
	cin >> n;
	for(int i=2;i*i<=n;++i){
		if(n%i==0) ok=1;
		else if((n-2)%i==0) ok2=1;
	}
	if(!ok) cout << "1" << endl;
	else if(!ok2) cout << "2" << endl;
	else if(n%2==0) cout << "2" << endl;
	else cout << "3" << endl;
	return 0;
}

