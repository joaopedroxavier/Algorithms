//
//	P1 - Fractions Again?!
//	Judge: UVa
//	source: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1917
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

int v[N];

int main(){
	int n, cont;
	while(1){
		cont=0;
		cin >> n;
		if(cin.eof()) break;
		for(int i=n+1;i<=2*n;++i) if((n*i)%(i-n)==0) v[cont] = i, cont++;
		cout << cont << endl;
		for(int i=0;i<cont;++i) cout << "1/" << n << " = " << "1/"<< n*v[i]/(v[i]-n) << " + 1/" << v[i] << endl;
	}
	return 0;
}

