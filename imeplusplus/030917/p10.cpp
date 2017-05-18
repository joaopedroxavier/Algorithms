//
//	P10 - Wachovia Bank
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/WACHOVIA/
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

ll sack[N][N], w[N], b[N];
int main(){
	int t, n, k;
	cin >> t;
	for(int i=0;i<t;++i){
		cin >> k >> n;
		for(int j=1;j<=n;++j){
			w[j] = 0;
			b[j] = 0;
			cin >> w[j] >> b[j];
		}
		for(int j=0;j<=n;++j){
			for(int p=0;p<=k;++p){
				if(j==0 or p==0) sack[j][p] = 0;
				else{
					if(w[j]<=p)
						sack[j][p] = max(b[j]+sack[j-1][p-w[j]],sack[j-1][p]);
					else sack[j][p] = sack[j-1][p];
				}
			}
		}
		cout << "Hey stupid robber, you can get " << sack[n][k] << "." << endl;
	}
	return 0;
}
