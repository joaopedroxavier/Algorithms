//
//	P11 - Longest Common Subsequence
//	Judge: UVa
//	source: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1346
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

const int N=1e4;

int l[N][N];
int main(){
	string a, b;
	int cont = 0;
	bool two_times = false;
	while(1){
		cont = 0;
		two_times = false;
		getline(cin, a);
		if(cin.eof()) break;
		getline(cin, b);
		for(unsigned i=0;i<=a.size();++i){
			for(unsigned j=0;j<=b.size();++j){
				if(i==0 or j==0) l[i][j] = 0;
				else if(a[i-1] == b[j-1]) l[i][j] = 1 + l[i-1][j-1];
				else l[i][j] = max(l[i-1][j],l[i][j-1]);
			}
		}
		cout << l[a.size()][b.size()] << endl;
	}
	return 0;
}
