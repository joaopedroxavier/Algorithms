//
//	P5 - Dividing Coins
//	Judge: UVa
//	source: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=503
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

const int INF=1e5;
const int M=1e3;

map<int,int> l[M];
int v[M];
int main(){
	int n, m, mn = INF;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> m;
		mn = INF;
		for(int j=0;j<=m;++j) l[j].clear();
		for(int j=1;j<=m;++j) cin >> v[j];
		l[0][0] = 1;
		for(int j=0;j<m;++j){
			for(auto it=l[j].begin();it!=l[j].end();++it){
				l[j+1][it->first+v[j+1]] = 1;
				l[j+1][it->first-v[j+1]] = 1;
			}
		}
		for(auto it=l[m].begin();it!=l[m].end();++it){
			mn = min(mn,abs(it->first));
		}
		cout << mn << endl;
	}
}

