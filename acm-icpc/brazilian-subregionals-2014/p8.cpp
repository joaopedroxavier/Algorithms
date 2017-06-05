#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, m, sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<n;++i){
		int good = 1;
		for(int j=0;j<m;++j){
			int g;
			cin >> g;
			if(g == 0) good = 0;
		}
		sum += good;
	}
	cout << sum << endl;
	return 0;
}

