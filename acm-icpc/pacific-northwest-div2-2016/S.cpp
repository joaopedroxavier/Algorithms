//
//	Problem S - Gravity
//	Pacific Northwest Region Programming Contest
//	Division 2
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e5;
const int INF=0x3f3f3f3f;

string ans[N];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;++i) cin >> ans[i];
	for(int k=0;k<n;++k){
		for(int i=0;i<n-1;++i){
			for(int j=0;j<m;++j){
				if(ans[i][j] == 'o' and ans[i+1][j] == '.') ans[i][j] = '.', ans[i+1][j] = 'o';
			}
		}
	}
	for(int i=0;i<n;++i) cout << ans[i] << endl;
}

