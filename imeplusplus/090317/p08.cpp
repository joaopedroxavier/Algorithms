//
//	P8 - Largest Sum Game
//	Judge: UVa
//	source: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4388
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
	ll n, sum=0, m=0;
	char c;
	while(~scanf("%lld%c", &n, &c)){
		sum+=n;
		if(sum<0) sum = 0;
		m = max(m, sum);
		if(c=='\n'){
			cout << m << endl;
			sum = 0;
			m = 0;
		}
	}	
}

