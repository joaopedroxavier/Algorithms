//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string cake[N];
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q=0;q<t;++q){
		for(int i=0;i<N;++i) cake[i].clear();
		int n, m;
		cin >> n >> m;
		for(int i=0;i<n;++i) cin >> cake[i];
		for(int i=0;i<n;++i)	for(int j=1;j<m;++j) if(cake[i][j] == '?') cake[i][j] = cake[i][j-1];
		for(int i=0;i<n;++i)	for(int j=m-2;j>=0;--j) if(cake[i][j] == '?') cake[i][j] = cake[i][j+1];
		for(int j=0;j<m;++j)	for(int i=1;i<n;++i) if(cake[i][j] == '?') cake[i][j] = cake[i-1][j];
		for(int j=0;j<m;++j)	for(int i=n-2;i>=0;--i) if(cake[i][j] == '?') cake[i][j] = cake[i+1][j];
		cout << "Case #" << q+1 << ":" << endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout << cake[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

