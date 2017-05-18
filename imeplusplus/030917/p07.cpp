//
//	P7 - Edit distance
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/EDIST/
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
	int t;
	string s, a, b;
	cin >> t;
	getline(cin,s);
	for(int k=0;k<t;++k){
		memset(l,0,sizeof(l));
		getline(cin, a);
		getline(cin, b);
		for(unsigned i=0;i<=a.size();++i){
			for(unsigned j=0;j<=b.size();++j){
				if(i==0) l[i][j] = j;
				else if(j==0) l[i][j] = i;
				else if(a[i-1]==b[j-1]) l[i][j] = l[i-1][j-1];
				else l[i][j] = min(min(l[i-1][j], l[i][j-1]), l[i-1][j-1])+1;
			}
		}
		cout << l[a.size()][b.size()] << endl;
	}
}

