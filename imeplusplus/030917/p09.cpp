//
//	P9 - FOODIE
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/FOODIE/
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

ll sack[N][N], w[N];
int main(){
	int t, n, k, aux, aux2;
	cin >> t;
	for(int i=0;i<t;++i){
		cin >> n >> k;
		for(int j=1;j<=n;++j){
			cin >> aux;
			w[j]=0;
			for(int p=1;p<=aux;++p){
				cin >> aux2;
				w[j]+=aux2;
			}
		}
		for(int j=0;j<=n;++j){
			for(int p=0;p<=k;++p){
				if(j==0 or p==0) sack[j][p] = 0;
				else{
					if(w[j]<=p)
						sack[j][p] = max(w[j]+sack[j-1][p-w[j]],sack[j-1][p]);
					else sack[j][p] = sack[j-1][p];
				}
			}
		}
		cout << sack[n][k] << endl;
	}
	return 0;
}
